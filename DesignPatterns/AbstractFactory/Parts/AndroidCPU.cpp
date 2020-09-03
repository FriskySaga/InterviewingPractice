#include <string>

class AndroidCPU
{
public:
  AndroidCPU(std::string brandName,
             std::string modelName,
             int numberOfCores,
             float clockSpeedGHz)
    : brandName(brandName),
      modelName(modelName),
      platformName("Android"),
      numberOfCores(numberOfCores),
      clockSpeedGHz(clockSpeedGHz)
  {
  }

  const std::string getBrand()
  {
    return brandName;
  }

  const std::string getModel()
  {
    return modelName;
  }

  const std::string getPlatform()
  {
    return platformName;
  }

  const int getNumberOfCores()
  {
    return numberOfCores;
  }

  const float getClockSpeedGHz()
  {
    return clockSpeedGHz;
  }

private:
  std::string brandName;
  std::string modelName;
  std::string platformName;
  int numberOfCores;
  float clockSpeedGHz;
};

