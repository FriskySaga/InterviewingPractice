#pragma once

// Project includes
#include "Computer.hpp"
class LaptopCPU;

class Laptop : Computer
{
public:
  Laptop(std::string brandName,
         std::string modelName,
         CPU* cpu);

  virtual ~Laptop();

  const std::string getBrand();
  const std::string getModel();
  const std::string getPlatform();
  const CPU* getCPU();

private:
  // Component attributes
  std::string brandName;
  std::string modelName;
  std::string platformName;

  // Computer attributes
  LaptopCPU* cpu;
};

