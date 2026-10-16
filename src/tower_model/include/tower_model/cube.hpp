#ifndef TOWER_MODEL__CUBE_HPP_
#define TOWER_MODEL__CUBE_HPP_

#include "tower_model/piece.hpp"

namespace tower_model
{

class Cube final : public Piece
{
public:
  Cube(std::uint32_t id, double cote);

  std::string forme() const override;
  std::string couleur() const override;
  double volume() const override;
};

}  // namespace tower_model

#endif  // TOWER_MODEL__CUBE_HPP_
