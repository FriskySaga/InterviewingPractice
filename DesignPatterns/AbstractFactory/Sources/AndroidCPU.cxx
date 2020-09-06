// C++ includes
#include <string>

// Project includes
#include "AndroidCPU.hpp"

AndroidCPU::AndroidCPU(std::string brandName,
                       std::string modelName,
                       uint16_t generationNumber,
                       uint16_t numberOfCores,
                       float maxClockSpeedGHz)
  : brandName(brandName),
    modelName(modelName),
    platformName("Android"),
    generationNumber(generationNumber),
    numberOfCores(numberOfCores),
    maxClockSpeedGHz(maxClockSpeedGHz)
{
}

AndroidCPU::~AndroidCPU()
{
}

bool AndroidCPU::operator==(AndroidCPU& rhs)
{
  return this->getBrand() == rhs.getBrand() &&
         this->getModel() == rhs.getModel() &&
         this->getPlatform() == rhs.getPlatform() &&
         this->getGeneration() == rhs.getGeneration() &&
         this->getNumberOfCores() == rhs.getNumberOfCores() &&
         this->getMaxClockSpeedGHz() == rhs.getMaxClockSpeedGHz();
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

const uint16_t AndroidCPU::getGeneration()
{
  return generationNumber;
}

const uint16_t AndroidCPU::getNumberOfCores()
{
  return numberOfCores;
}

const float AndroidCPU::getMaxClockSpeedGHz()
{
  return maxClockSpeedGHz;
}

