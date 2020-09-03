#include <string>

class Component
{
public:
  virtual const std::string getBrand() = 0;
  virtual const std::string getModel() = 0;
  virtual const std::string getPlatform() = 0;
};

