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

  Android* makeAndroid(std::string androidBrandName,
                       std::string androidModelName,
                       std::string cpuBrandName,
                       std::string cpuModelName,
                       uint16_t cpuGenerationNumber,
                       uint16_t cpuNumberOfCores,
                       float cpuMaxClockSpeedGHz);

private:
  CPUFactory* cpuFactory;
};

