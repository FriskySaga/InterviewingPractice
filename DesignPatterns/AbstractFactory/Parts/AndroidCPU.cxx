// C++ includes
#include <string>

// Project includes
#include "AndroidCPU.hpp"

AndroidCPU::AndroidCPU(std::string brandName,
                       std::string modelName,
                       int numberOfCores,
                       float clockSpeedGHz)
  : brandName(brandName),
    modelName(modelName),
    platformName("Android"),
    numberOfCores(numberOfCores),
    clockSpeedGHz(clockSpeedGHz)
{
}

AndroidCPU::~AndroidCPU()
{
}

const std::string AndroidCPU::getBrand()
{
  return brandName;
}

const std::string AndroidCPU::getModel()
{
  return modelName;
}

const std::string AndroidCPU::getPlatform()
{
  return platformName;
}

const int AndroidCPU::getNumberOfCores()
{
  return numberOfCores;
}

const float AndroidCPU::getClockSpeedGHz()
{
  return clockSpeedGHz;
}

