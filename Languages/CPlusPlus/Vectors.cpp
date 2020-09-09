/**
 * C++14
 */

#include <iostream>
#include <vector>

int main()
{
  std::vector<int> intVector = {1,2,3,4,5};

  // C-style loops
  std::cout << "C-style loop" << std::endl;
  for (uint16_t i = 0U; i< intVector.size(); ++i)
  {
    std::cout << intVector.at(i) << " ";
  }
  std::cout << std::endl << std::endl;

  // Vector iterator for loop
  std::cout << "Vector iterator for loop" << std::endl;
  std::vector<int>::iterator it;
  for (it = intVector.begin(); it < intVector.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl << std::endl;

  // Vector iterator while loop
  std::cout << "Vector iterator while loop" << std::endl;
  std::vector<int>::iterator iter = intVector.begin();
  while (iter != intVector.end())
  {
    std::cout << *iter << " ";
    ++iter;
  }
  std::cout << std::endl << std::endl;

  return 0;
}

