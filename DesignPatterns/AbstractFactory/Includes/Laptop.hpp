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

  // Component attributes
  const std::string getBrand();
  const std::string getModel();
  const std::string getPlatform();

  // Laptop attributes
  LaptopCPU& getCPU();

private:
  // Component attributes
  std::string brandName;
  std::string modelName;
  std::string platformName;

  // Laptop attributes
  LaptopCPU& cpu;
};

