/**
 * Firecode Level 2
 * 
 * Determine if two lowercase strings are anagrams.
 * An anagram is a string formed by rearranging the letters of another string.
 */

#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

bool isAnagram(std::string input1, std::string input2)
{
  std::unordered_map<char, unsigned int> hm;
  for (auto const& c : input1) ++hm[c];
  for (auto const& c : input2) --hm[c];
  for (auto const& x : hm)
    if (x.second) return false;
  return true;
}

int main()
{
  assert(isAnagram("ava", "ava"));
  assert(isAnagram("yellow", "llowey"));
  assert(isAnagram("no", "no"));
  assert(!isAnagram("n", "noooo"));
  assert(isAnagram("", ""));

  return 0;
}
