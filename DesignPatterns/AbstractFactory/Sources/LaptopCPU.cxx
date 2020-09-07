// Project includes
#include "LaptopCPU.hpp"

LaptopCPU::LaptopCPU(const std::string brandName,
                     const std::string modelName,
                     const uint16_t generationNumber,
                     const uint16_t numberOfCores,
                     const float maxClockSpeedGHz)
  : brandName(brandName),
    modelName(modelName),
    platformName("Laptop"),
    generationNumber(generationNumber),
    numberOfCores(numberOfCores),
    maxClockSpeedGHz(maxClockSpeedGHz)
{
}

LaptopCPU::~LaptopCPU()
{
}

const bool LaptopCPU::operator==(LaptopCPU* rhs)
{
  return this->getBrand() == rhs->getBrand() &&
         this->getModel() == rhs->getModel() &&
         this->getPlatform() == rhs->getPlatform() &&
         this->getGeneration() == rhs->getGeneration() &&
         this->getNumberOfCores() == rhs->getNumberOfCores() &&
         this->getMaxClockSpeedGHz() == rhs->getMaxClockSpeedGHz();
}

const std::string LaptopCPU::getBrand()
{
  return brandName;
}

const std::string LaptopCPU::getModel()
{
  return modelName;
}

const std::string LaptopCPU::getPlatform()
{
  return platformName;
}

const uint16_t LaptopCPU::getGeneration()
{
  return generationNumber;
}

const uint16_t LaptopCPU::getNumberOfCores()
{
  return numberOfCores;
}

const float LaptopCPU::getMaxClockSpeedGHz()
{
  return maxClockSpeedGHz;
}

