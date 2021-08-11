#include <bitset>
#include <ios>
#include <iostream>
#include <vector>

class NumberSubject;

/**
 * Constructor is defined in the derived class
 * because otherwise will be an unresolved
 * cyclic dependency with Observer and NumberSubject.
 */
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

  /**
   * Output:
   * 
   * Binary: 00001111
   * Octal: 17
   * Decimal: 15
   * Hexadecimal: f
   */
  numberSubject->setNumber(15);

  /**
   * Output
   * 
   * Binary: 00001010
   * Octal: 12
   * Decimal: 10
   * Hexadecimal: a
   *
   */
  numberSubject->setNumber(10);

  delete numberSubject;
  return 0;
}
