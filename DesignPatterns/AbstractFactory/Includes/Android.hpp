#pragma once

// Project includes
#include "AndroidCPU.hpp"

class Android : public Component
{
public:
  Android(std::string brandName,
          std::string modelName,
          AndroidCPU* cpu);

  virtual ~Android();

  // Component attributes
  const std::string getBrand();
  const std::string getModel();
  const std::string getPlatform();

  // Android attributes
  AndroidCPU* getCPU();

private:
  // Component attributes
  std::string brandName;
  std::string modelName;
  std::string platformName;

  // Android attributes
  AndroidCPU* cpu;
};

