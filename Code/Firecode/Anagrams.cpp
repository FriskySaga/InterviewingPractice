/**
 * Firecode Level 2
 * 
 * Determine if two lowercase strings are anagrams.
 * An anagram is a string formed by rearranging the letters of another string.
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string input1, string input2)
{
  sort(input1.begin(), input1.end());
  sort(input2.begin(), input2.end());

  return input1 == input2;
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
