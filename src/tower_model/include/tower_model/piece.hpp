#ifndef TOWER_MODEL__PIECE_HPP_
#define TOWER_MODEL__PIECE_HPP_

#include <cstdint>
#include <string>

namespace tower_model
{

// Toutes les dimensions sont en metres, selon les axes locaux de la piece.
struct Dimensions
{
  double longueur;  // x ; diametre pour un cylindre
  double largeur;   // y ; diametre pour un cylindre
  double hauteur;   // z ; axe du cylindre
};

// Classe mere abstraite : les trois formes partagent un identifiant et des dimensions.
class Piece
{
public:
  // Necessaire pour detruire correctement une classe fille via un pointeur Piece.
  virtual ~Piece() = default;

  std::uint32_t id() const;
  const Dimensions & dimensions() const;

  // Chaque classe fille fournit sa forme, sa couleur fixe et son volume en m3.
  virtual std::string forme() const = 0;
  virtual std::string couleur() const = 0;
  virtual double volume() const = 0;

protected:
  // Seules les classes filles appellent ce constructeur.
  Piece(std::uint32_t id, Dimensions dimensions);

private:
  std::uint32_t id_;
  Dimensions dimensions_;
};

}  // namespace tower_model

#endif  // TOWER_MODEL__PIECE_HPP_
