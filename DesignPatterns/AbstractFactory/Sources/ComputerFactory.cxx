// Project includes
#include "ComputerFactory.hpp"
#include "CPUFactory.hpp"

ComputerFactory::ComputerFactory()
  : cpuFactory(new CPUFactory())
{
}

ComputerFactory::~ComputerFactory()
{
  delete cpuFactory;
}

Android* ComputerFactory::makeAndroid(std::string androidBrandName,
                                      std::string androidModelName,
                                      std::string cpuBrandName,
                                      std::string cpuModelName,
                                      uint16_t cpuGenerationNumber,
                                      uint16_t cpuNumberOfCores,
                                      float cpuMaxClockSpeedGHz)
{
  AndroidCPU* cpu = cpuFactory->makeAndroidCPU(cpuBrandName,
                                               cpuModelName,
                                               cpuGenerationNumber,
                                               cpuNumberOfCores,
                                               cpuMaxClockSpeedGHz);

  return new Android(androidBrandName,
                     androidModelName,
                     cpu); // udyr memory leak?
}

