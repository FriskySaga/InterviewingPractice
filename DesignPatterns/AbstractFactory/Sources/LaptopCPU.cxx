// Project includes
#include "LaptopCPU.hpp"

LaptopCPU::LaptopCPU(const std::string& brandName,
                     const std::string& modelName,
                     const uint16_t& generationNumber,
                     const uint16_t& numberOfCores,
                     const float& maxClockSpeedGHz)
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

bool LaptopCPU::operator==(LaptopCPU& rhs) const
{
  return this->getBrand() == rhs.getBrand() &&
         this->getModel() == rhs.getModel() &&
         this->getPlatform() == rhs.getPlatform() &&
         this->getGeneration() == rhs.getGeneration() &&
         this->getNumberOfCores() == rhs.getNumberOfCores() &&
         this->getMaxClockSpeedGHz() == rhs.getMaxClockSpeedGHz();
}

std::string LaptopCPU::getBrand() const
{
  return brandName;
}

std::string LaptopCPU::getModel() const
{
  return modelName;
}

std::string LaptopCPU::getPlatform() const
{
  return platformName;
}

uint16_t LaptopCPU::getGeneration() const
{
  return generationNumber;
}

uint16_t LaptopCPU::getNumberOfCores() const
{
  return numberOfCores;
}

float LaptopCPU::getMaxClockSpeedGHz() const
{
  return maxClockSpeedGHz;
}

