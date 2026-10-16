#include "tower_model/cube.hpp"

namespace tower_model
{

Cube::Cube(std::uint32_t id, double cote)
: Piece(id, {cote, cote, cote})
{
}

std::string Cube::forme() const
{
  return "cube";
}

std::string Cube::couleur() const
{
  return "red";
}

double Cube::volume() const
{
  const double cote = dimensions().longueur;
  return cote * cote * cote;
}

}  // namespace tower_model
