#pragma once

// Project includes
#include "AndroidCPU.hpp"

class Android : public Component
{
friend class ComputerFactory;

private:
  Android(const std::string& brandName,
          const std::string& modelName,
          AndroidCPU* cpu);

public:
  virtual ~Android();

  // Component attributes
  std::string getBrand() const;
  std::string getModel() const;
  std::string getPlatform() const;

  // Android attributes
  AndroidCPU* getCPU() const;

private:
  // Component attributes
  const std::string brandName;
  const std::string modelName;
  const std::string platformName;

  // Android attributes
  AndroidCPU* cpu;
};

