// Project includes
#include "AndroidCPU.hpp"

AndroidCPU::AndroidCPU(const std::string& brandName,
                       const std::string& modelName,
                       const uint16_t& generationNumber,
                       const uint16_t& numberOfCores,
                       const float& maxClockSpeedGHz)
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

bool AndroidCPU::operator==(AndroidCPU* rhs) const
{
  return this->getBrand() == rhs->getBrand() &&
         this->getModel() == rhs->getModel() &&
         this->getPlatform() == rhs->getPlatform() &&
         this->getGeneration() == rhs->getGeneration() &&
         this->getNumberOfCores() == rhs->getNumberOfCores() &&
         this->getMaxClockSpeedGHz() == rhs->getMaxClockSpeedGHz();
}

std::string AndroidCPU::getBrand() const
{
  return brandName;
}

std::string AndroidCPU::getModel() const
{
  return modelName;
}

std::string AndroidCPU::getPlatform() const
{
  return platformName;
}

uint16_t AndroidCPU::getGeneration() const
{
  return generationNumber;
}

uint16_t AndroidCPU::getNumberOfCores() const
{
  return numberOfCores;
}

float AndroidCPU::getMaxClockSpeedGHz() const
{
  return maxClockSpeedGHz;
}

