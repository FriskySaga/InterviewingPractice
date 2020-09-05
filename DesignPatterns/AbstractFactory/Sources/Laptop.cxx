#include <string>
#include "Computer.cxx"
class Laptop : Computer
{
public:
  const std::string getBrand();
  const std::string getModel();
  const std::string getPlatform();
  // CPU& getCPU();
  // RAM& getRAM();
};

