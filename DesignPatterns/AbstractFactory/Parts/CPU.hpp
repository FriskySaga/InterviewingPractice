// Project includes
#include "Component.hpp"

class CPU : Component
{
public:
  virtual const int getNumberOfCores() = 0;
  virtual const float getClockSpeedGHz() = 0;
protected:
  CPU();
  virtual ~CPU();
};

