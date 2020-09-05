#include <string>

class LaptopCPU
{
public:
  const std::string getBrand();
  const std::string getModel();
  const std::string getPlatform();
  const int getNumberOfCores();
  const float getMaxClockSpeedGHz();
};

