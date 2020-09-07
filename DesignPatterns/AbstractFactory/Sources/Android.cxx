// Project includes
#include "Android.hpp"

Android::Android(const std::string brandName,
                 const std::string modelName,
                 AndroidCPU* cpu)
  : brandName(brandName),
    modelName(modelName),
    platformName("Android"),
    cpu(cpu)
{
}

Android::~Android()
{
  delete cpu;
}

std::string Android::getBrand() const
{
  return brandName;
}

std::string Android::getModel() const
{
  return modelName;
}

std::string Android::getPlatform() const
{
  return platformName;
}

AndroidCPU* Android::getCPU() const
{
  return cpu;
}

