/**
 * C++14
 */

#include <iostream>

template <class T>
T multiply(T a, T b)
{
  T result = a * b;
  return result;
}

int main()
{
  std::cout << multiply(4, 5) << std::endl; // 20
  std::cout << multiply(10.5, 2.0) << std::endl; // 21
  return 0;
}

