// Project includes
#include "Ninjutsu.hpp"

Ninjutsu::Ninjutsu(const std::vector<std::string> handSeals)
  : handSeals(handSeals)
{
}

std::vector<std::string> Ninjutsu::getHandSeals() const
{
  return handSeals;
}

void Ninjutsu::changeHandSeals(const std::vector<std::string> handSeals)
{
  this->handSeals = handSeals;
}

