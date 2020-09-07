#pragma once

// Project includes
#include "AndroidCPU.hpp"
#include "LaptopCPU.hpp"

class CPUFactory
{
public:
  AndroidCPU* makeAndroidCPU(const std::string& brandName,
                             const std::string& modelName,
                             const uint16_t& generationNumber,
                             const uint16_t& numberOfCores,
                             const float& maxClockSpeedGHz);

  LaptopCPU* makeLaptopCPU(const std::string& brandName,
                           const std::string& modelName,
                           const uint16_t& generationNumber,
                           const uint16_t& numberOfCores,
                           const float& maxClockSpeedGHz);
};

