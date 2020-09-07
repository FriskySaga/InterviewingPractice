#pragma once

// Project includes
#include "Component.hpp"

class CPU : public Component
{
public:
  virtual uint16_t getGeneration() const = 0;
  virtual uint16_t getNumberOfCores() const = 0;
  virtual float getMaxClockSpeedGHz() const = 0;
};

