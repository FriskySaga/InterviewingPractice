// C++ includes
#include <iostream>

// External includes
#include <gtest/gtest.h>

// Project includes
#include "AndroidCPU.hpp"

TEST(AbstractFactoryTest, AndroidCPUTest)
{
  AndroidCPU phoneCPU(
    "Qualcomm",
    "Snapdragon 865 5G Mobile Platform",
    5U,
    8U,
    2.84
  );
  std::cout << "hello" << std::endl;
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

