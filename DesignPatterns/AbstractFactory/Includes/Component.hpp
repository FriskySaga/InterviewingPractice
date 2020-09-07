// C++ includes
#include <string>

class Component
{
public:
  virtual std::string getBrand() const = 0;
  virtual std::string getModel() const = 0;
  virtual std::string getPlatform() const = 0;
};

