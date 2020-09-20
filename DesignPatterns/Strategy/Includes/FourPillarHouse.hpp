#pragma once

// Project includes
#include "Ninjutsu.hpp"

class FourPillarHouse : public Ninjutsu
{
public:
  FourPillarHouse(const std::vector<std::string> handSeals);

  ChakraNature::ChakraNatureEnum getNature() const;
};

