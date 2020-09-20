#pragma once

namespace ChakraNature
{
  enum ChakraNatureEnum
  {
    FIRE = 0,
    WIND = 1,
    LIGHTNING = 2,
    EARTH = 3,
    WATER = 4,
    WOOD = 5
  };

  static const char* ChakraNatureEnumStrings[] =
  {
    "FIRE",
    "WIND",
    "LIGHTNING",
    "EARTH",
    "WATER",
    "WOOD"
  };

  static const char* getString(int enumValue)
  {
    return ChakraNatureEnumStrings[enumValue];
  }
}

