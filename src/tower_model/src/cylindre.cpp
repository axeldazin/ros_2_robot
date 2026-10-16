#include "tower_model/cylindre.hpp"

namespace tower_model
{

Cylindre::Cylindre(std::uint32_t id, double rayon, double hauteur)
: Piece(id, {2.0 * rayon, 2.0 * rayon, hauteur})
{
}

double Cylindre::rayon() const
{
  return dimensions().longueur / 2.0;
}

std::string Cylindre::forme() const
{
  return "cylindre";
}

std::string Cylindre::couleur() const
{
  return "green";
}

double Cylindre::volume() const
{
  constexpr double pi = 3.14159265358979323846;
  return pi * rayon() * rayon() * dimensions().hauteur;
}

}  // namespace tower_model
