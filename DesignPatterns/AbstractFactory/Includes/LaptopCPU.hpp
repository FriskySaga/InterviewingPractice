#pragma once

// Project includes
#include "CPU.hpp"

class LaptopCPU : public CPU
{
public:
  LaptopCPU(const std::string brandName,
            const std::string modelName,
            const uint16_t generationNumber,
            const uint16_t numberOfCores,
            const float maxClockSpeedGHz);

  virtual ~LaptopCPU();

  const bool operator==(LaptopCPU* rhs);

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

