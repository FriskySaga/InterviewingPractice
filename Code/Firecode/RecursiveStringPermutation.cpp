/**
 * Firecode Level 4
 * Google
 * Leetcode Medium
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// String permutations are the various possible strings made by the rearrangement of
// the characters in the original string.

// For example, the permutations of car are:
//   car, cra, acr, arc, rac, rca

// Write a recursive method get_permutations() that returns all permutations of an
// input string in an vector. Define a helper method if needed. For the sake of
// simplicity, assume that all characters in the input string are unique.

// Examples:
// get_permutations("") -> vector -> []
// get_permutations("c") -> vector -> ["c"]
// get_permutations("cat") -> vector -> ["cat","cta","act","atc","tca","tac"]*
// *Order does not matter.
vector<string> getPermutations(string s) 
{
  vector<string> permutations;
  if (s.size() <= 1U)
  {
    permutations.push_back(s);
    return permutations;
  }

  vector<string> resultSet;
  permutations = getPermutations(s.substr(1U));
  for (const auto& str : permutations)
  {
    int len = str.size();
    for (int j = -1; j < len; ++j)
    {
      string newStr = str.substr(0U, j + 1) +  s.at(0U) + str.substr(j + 1);
      resultSet.push_back(newStr);
    }
  }

  return resultSet;
}

int main()
{
  // ["cat","cta","act","atc","tca","tac"]
  vector<string> result = getPermutations("cat");

  // print result
  cout << "[";
  for (auto const& x : result) cout << x << ",";
  cout << "]" << endl;
  return 0;
}