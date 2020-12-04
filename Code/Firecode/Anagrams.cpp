/**
 * Anagrams
 * Visa
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
  for (const auto& x : input1) ++hm[x];
  for (const auto& x : input2) --hm[x];
  for (const auto& x : hm) if (x.second > 0) return false;
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
