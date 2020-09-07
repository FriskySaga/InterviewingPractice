#pragma once

// Project includes
#include "CPU.hpp"

class LaptopCPU : public CPU
{
friend class Laptop;
friend class CPUFactory;

private:
  LaptopCPU(const std::string& brandName,
            const std::string& modelName,
            const uint16_t& generationNumber,
            const uint16_t& numberOfCores,
            const float& maxClockSpeedGHz);

public:
  virtual ~LaptopCPU();

  bool operator==(LaptopCPU& rhs) const;

  // Component attributes
  std::string getBrand() const;
  std::string getModel() const;
  std::string getPlatform() const;

  // CPU attributes
  uint16_t getGeneration() const;
  uint16_t getNumberOfCores() const;
  float getMaxClockSpeedGHz() const;

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

