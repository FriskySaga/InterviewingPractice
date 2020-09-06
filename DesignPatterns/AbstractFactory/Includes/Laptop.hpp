#pragma once

// Project includes
#include "LaptopCPU.hpp"

class Laptop : public Component
{
public:
  Laptop(std::string brandName,
         std::string modelName,
         LaptopCPU& cpu);

  virtual ~Laptop();

  const std::string getBrand();
  const std::string getModel();
  const std::string getPlatform();
  LaptopCPU& getCPU();

private:
  // Component attributes
  std::string brandName;
  std::string modelName;
  std::string platformName;

  // Computer attributes
  LaptopCPU& cpu;
};

