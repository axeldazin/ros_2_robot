"""Verifie le lancement depuis une scene generee, un PNG fourni et une image vide."""

import json
import os
from pathlib import Path
import random
import subprocess
import tempfile

import cv2
import numpy as np


def run_scene(output_dir, image=None, start_controller=True):
    env = os.environ.copy()
    env['ROS_DOMAIN_ID'] = str(random.SystemRandom().randint(120, 160))
    env.pop('ROS_LOCALHOST_ONLY', None)
    env['ROS_AUTOMATIC_DISCOVERY_RANGE'] = 'LOCALHOST'
    command = [
        'ros2', 'launch', 'tower_perception', 'image_simulation.launch.py',
        'once:=true', f'output_dir:={output_dir}',
        f'start_controller:={str(start_controller).lower()}',
    ]
    if image is not None:
        command.append(f'image:={image}')
    result = subprocess.run(command, env=env, capture_output=True, text=True, timeout=30)
    assert result.returncode == 0, result.stdout + result.stderr
    assert (output_dir / 'pieces.json').is_file(), result.stdout + result.stderr
    assert (output_dir / 'pieces.csv').is_file()
    assert (output_dir / 'depth.npy').is_file()
    annotated = cv2.imread(str(output_dir / 'annotated.png'))
    assert annotated is not None
    metadata = json.loads((output_dir / 'scene.json').read_text())
    detections = json.loads((output_dir / 'pieces.json').read_text())
    assert detections['coordinates_are_simulated'] is True
    assert detections['frame_id'] == 'simulation_color_optical_frame'
    return metadata, detections, result.stdout


def main():
    with tempfile.TemporaryDirectory(prefix='tower_image_simulation_test_') as directory:
        root = Path(directory)
        generated_dir = root / 'generated'
        metadata, result, logs = run_scene(generated_dir)
        assert len(result['pieces']) == 3, result
        assert len({piece['id'] for piece in result['pieces']}) == 3
        by_color = {piece['color']: piece for piece in result['pieces']}
        for expected in metadata['expected_pieces']:
            actual = by_color[expected['color']]
            np.testing.assert_allclose(actual['center_px'], expected['center_px'], atol=1.0)
            np.testing.assert_allclose(actual['center_m'], expected['center_m'], atol=0.002)
            np.testing.assert_allclose(actual['dimensions_m'], expected['dimensions_m'], atol=1e-12)
        assert 'Vecteur recu : 3 piece(s)' in logs, logs
        print('OK : scene generee, centres pixels/3D, dimensions et reception controleur.', flush=True)

        # Verifier aussi un chemin de photo contenant des espaces.
        own_image = root / 'mes pieces.png'
        own_image.write_bytes((generated_dir / 'scene.png').read_bytes())
        _, custom, _ = run_scene(root / 'custom', own_image)
        assert len(custom['pieces']) == 3
        for piece in custom['pieces']:
            previous = by_color[piece['color']]
            np.testing.assert_allclose(piece['center_px'], previous['center_px'], atol=1.0)
            assert abs(piece['center_m'][2] - (0.8 + piece['dimensions_m'][2] / 2)) < 1e-6
        print('OK : PNG fourni, profondeur uniforme explicitement simulee.', flush=True)

        blank = root / 'blank.png'
        assert cv2.imwrite(str(blank), np.zeros((640, 960, 3), dtype=np.uint8))
        _, empty, logs = run_scene(root / 'empty', blank)
        assert empty['pieces'] == []
        assert 'Vecteur recu : 0 piece(s)' in logs, logs
        print('OK : image vide, vecteur vide et arret propre des noeuds.', flush=True)

        _, standalone, _ = run_scene(root / 'without_controller', start_controller=False)
        assert len(standalone['pieces']) == 3
        print('OK : simulation sans controleur, aucune attente d\'abonnement inutile.', flush=True)


if __name__ == '__main__':
    main()
