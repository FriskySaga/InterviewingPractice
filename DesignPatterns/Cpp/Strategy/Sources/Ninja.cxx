// Standard includes
#include <iostream>
#include <set>

// Project includes
#include "Ninjutsu.hpp"
#include "Ninja.hpp"

Ninja::Ninja(const std::set<ChakraNature::ChakraNatureEnum> natureCapabilities)
  : natureCapabilities(natureCapabilities)
{
}

Ninja::~Ninja()
{
  delete ninjutsu;
}

void Ninja::cast(Ninjutsu* ninjutsu)
{
  ChakraNature::ChakraNatureEnum nature = ninjutsu->getNature();
  if (natureCapabilities.count(nature))
  {
    this->ninjutsu = ninjutsu;
  }
  else
  {
    std::cout << "Ninja cannot use Chakra Nature: " << ChakraNature::getString(nature) << std::endl;
    delete ninjutsu;
  }
}

Ninjutsu* Ninja::getNinjutsu() const
{
  return ninjutsu;
}

