// C++ includes
#include <iostream>

// External includes
#include <gtest/gtest.h>

// Project includes
#include "AndroidCPU.hpp"

TEST(AbstractFactoryTest, AndroidCPUTest)
{
  const std::string brandName("Qualcomm");
  const std::string modelName("Snapdragon 855 Mobile Platform");
  const uint16_t generationNumber(4U);
  const uint16_t numberOfCores(8U);
  const float maxClockSpeedGHz(2.84);

  AndroidCPU phoneCPU(brandName,
                      modelName,
                      generationNumber,
                      numberOfCores,
                      maxClockSpeedGHz);

  EXPECT_EQ(brandName, phoneCPU.getBrand());
  EXPECT_EQ(modelName, phoneCPU.getModel());
  EXPECT_EQ(generationNumber, phoneCPU.getGeneration());
  EXPECT_EQ(numberOfCores, phoneCPU.getNumberOfCores());
  EXPECT_EQ(maxClockSpeedGHz, phoneCPU.getMaxClockSpeedGHz());
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

