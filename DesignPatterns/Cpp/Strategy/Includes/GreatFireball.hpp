#pragma once

// Project includes
#include "Ninjutsu.hpp"

class GreatFireball : public Ninjutsu
{
public:
  GreatFireball(const std::vector<std::string> handSeals);

  ChakraNature::ChakraNatureEnum getNature() const;
};

