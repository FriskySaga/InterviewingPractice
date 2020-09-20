// Project includes
#include "FourPillarHouse.hpp"

FourPillarHouse::FourPillarHouse(const std::vector<std::string> handSeals)
  : Ninjutsu(handSeals)
{
}

ChakraNature::ChakraNatureEnum FourPillarHouse::getNature() const
{
  return ChakraNature::ChakraNatureEnum::WOOD;
}

