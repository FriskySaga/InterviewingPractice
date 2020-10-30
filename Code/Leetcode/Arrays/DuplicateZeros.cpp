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
#include <iostream>
#include <vector>

using namespace std;

void duplicateZeros(vector<int>& arr)
{
  vector<int> brr;
  for (auto& iter : arr)
  {
    if (brr.size() < arr.size())
    {
      if (iter != 0)
      {
        brr.push_back(iter);
      }
      else
      {
        brr.push_back(iter);
        if (brr.size() < arr.size())
        {
          brr.push_back(0);
        }
      }
    }
  }
  arr = brr;
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
