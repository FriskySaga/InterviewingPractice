#pragma once

// Project includes
#include "Android.hpp"
#include "Laptop.hpp"
class CPUFactory;

class ComputerFactory
{
public:
  ComputerFactory();

  virtual ~ComputerFactory();

  Android* makeAndroid(const std::string& androidBrandName,
                       const std::string& androidModelName,
                       const std::string& cpuBrandName,
                       const std::string& cpuModelName,
                       const uint16_t& cpuGenerationNumber,
                       const uint16_t& cpuNumberOfCores,
                       const float& cpuMaxClockSpeedGHz);

  Laptop* makeLaptop(const std::string& laptopBrandName,
                     const std::string& laptopModelName,
                     const std::string& cpuBrandName,
                     const std::string& cpuModelName,
                     const uint16_t& cpuGenerationNumber,
                     const uint16_t& cpuNumberOfCores,
                     const float& cpuMaxClockSpeedGHz);

private:
  CPUFactory* cpuFactory;
};

