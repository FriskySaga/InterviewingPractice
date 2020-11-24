/**
 * Firecode Level 2
 * Salesforce
 */

// Given two strings - input1 and input2, determine if they are isomorphic. Two
// strings are isomorphic if the letters in one string can be remapped to get the
// second string. Remapping a letter means replacing all occurrences of it with
// another letter. The ordering of the letters remains unchanged. You can also think
// of isomorphism as it is used in chemistry - i.e. having the same form or overall
// shape. Target linear time and space complexity with your solution.

// Examples:

// Input 1 : css
// Input 2 : dll
// Output  : 1

// Input 1 : css
// Input 2 : dle
// Output  : 0

// Input 1 : abcabc
// Input 2 : xyzxyz
// Output  : true

// Input 1 : abcabc
// Input 2 : xbexyz
// Output  : false

#include <boost/range/combine.hpp>
#include <boost/tuple/tuple.hpp>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

bool isIsomorphic(std::string input1, std::string input2)
{
  if (input1.size() != input2.size()) return false;

  std::unordered_map<char, char> m1;
  std::unordered_map<char, char> m2;
  for (const auto& x : boost::combine(input1, input2))
  {
    char a, b;
    boost::tie(a, b) = x;

    if (m1.find(a) != m1.end())
    {
      if (m1.at(a) != b) return false;
    }
    if (m2.find(b) != m2.end())
    {
      if (m2.at(b) != a) return false;
    }
    else
    {
      // No need to worry about duplicate insertion attempt for m1. Suppose:
      // input1 = "aa", input2 = "ab"
      // We would have returned False since m1['a'] != 'b'
      m1.insert(std::make_pair(a,b));
      m2.insert(std::make_pair(b,a));
    }
  }
  return true;
}

int main()
{
  assert(isIsomorphic("css", "dll"));
  assert(!isIsomorphic("css", "dle"));
  assert(isIsomorphic("abcabc", "xyzxyz"));
  assert(!isIsomorphic("abcabc", "xbexyz"));
  assert(!isIsomorphic("abcd", "aabb"));
  assert(!isIsomorphic("a", "ab"));
  assert(!isIsomorphic("aba", "abb"));
  assert(isIsomorphic("aba", "aba"));

  return 0;
}