#ifndef TOWER_MODEL__RECTANGLE_HPP_
#define TOWER_MODEL__RECTANGLE_HPP_

#include "tower_model/piece.hpp"

namespace tower_model
{

// Ici, Rectangle designe une piece en 3D : un pave rectangulaire.
class Rectangle final : public Piece
{
public:
  Rectangle(std::uint32_t id, double longueur, double largeur, double hauteur);

  std::string forme() const override;
  std::string couleur() const override;
  double volume() const override;
};

}  // namespace tower_model

#endif  // TOWER_MODEL__RECTANGLE_HPP_
