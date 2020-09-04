// C++ includes
#include <string>

// Project includes
#include "CPU.cpp"

class AndroidCPU : CPU
{
public:
  AndroidCPU(std::string brandName,
             std::string modelName,
             int numberOfCores,
             float clockSpeedGHz);

  virtual ~AndroidCPU();

  const std::string getBrand();

  const std::string getModel();

  const std::string getPlatform();

  const int getNumberOfCores();

  const float getClockSpeedGHz();

private:
  std::string brandName;
  std::string modelName;
  std::string platformName;
  int numberOfCores;
  float clockSpeedGHz;
};

