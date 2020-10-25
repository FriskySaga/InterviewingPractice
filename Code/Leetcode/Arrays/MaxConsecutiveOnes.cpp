/**
 * Leetcode Arrays
 * 
 * Max Consecutive Ones
 * 
 * Given a binary array, find the maximum number of consecutive 1s in this array.
 * 
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * 
 * Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
 * 
 * Note:
    The input array will only contain 0 and 1.
    The length of input array is a positive integer and will not exceed 10,000
 */

#include <cassert>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums)
{
  unsigned int cnt = 0, max = 0;
  vector<int>::const_iterator iter = nums.begin();
  for (; iter != nums.end(); ++iter)
  {
    if (*iter == 1)
    {
      ++cnt;
    }
    else
    {
      if (cnt > max)
      {
        max = cnt;
      }
      cnt = 0;
      continue;
    }
    if (cnt > max)
    {
      max = cnt;
    }
  }
  return max;
}

int main()
{
    vector<int> first{1,1,0,1,1,1};
    assert(findMaxConsecutiveOnes(first) == 3);

    vector<int> second{1};
    assert(findMaxConsecutiveOnes(second) == 1);

    vector<int> third{0};
    assert(findMaxConsecutiveOnes(third) == 0);

    vector<int> fourth;
    assert(findMaxConsecutiveOnes(fourth) == 0);

    return 0;
}
