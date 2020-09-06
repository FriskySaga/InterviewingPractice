#pragma once

// Project includes
#include "AndroidCPU.hpp"

class Android : public Component
{
public:
  Android(std::string brandName,
          std::string modelName,
          AndroidCPU& cpu);

  virtual ~Android();

  const std::string getBrand();
  const std::string getModel();
  const std::string getPlatform();
  AndroidCPU& getCPU();

private:
  // Component attributes
  std::string brandName;
  std::string modelName;
  std::string platformName;

  // Computer attributes
  AndroidCPU& cpu;
};

