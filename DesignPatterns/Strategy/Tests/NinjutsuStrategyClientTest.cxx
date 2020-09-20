// External includes
#include <gtest/gtest.h>

// Project includes
#include "ChakraNatureEnum.hpp"
#include "FourPillarHouse.hpp"
#include "GreatFireball.hpp"
#include "HandSeals.hpp"
#include "Ninja.hpp"

using namespace ChakraNature;

TEST(NinjaClientTest, StrategicalTest)
{
  Ninja Kakashi
  (
    std::set<ChakraNatureEnum>
    {
      ChakraNatureEnum::LIGHTNING,
      ChakraNatureEnum::EARTH,
      ChakraNatureEnum::WATER,
      ChakraNatureEnum::FIRE,
      ChakraNatureEnum::WIND
    }
  );

  // Use Great Fireball technique (memory gets cleaned up in destructor)
  Kakashi.cast(new GreatFireball(GreatFireballHandSeals::LongForm));
  GreatFireball* greatFireballJutsu = static_cast<GreatFireball*>(Kakashi.getNinjutsu());

  // Verify nature
  EXPECT_EQ(ChakraNatureEnum::FIRE, greatFireballJutsu->getNature());

  // Verify hand seals
  EXPECT_EQ(GreatFireballHandSeals::LongForm, greatFireballJutsu->getHandSeals());

  // Change hand seals
  greatFireballJutsu->changeHandSeals(GreatFireballHandSeals::Itachi);
  EXPECT_EQ(GreatFireballHandSeals::Itachi, greatFireballJutsu->getHandSeals());

  // Kakashi can't use Wood Style techniques
  Kakashi.cast(new FourPillarHouse(FourPillarHouseHandSeals::StandardForm));
  EXPECT_TRUE(testing::internal::GetCapturedStdout().find("Ninja cannot use Chakra Nature: WOOD\n") != std::string::npos);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  testing::internal::CaptureStdout();
  return RUN_ALL_TESTS();
}

