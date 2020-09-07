// Project includes
#include "CPUFactory.hpp"

AndroidCPU* CPUFactory::makeAndroidCPU(std::string brandName,
                                       std::string modelName,
                                       uint16_t generationNumber,
                                       uint16_t numberOfCores,
                                       float maxClockSpeedGHz)
{
  return new AndroidCPU(brandName,
                        modelName,
                        generationNumber,
                        numberOfCores,
                        maxClockSpeedGHz);
}

LaptopCPU* CPUFactory::makeLaptopCPU(std::string brandName,
                                     std::string modelName,
                                     uint16_t generationNumber,
                                     uint16_t numberOfCores,
                                     float maxClockSpeedGHz)
{
  return new LaptopCPU(brandName,
                       modelName,
                       generationNumber,
                       numberOfCores,
                       maxClockSpeedGHz);
}

