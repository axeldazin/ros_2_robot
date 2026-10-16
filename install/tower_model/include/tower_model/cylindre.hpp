#ifndef TOWER_MODEL__CYLINDRE_HPP_
#define TOWER_MODEL__CYLINDRE_HPP_

#include "tower_model/piece.hpp"

namespace tower_model
{

class Cylindre final : public Piece
{
public:
  Cylindre(std::uint32_t id, double rayon, double hauteur);

  double rayon() const;
  std::string forme() const override;
  std::string couleur() const override;
  double volume() const override;
};

}  // namespace tower_model

#endif  // TOWER_MODEL__CYLINDRE_HPP_
