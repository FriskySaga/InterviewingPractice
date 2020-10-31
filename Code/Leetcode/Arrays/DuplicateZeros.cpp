/**
 * Leetcode Arrays
 * 
 * Duplicate Zeros
 * 
 * Given a fixed length array arr of integers, duplicate each occurrence of zero,
 * shifting the remaining elements to the right.
 * 
 * Note that elements beyond the length of the original array are not written.
 * 
 * Do the above modifications to the input array in place, do not return anything from your function.
 * 
 * Example 1:
    Input: [1,0,2,3,0,4,5,0]
    Output: null
    Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
 *
 * Example 2:
    Input: [1,2,3]
    Output: null
    Explanation: After calling your function, the input array is modified to: [1,2,3]
 * 
 * Note:
    1 <= arr.length <= 10000
    0 <= arr[i] <= 9
 */

#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

void duplicateZeros(vector<int>& arr)
{
  uint16_t possibleDuplicates = 0;
  int maxOrigIndex = arr.size() - 1;

  // Identify the number of duplicate zeros to keep
  // Ex: 1 0 2 3 0 4
  // Ex:               maxOrigIndex - possibleDuplicates
  // index 0, value 1: 5 - 0
  // index 1, value 0: 5 - 0
  // index 2, value 2: 5 - 1
  // index 3, value 3: 5 - 1
  // index 4, value 0: 5 - 1
  // index 5, value 4: 5 - 2 (don't enter loop)
  for (uint16_t i = 0; i <= maxOrigIndex - possibleDuplicates; ++i)
  {
    if (arr[i] == 0)
    {
      // Don't duplicate this zero since duplicating would go beyond the array
      // Ex: the second 0
      // Ex: 4 == 5 - 1
      if (i == maxOrigIndex - possibleDuplicates)
      {
        // Immediately copy this 0
        arr[maxOrigIndex] = 0;
        --maxOrigIndex;
        break;
      }

      // Ex: the first 0, increment counter to 1
      ++possibleDuplicates;
    }
  }

  // Ex: lastIdx = 4 - 1 = 3
  int lastIdx = maxOrigIndex - possibleDuplicates;

  // Modify the original array with the duplicated zeros
  // Ex: 1 0 2 3 0 4
  // index 3, value 3, arr[4] = arr[3], dupes 1
  // index 2, value 2, arr[3] = arr[2], dupes 1
  // index 1, value 0, arr[2] = arr[1], dupes 1
  // index 1, value 0, arr[1] = arr[1], dupes 0
  // index 0, value 1, arr[0] = arr[0], dupes 0
  for (int16_t i = lastIdx; i >= 0; --i)
  {
    if (arr[i] == 0)
    {
      arr[i+possibleDuplicates] = 0;
      --possibleDuplicates;
      arr[i+possibleDuplicates] = 0;
    }
    else
    {
      arr[i+possibleDuplicates] = arr[i];
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  vector<int> q1{1,0,2,3,0,4,5,0};
  vector<int> a1{1,0,0,2,3,0,0,4};
  duplicateZeros(q1);
  assert(q1 == a1);

  vector<int> q2{1,2,3};
  vector<int> a2{1,2,3};
  duplicateZeros(q2);
  assert(q2 == a2);

  vector<int> q3{1};
  vector<int> a3{1};
  duplicateZeros(q3);
  assert(a3 == a3);

  vector<int> q4;
  vector<int> a4;
  duplicateZeros(q4);
  assert(q4 == a4);

  return 0;
}
