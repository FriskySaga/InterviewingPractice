/**
 * C++14
 */

#include <cerrno>
#include <cstdio>
#include <cstring>
#include <iostream>

int main()
{
  if (std::rename("Source.txt", "Destination.txt") < 0)
  {
    std::cout << strerror(errno) << std::endl;
  }
  
  return 0;
}