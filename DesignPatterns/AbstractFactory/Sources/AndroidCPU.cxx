// Project includes
#include "AndroidCPU.hpp"

AndroidCPU::AndroidCPU(const std::string brandName,
                       const std::string modelName,
                       const uint16_t generationNumber,
                       const uint16_t numberOfCores,
                       const float maxClockSpeedGHz)
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

const bool AndroidCPU::operator==(AndroidCPU* rhs)
{
  return this->getBrand() == rhs->getBrand() &&
         this->getModel() == rhs->getModel() &&
         this->getPlatform() == rhs->getPlatform() &&
         this->getGeneration() == rhs->getGeneration() &&
         this->getNumberOfCores() == rhs->getNumberOfCores() &&
         this->getMaxClockSpeedGHz() == rhs->getMaxClockSpeedGHz();
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

