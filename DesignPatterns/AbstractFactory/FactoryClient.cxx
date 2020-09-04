// C++ includes
#include <iostream>

// External includes
#include <gtest/gtest.h>

// Project includes
#include "AndroidCPU.hpp"

TEST(AbstractFactoryTest, CPUFactoryTest)
{
  ASSERT_EQ(1,1);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

