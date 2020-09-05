#pragma once

// Project includes
#include "Component.hpp"

class CPU : Component
{
public:
  virtual const uint16_t getGeneration() = 0;
  virtual const uint16_t getNumberOfCores() = 0;
  virtual const float getMaxClockSpeedGHz() = 0;
};

