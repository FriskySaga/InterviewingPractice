// Project includes
//#include "Component.h"

class CPU // : Component
{
public:
  CPU();
  virtual ~CPU();
  virtual const int getNumberOfCores() = 0;
  virtual const float getClockSpeedGHz() = 0;
private:
};

