#include <bitset>
#include <iostream>

/**
 * Return number of 1s in the
 * binary form of this integer
 */
int function(int a)
{
  int i = 0;
  for (i = 0; a; ++i)
  {
    a &= a-1;
  }
  return i;
}

int main()
{
  std::cout << "f(2) = f("
    << std::bitset<4>(2) << ") = "
    << function(2) << std::endl;
  
  std::cout << "f(5) = f("
    << std::bitset<4>(5) << ") = "
    << function(5) << std::endl;
  
  std::cout << "f(7) = f("
    << std::bitset<4>(7) << ") = "
    << function(7) << std::endl;
  
  std::cout << "f(100) = f("
    << std::bitset<8>(100) << ") = "
    << function(100) << std::endl;

  std::cout << "f(127) = f("
    << std::bitset<8>(127) << ") = "
    << function(127) << std::endl;

  return 0;
}