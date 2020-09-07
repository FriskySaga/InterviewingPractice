// Project includes
#include "Laptop.hpp"

Laptop::Laptop(const std::string& brandName,
               const std::string& modelName,
               LaptopCPU* cpu)
  : brandName(brandName),
    modelName(modelName),
    platformName("Laptop"),
    cpu(cpu)
{
}

Laptop::~Laptop()
{
  delete cpu;
}

std::string Laptop::getBrand() const
{
  return brandName;
}

std::string Laptop::getModel() const
{
  return modelName;
}

std::string Laptop::getPlatform() const
{
  return platformName;
}

LaptopCPU* Laptop::getCPU()
{
  return cpu;
}

