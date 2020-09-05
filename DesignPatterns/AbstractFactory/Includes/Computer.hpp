#pragma once

// Project includes
#include "Component.hpp"
class CPU;

class Computer : Component
{
public:
  virtual const CPU* getCPU() = 0;
};

