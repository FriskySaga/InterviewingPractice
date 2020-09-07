// Project includes
#include "Android.hpp"

Android::Android(std::string brandName,
                 std::string modelName,
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

const std::string Android::getBrand()
{
  return brandName;
}

const std::string Android::getModel()
{
  return modelName;
}

const std::string Android::getPlatform()
{
  return platformName;
}

AndroidCPU* Android::getCPU()
{
  return cpu;
}

