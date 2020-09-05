// Project includes
#include "Laptop.hpp"
// #include "LaptopCPU.hpp"

Laptop::Laptop(std::string brandName,
               std::string modelName,
               CPU* cpu)
  : brandName(brandName),
    modelName(modelName)
{
  // this->cpu = dynamic_cast<LaptopCPU*>(cpu);
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

const CPU* Laptop::getCPU()
{
  return NULL;
}

