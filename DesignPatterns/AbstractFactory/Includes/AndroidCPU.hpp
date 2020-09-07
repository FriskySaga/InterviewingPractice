#pragma once

// Project includes
#include "CPU.hpp"

class AndroidCPU : public CPU
{
friend class Android;
friend class CPUFactory;

private:
  AndroidCPU(const std::string& brandName,
             const std::string& modelName,
             const uint16_t& generationNumber,
             const uint16_t& numberOfCores,
             const float& maxClockSpeedGHz);

public:
  virtual ~AndroidCPU();

  bool operator==(AndroidCPU& rhs) const;

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

