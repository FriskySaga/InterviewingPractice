// Project includes
#include "CPUFactory.hpp"

AndroidCPU* CPUFactory::makeAndroidCPU(const std::string brandName,
                                       const std::string modelName,
                                       const uint16_t generationNumber,
                                       const uint16_t numberOfCores,
                                       const float maxClockSpeedGHz)
{
  return new AndroidCPU(brandName,
                        modelName,
                        generationNumber,
                        numberOfCores,
                        maxClockSpeedGHz);
}

LaptopCPU* CPUFactory::makeLaptopCPU(const std::string brandName,
                                     const std::string modelName,
                                     const uint16_t generationNumber,
                                     const uint16_t numberOfCores,
                                     const float maxClockSpeedGHz)
{
  return new LaptopCPU(brandName,
                       modelName,
                       generationNumber,
                       numberOfCores,
                       maxClockSpeedGHz);
}

