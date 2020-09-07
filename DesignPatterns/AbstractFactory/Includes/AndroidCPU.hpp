#pragma once

// Project includes
#include "CPU.hpp"

class AndroidCPU : public CPU
{
public:
  AndroidCPU(const std::string brandName,
             const std::string modelName,
             const uint16_t generationNumber,
             const uint16_t numberOfCores,
             const float maxClockSpeedGHz);

  virtual ~AndroidCPU();

  const bool operator==(AndroidCPU* rhs);

  // Component attributes
  const std::string getBrand();
  const std::string getModel();
  const std::string getPlatform();

  // CPU attributes
  const uint16_t getGeneration();
  const uint16_t getNumberOfCores();
  const float getMaxClockSpeedGHz();

private:
  // Component attributes
  const std::string brandName;
  const std::string modelName;
  const std::string platformName;

  // CPU attributes
  const uint16_t generationNumber;
  const uint16_t numberOfCores;
  const float maxClockSpeedGHz;
};

