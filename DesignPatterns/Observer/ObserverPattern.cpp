#include <bitset>
#include <ios>
#include <iostream>
#include <vector>

class NumberSubject;
class Observer
{
public:
  virtual ~Observer()
  {
  }
  virtual void update() = 0;

protected:
  NumberSubject* numberSubject;
};

class NumberSubject
{
public:
  NumberSubject() :
    observers(),
    number(0)
  {
  }

  void addObserver(Observer* observer)
  {
    observers.push_back(observer);
  }

  void notifyAllObservers()
  {
    std::cout << std::endl;
    for (auto observer : observers)
    {
      observer->update();
    }
  }

  int getNumber()
  {
    return number;
  }

  void setNumber(int number)
  {
    this->number = number;
    notifyAllObservers();
  }

private:
  std::vector<Observer*> observers;
  int number;
};

class BinaryObserver : Observer
{
public:
  BinaryObserver(NumberSubject* numberSubject)
  {
    this->numberSubject = numberSubject;
    this->numberSubject->addObserver(this);
  }

  void update()
  {
    std::cout << "Binary: " << std::bitset<8>(this->numberSubject->getNumber()) << std::endl;
  }
};

class OctalObserver : Observer
{
public:
  OctalObserver(NumberSubject* numberSubject)
  {
    this->numberSubject = numberSubject;
    this->numberSubject->addObserver(this);
  }

  void update()
  {
    std::cout << "Octal: " << std::oct << this->numberSubject->getNumber() << std::endl;
  }
};

class DecimalObserver : Observer
{
public:
  DecimalObserver(NumberSubject* numberSubject)
  {
    this->numberSubject = numberSubject;
    this->numberSubject->addObserver(this);
  }

  void update()
  {
    std::cout << "Decimal: " << std::dec << this->numberSubject->getNumber() << std::endl;
  }
};

class HexObserver : Observer
{
public:
  HexObserver(NumberSubject* numberSubject)
  {
    this->numberSubject = numberSubject;
    this->numberSubject->addObserver(this);
  }

  void update()
  {
    std::cout << "Hexadecimal: " << std::hex << this->numberSubject->getNumber() << std::endl;
  }
};

int main()
{
  NumberSubject* numberSubject = new NumberSubject();

  BinaryObserver binaryObserver(numberSubject);
  OctalObserver octalObserver(numberSubject);
  DecimalObserver decimalObserver(numberSubject);
  HexObserver hexObserver(numberSubject);

  numberSubject->setNumber(15);
  numberSubject->setNumber(10);

  delete numberSubject;
  return 0;
}
