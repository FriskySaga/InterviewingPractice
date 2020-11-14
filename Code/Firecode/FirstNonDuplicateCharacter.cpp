/**
 * Find the first non-duplicate character in a string.
 * Return '0' if no unique character is found.
 * 
 * first_non_repeating( "abcdcd" ) --> 'a'
 * first_non_repeating( "cbcd" ) --> 'b'
 * first_non_repeating( "cdcd" ) --> '0'
 */

#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * 1. Create the character count map < char, int > hmp.
 * For each character, if there is no value stored in the map, insert an entry hmp.insert(pair(c, 1)) .
 * Else find the entry using iterators it = hmp.find(c) and increment the value of  it->second by 1.
 * 
 * 2. Scan the string, return the character if the count in the hmp is 1 .
 * If no characters have count of 1 , return '0'
 */
char firstNonRepeating(string str)
{
  map <char, int> hmp;

  // Create the character count map
  for (auto c = str.cbegin(); c != str.cend(); ++c)
  {
    auto findResult = hmp.find(*c);

    // Add character to the map
    if (findResult == hmp.end())
    {
      hmp.insert(pair<char, int>(*c, 1));
    }

    // Else, character already exists in the map, increase the count
    else
    {
      ++findResult->second;
    }
  }

  // Find the first character with a count of 1
  for (auto c = str.cbegin(); c != str.cend(); ++c)
  {
    if (hmp.find(*c)->second == 1)
    {
      return *c;
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
