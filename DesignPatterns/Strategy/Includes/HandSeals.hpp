#pragma once

#include <string>
#include <vector>

namespace HandSeals
{
  extern const std::string Rat("Rat");
  extern const std::string Ox("Ox");
  extern const std::string Tiger("Tiger");
  extern const std::string Hare("Hare");
  extern const std::string Dragon("Dragon");
  extern const std::string Snake("Snake");
  extern const std::string Horse("Horse");
  extern const std::string Ram("Ram");
  extern const std::string Monkey("Monkey");
  extern const std::string Bird("Bird");
  extern const std::string Dog("Dog");
  extern const std::string Boar("Boar");
}

namespace GreatFireballHandSeals
{
  using namespace HandSeals;
  extern const std::vector<std::string> LongForm {Snake, Ram, Monkey, Boar, Horse, Tiger};
  extern const std::vector<std::string> RinNoSho {Horse, Tiger};
  extern const std::vector<std::string> HyoNoSho {Tiger};
  extern const std::vector<std::string> Itachi {Boar, Horse, Tiger};
}

namespace FourPillarHouseHandSeals
{
  using namespace HandSeals;
  extern const std::vector<std::string> StandardForm {Snake, Rat, Ox, Ram};
}

