/**
 * Leetcode Arrays
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

