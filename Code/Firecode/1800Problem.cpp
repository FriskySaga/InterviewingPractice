/**
 * Firecode Level 4
 * Leetcode Medium
 * Facebook
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Given a string that represents the digits pressed on a classic cell phone keypad
// - return all possible letter combinations that the numbers could represent in an
// vector of strings. Check out the keypad and mapping below for reference.

// Note:
// a) You can assume that the input String contains only numbers between 2 and 9.
// b) The order of the combinations in the output does not matter.

// Mapping:
// 2 -> "abc"
// 3 -> "def"
// 4 -> "ghi"
// 5 -> "jkl"
// 6 -> "mno"
// 7 -> "pqrs"
// 8 -> "tuv"
// 9 -> "wxyz"

void backtrack(const string& letterCombination,
               const string& nextDigits,
               const unordered_map<char, string>& digitsToLetters,
               vector<string>& stringsFromNums)
{
  if (nextDigits.empty())
    stringsFromNums.push_back(letterCombination);

  else
  {
    string letters = digitsToLetters.at(nextDigits.front());
    for (const auto& letter : letters)
      backtrack(letterCombination + letter,
                nextDigits.substr(1U),
                digitsToLetters,
                stringsFromNums);
  }
}

// Example:
// Input  : "34" 
// Output : [dg, dh, di, eg, eh, ei, fg, fh, fi]
vector<string> getStringsFromNums(string digits) 
{
  unordered_map<char, string> digitsToLetters
  ({
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
  });
  vector<string> stringsFromNums;

  if (!digits.empty())
    backtrack("", digits, digitsToLetters, stringsFromNums);
  return stringsFromNums;
}

int main()
{
  // [dg, dh, di, eg, eh, ei, fg, fh, fi]
  vector<string> result = getStringsFromNums("34");

  // print result
  cout << "[";
  for (auto const& x : result) cout << x << ",";
  cout << "]" << endl;
  return 0;
}
