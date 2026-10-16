#include "tower_model/rectangle.hpp"

namespace tower_model
{

Rectangle::Rectangle(std::uint32_t id, double longueur, double largeur, double hauteur)
: Piece(id, {longueur, largeur, hauteur})
{
}

std::string Rectangle::forme() const
{
  return "rectangle";
}

std::string Rectangle::couleur() const
{
  return "blue";
}

double Rectangle::volume() const
{
  const auto & d = dimensions();
  return d.longueur * d.largeur * d.hauteur;
}

}  // namespace tower_model
