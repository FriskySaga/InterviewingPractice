#pragma once

// Project includes
#include "LaptopCPU.hpp"

class Laptop : public Component
{
public:
  Laptop(const std::string& brandName,
         const std::string& modelName,
         LaptopCPU* cpu);

  virtual ~Laptop();

  // Component attributes
  std::string getBrand() const;
  std::string getModel() const;
  std::string getPlatform() const;

  // Laptop attributes
  LaptopCPU* getCPU();

private:
  // Component attributes
  const std::string brandName;
  const std::string modelName;
  const std::string platformName;

  // Laptop attributes
  LaptopCPU* cpu;
};

