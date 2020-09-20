#pragma once

// Standard includes
#include <string>
#include <vector>

// Project includes
#include "ChakraNatureEnum.hpp"

class Ninjutsu
{
public:
  std::vector<std::string> getHandSeals() const;
  void changeHandSeals(const std::vector<std::string> handSeals); 

  virtual ChakraNature::ChakraNatureEnum getNature() const = 0;

protected:
  Ninjutsu(const std::vector<std::string> handSeals);

private:
  ChakraNature::ChakraNatureEnum nature;
  std::vector<std::string> handSeals;
};

