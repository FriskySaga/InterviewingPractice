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

Android* ComputerFactory::makeAndroid(const std::string& androidBrandName,
                                      const std::string& androidModelName,
                                      const std::string& cpuBrandName,
                                      const std::string& cpuModelName,
                                      const uint16_t& cpuGenerationNumber,
                                      const uint16_t& cpuNumberOfCores,
                                      const float& cpuMaxClockSpeedGHz)
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

