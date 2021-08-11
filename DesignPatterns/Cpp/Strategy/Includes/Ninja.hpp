#pragma once

// Project includes
class Ninjutsu;

class Ninja
{
public:
  Ninja(const std::set<ChakraNature::ChakraNatureEnum> natureCapabilities);
  ~Ninja();

  void cast(Ninjutsu* ninjutsu);
  Ninjutsu* getNinjutsu() const;

private:
  Ninjutsu* ninjutsu;
  std::set<ChakraNature::ChakraNatureEnum> natureCapabilities;
};

