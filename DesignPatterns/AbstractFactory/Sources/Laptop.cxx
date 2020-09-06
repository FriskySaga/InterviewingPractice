// Project includes
#include "Laptop.hpp"

Laptop::Laptop(std::string brandName,
               std::string modelName,
               LaptopCPU& cpu)
  : brandName(brandName),
    modelName(modelName),
    cpu(cpu)
{
}

Laptop::~Laptop()
{
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

LaptopCPU& Laptop::getCPU()
{
  return cpu;
}

