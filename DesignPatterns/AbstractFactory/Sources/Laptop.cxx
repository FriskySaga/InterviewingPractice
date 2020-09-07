// Project includes
#include "Laptop.hpp"

Laptop::Laptop(const std::string brandName,
               const std::string modelName,
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

const std::string Laptop::getBrand()
{
  return brandName;
}

const std::string Laptop::getModel()
{
  return modelName;
}

const std::string Laptop::getPlatform()
{
  return platformName;
}

LaptopCPU* Laptop::getCPU()
{
  return cpu;
}

