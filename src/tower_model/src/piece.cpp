#include "tower_model/piece.hpp"

#include <cmath>
#include <stdexcept>

namespace tower_model
{

Piece::Piece(std::uint32_t id, Dimensions dimensions)
: id_(id), dimensions_(dimensions)
{
  for (double valeur : {dimensions.longueur, dimensions.largeur, dimensions.hauteur}) {
    if (!std::isfinite(valeur) || valeur <= 0.0) {
      throw std::invalid_argument("Une dimension doit etre finie et strictement positive.");
    }
  }
}

std::uint32_t Piece::id() const
{
  return id_;
}

const Dimensions & Piece::dimensions() const
{
  return dimensions_;
}

}  // namespace tower_model
