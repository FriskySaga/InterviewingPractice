/**
 * Firecode Level 2
 * 
 * Find the first non-duplicate character in a string.
 * Return '0' if no unique character is found.
 * 
 * first_non_repeating( "abcdcd" ) --> 'a'
 * first_non_repeating( "cbcd" ) --> 'b'
 * first_non_repeating( "cdcd" ) --> '0'
 */

#include <cassert>
#include <string>
#include <unordered_map>

char firstNonRepeating(std::string str)
{
  std::unordered_map<char, unsigned int> hm;

  // Count occurrences of each character
  for (const auto c : str)
  {
    ++hm[c];
  }

  // Find the first character with a single occurrence
  for (const auto c : str)
  {
    if (hm.at(c) == 1)
    {
      return c;
    }
  }

  return '0';
}

int main()
{
  assert(firstNonRepeating("abcdcd") == 'a');
  assert(firstNonRepeating("cbcd") == 'b');
  assert(firstNonRepeating("cdcd") == '0');
  assert(firstNonRepeating("") == '0');

  return 0;
}
