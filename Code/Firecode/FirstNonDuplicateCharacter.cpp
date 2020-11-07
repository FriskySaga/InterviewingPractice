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

using namespace std;

// char firstNonRepeating(string str)
// {
//   unordered_map<char> 

//   for (auto iter = str.cbegin(); iter != str.cend(); ++iter)
//   {
    
//   }
//   return '0';
// }

int main()
{
  assert(firstNonRepeating("abcdcd") == 'a');
  // assert(firstNonRepeating("cbcd") == 'b');
  // assert(firstNonRepeating("cdcd") == '0');
  // assert(firstNonRepeating("") == '0');

  return 0;
}
