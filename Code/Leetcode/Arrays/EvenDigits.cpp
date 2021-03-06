/**
 * Leetcode Arrays
 * 
 * Find Numbers with Even Number of Digits
 * 
 * Given an array nums of integers, return how many of them contain an even number of digits.
 * 
 * Example 1:
    Input: nums = [12,345,2,6,7896]
    
    Output: 2
    
    Explanation: 
     12 contains 2 digits (even number of digits). 
     345 contains 3 digits (odd number of digits). 
     2 contains 1 digit (odd number of digits). 
     6 contains 1 digit (odd number of digits). 
     7896 contains 4 digits (even number of digits). 
     Therefore only 12 and 7896 contain an even number of digits.
 * 
 * Example 2:
    Input: nums = [555,901,482,1771]
    
    Output: 1 
    
    Explanation: 
     Only 1771 contains an even number of digits.
 * 
 * Constraints:
    1 <= nums.length <= 500
    1 <= nums[i] <= 10^5
 */

#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int findNumbers(vector<int>& nums)
{
  int numEvens = 0;
  for (const auto& iter : nums)
  {
    int number = iter;
    uint16_t numDigits = 0;
    
    while (number != 0)
    {
      number /= 10;
      ++numDigits;
    }

    if (numDigits % 2 == 0)
    {
      ++numEvens;
    }
  }
  return numEvens;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> first{12,345,2,6,7896};
  assert(findNumbers(first) == 2);

  vector<int> second{555,901,482,1771};
  assert(findNumbers(second) == 1);

  vector<int> third;
  assert(findNumbers(third) == 0);

  return 0;
}
