// External includes
#include <gtest/gtest.h>

// Project includes
#include "ComputerFactory.hpp"
#include "CPUFactory.hpp"

TEST(AbstractFactoryTest, AndroidCPUFactoryTest)
{
  CPUFactory cpuFactory;
  const std::string platformName("Android");

  // Create an Android CPU
  const std::string cpuBrandName("Qualcomm");
  const std::string cpuModelName("Snapdragon 855 Mobile Platform");
  const uint16_t generationNumber(4U);
  const uint16_t numberOfCores(8U);
  const float maxClockSpeedGHz(2.84);

  AndroidCPU* androidCPU1 = cpuFactory.makeAndroidCPU(cpuBrandName,
                                                      cpuModelName,
                                                      generationNumber,
                                                      numberOfCores,
                                                      maxClockSpeedGHz);
  EXPECT_EQ(cpuBrandName, androidCPU1->getBrand());
  EXPECT_EQ(cpuModelName, androidCPU1->getModel());
  EXPECT_EQ(platformName, androidCPU1->getPlatform());
  EXPECT_EQ(generationNumber, androidCPU1->getGeneration());
  EXPECT_EQ(numberOfCores, androidCPU1->getNumberOfCores());
  EXPECT_EQ(maxClockSpeedGHz, androidCPU1->getMaxClockSpeedGHz());

  AndroidCPU* androidCPU2 = cpuFactory.makeAndroidCPU(cpuBrandName,
                                                      cpuModelName,
                                                      generationNumber,
                                                      numberOfCores,
                                                      maxClockSpeedGHz);
  EXPECT_TRUE(*androidCPU1 == *androidCPU2);

  delete androidCPU1;
  delete androidCPU2;
}

TEST(AbstractFactoryTest, LaptopCPUFactoryTest)
{
  CPUFactory cpuFactory;
  const std::string platformName("Laptop");

  // Create a laptop CPU
  const std::string cpuBrandName("Intel");
  const std::string cpuModelName("Core i7-8565U");
  const uint16_t generationNumber(8U);
  const uint16_t numberOfCores(4U);
  const float maxClockSpeedGHz(4.60);

  LaptopCPU* laptopCPU1 = cpuFactory.makeLaptopCPU(cpuBrandName,
                                                   cpuModelName,
                                                   generationNumber,
                                                   numberOfCores,
                                                   maxClockSpeedGHz);
  EXPECT_EQ(cpuBrandName, laptopCPU1->getBrand());
  EXPECT_EQ(cpuModelName, laptopCPU1->getModel());
  EXPECT_EQ(platformName, laptopCPU1->getPlatform());
  EXPECT_EQ(generationNumber, laptopCPU1->getGeneration());
  EXPECT_EQ(numberOfCores, laptopCPU1->getNumberOfCores());
  EXPECT_EQ(maxClockSpeedGHz, laptopCPU1->getMaxClockSpeedGHz());

  LaptopCPU* laptopCPU2 = cpuFactory.makeLaptopCPU(cpuBrandName,
                                                   cpuModelName,
                                                   generationNumber,
                                                   numberOfCores,
                                                   maxClockSpeedGHz);
  EXPECT_TRUE(*laptopCPU1 == *laptopCPU2);

  delete laptopCPU1;
  delete laptopCPU2;
}

TEST(AbstractFactoryTest, AndroidComputerFactoryTest)
{
  ComputerFactory factory;

  const std::string platformName("Android");
  const std::string androidBrandName("Samsung");
  const std::string androidModelName("Galaxy S10 Plus");
  const std::string cpuBrandName("Qualcomm");
  const std::string cpuModelName("Snapdragon 855 Mobile Platform");
  const uint16_t generationNumber(4U);
  const uint16_t numberOfCores(8U);
  const float maxClockSpeedGHz(2.84);

  Android* android = factory.makeAndroid(androidBrandName,
                                         androidModelName,
                                         cpuBrandName,
                                         cpuModelName,
                                         generationNumber,
                                         numberOfCores,
                                         maxClockSpeedGHz);

  // Validate Android
  EXPECT_EQ(androidBrandName, android->getBrand());
  EXPECT_EQ(androidModelName, android->getModel());
  EXPECT_EQ(platformName, android->getPlatform());

  // Validate CPU
  EXPECT_EQ(cpuBrandName, android->getCPU()->getBrand());
  EXPECT_EQ(cpuModelName, android->getCPU()->getModel());
  EXPECT_EQ(platformName, android->getCPU()->getPlatform());
  EXPECT_EQ(generationNumber, android->getCPU()->getGeneration());
  EXPECT_EQ(numberOfCores, android->getCPU()->getNumberOfCores());
  EXPECT_EQ(maxClockSpeedGHz, android->getCPU()->getMaxClockSpeedGHz());

  delete android;
}

TEST(AbstractFactoryTest, LaptopComputerFactoryTest)
{
  ComputerFactory factory;

  const std::string platformName("Laptop");
  const std::string laptopBrandName("HP");
  const std::string laptopModelName("Elite Dragonfly");
  const std::string cpuBrandName("Intel");
  const std::string cpuModelName("Core i7-8565U");
  const uint16_t generationNumber(8U);
  const uint16_t numberOfCores(4U);
  const float maxClockSpeedGHz(4.60);

  Laptop* laptop = factory.makeLaptop(laptopBrandName,
                                      laptopModelName,
                                      cpuBrandName,
                                      cpuModelName,
                                      generationNumber,
                                      numberOfCores,
                                      maxClockSpeedGHz);

  // Validate Laptop
  EXPECT_EQ(laptopBrandName, laptop->getBrand());
  EXPECT_EQ(laptopModelName, laptop->getModel());
  EXPECT_EQ(platformName, laptop->getPlatform());

  // Validate CPU
  EXPECT_EQ(cpuBrandName, laptop->getCPU()->getBrand());
  EXPECT_EQ(cpuModelName, laptop->getCPU()->getModel());
  EXPECT_EQ(platformName, laptop->getCPU()->getPlatform());
  EXPECT_EQ(generationNumber, laptop->getCPU()->getGeneration());
  EXPECT_EQ(numberOfCores, laptop->getCPU()->getNumberOfCores());
  EXPECT_EQ(maxClockSpeedGHz, laptop->getCPU()->getMaxClockSpeedGHz());

  delete laptop;
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

