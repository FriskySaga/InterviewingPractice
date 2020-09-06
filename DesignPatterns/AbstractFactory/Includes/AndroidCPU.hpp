#pragma once

// Project includes
#include "CPU.hpp"

class AndroidCPU : public CPU
{
public:
  AndroidCPU(std::string brandName,
             std::string modelName,
             uint16_t generationNumber,
             uint16_t numberOfCores,
             float maxClockSpeedGHz);

  virtual ~AndroidCPU();

  bool operator==(AndroidCPU& rhs);

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
  std::string brandName;
  std::string modelName;
  std::string platformName;

  // CPU attributes
  uint16_t generationNumber;
  uint16_t numberOfCores;
  float maxClockSpeedGHz;
};

