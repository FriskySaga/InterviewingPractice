// C++ includes
#include <iostream>

// External includes
#include <gtest/gtest.h>

// Project includes
#include "Android.hpp"
#include "AndroidCPU.hpp"
#include "Laptop.hpp"
#include "LaptopCPU.hpp"

TEST(AbstractFactoryTest, AndroidTest)
{
  // Create a CPU
  const std::string cpuBrandName("Qualcomm");
  const std::string cpuModelName("Snapdragon 855 Mobile Platform");
  const uint16_t generationNumber(4U);
  const uint16_t numberOfCores(8U);
  const float maxClockSpeedGHz(2.84);

  AndroidCPU androidCPU(cpuBrandName,
                        cpuModelName,
                        generationNumber,
                        numberOfCores,
                        maxClockSpeedGHz);

  EXPECT_EQ(cpuBrandName, androidCPU.getBrand());
  EXPECT_EQ(cpuModelName, androidCPU.getModel());
  EXPECT_EQ(generationNumber, androidCPU.getGeneration());
  EXPECT_EQ(numberOfCores, androidCPU.getNumberOfCores());
  EXPECT_EQ(maxClockSpeedGHz, androidCPU.getMaxClockSpeedGHz());

  // Create an Android phone
  const std::string androidBrandName("Samsung");
  const std::string androidModelName("Galaxy S10 Plus");
  Android androidPhone(androidBrandName,
                       androidModelName,
                       androidCPU);

  EXPECT_EQ(androidBrandName, androidPhone.getBrand());
  EXPECT_EQ(androidModelName, androidPhone.getModel());
  EXPECT_TRUE(androidCPU == androidPhone.getCPU());
}

TEST(AbstractFactoryTest, LaptopTest)
{
  // Create a CPU
  const std::string cpuBrandName("Intel");
  const std::string cpuModelName("Core i7-8565U");
  const uint16_t generationNumber(8U);
  const uint16_t numberOfCores(4U);
  const float maxClockSpeedGHz(4.60);

  LaptopCPU laptopCPU(cpuBrandName,
                      cpuModelName,
                      generationNumber,
                      numberOfCores,
                      maxClockSpeedGHz);

  EXPECT_EQ(cpuBrandName, laptopCPU.getBrand());
  EXPECT_EQ(cpuModelName, laptopCPU.getModel());
  EXPECT_EQ(generationNumber, laptopCPU.getGeneration());
  EXPECT_EQ(numberOfCores, laptopCPU.getNumberOfCores());
  EXPECT_EQ(maxClockSpeedGHz, laptopCPU.getMaxClockSpeedGHz());

  // Create a Laptop computer
  const std::string laptopBrandName("HP");
  const std::string laptopModelName("Elite Dragonfly");
  Laptop laptopComputer(laptopBrandName,
                        laptopModelName,
                        laptopCPU);

  EXPECT_EQ(laptopBrandName, laptopComputer.getBrand());
  EXPECT_EQ(laptopModelName, laptopComputer.getModel());
  EXPECT_TRUE(laptopCPU == laptopComputer.getCPU());
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

