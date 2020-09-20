// Project includes
#include "GreatFireball.hpp"

GreatFireball::GreatFireball(const std::vector<std::string> handSeals)
  : Ninjutsu(handSeals)
{
}

ChakraNature::ChakraNatureEnum GreatFireball::getNature() const
{
  return ChakraNature::ChakraNatureEnum::FIRE;
}

