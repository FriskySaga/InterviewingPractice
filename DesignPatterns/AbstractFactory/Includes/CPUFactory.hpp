#pragma once

// Project includes
#include "AndroidCPU.hpp"
#include "LaptopCPU.hpp"

class CPUFactory
{
public:
  AndroidCPU* makeAndroidCPU(std::string brandName,
                             std::string modelName,
                             uint16_t generationNumber,
                             uint16_t numberOfCores,
                             float maxClockSpeedGHz);

  LaptopCPU* makeLaptopCPU(std::string brandName,
                           std::string modelName,
                           uint16_t generationNumber,
                           uint16_t numberOfCores,
                           float maxClockSpeedGHz);
};

