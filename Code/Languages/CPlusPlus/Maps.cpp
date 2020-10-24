/**
 * C++14
 */

#include <iostream>
#include <map>
#include <string>

int main()
{
{
  std::cout << "Long-style for loop" << std::endl;
  std::map<char,int> alphabet;
  alphabet['a'] = 1;
  alphabet['b'] = 2;
  alphabet['c'] = 3;
  for (auto it = alphabet.begin(); it != alphabet.end(); ++it)
  {
    std::cout << it->first << ": " << it->second << std::endl;
  }
  std::cout << std::endl;
}

{
  std::cout << "auto const&" << std::endl;
  std::map<char,std::string> alphabet;
  alphabet.insert(std::pair<char,std::string>('a', "apple"));
  alphabet.insert(std::pair<char,std::string>('b', "broken"));
  for (auto const& x : alphabet)
  {
    std::cout << x.first << ": " << x.second << std::endl;
  }
  std::cout << std::endl;
}

{
  std::cout << "std::pair<char,float> const&" << std::endl;
  std::map<char,float> alphabet;
  alphabet.insert(std::map<char,float>::value_type('c', 3.0));
  alphabet.insert(std::map<char,float>::value_type('d', 4.0));
  for (std::pair<char,float> const& item : alphabet)
  {
    std::cout << item.first << ": " << item.second << std::endl;
  }
  std::cout << std::endl;
}

{
  std::cout << "C++17 structured binding loop" << std::endl;
  std::map<int,float> numbers;
  numbers.insert(std::make_pair(0, 0.5));
  numbers.insert(std::make_pair(1, 1.5));
  for (auto const& [key, val] : numbers)
  {
    std::cout << key << ": " << val << std::endl;
  }
}

  return 0;
}

