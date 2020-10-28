/**
 * Leetcode Arrays
 * 
 * Squares of a Sorted Array
 * 
 * Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number,
 * also in sorted non-decreasing order.
 * 
 * Example 1:
    Input: [-4,-1,0,3,10]
    Output: [0,1,9,16,100]
 * 
 * Example 2:
    Input: [-7,-3,2,3,11]
    Output: [4,9,9,49,121]
 * 
 * Note:
    1 <= A.length <= 10000
    -10000 <= A[i] <= 10000
    A is sorted in non-decreasing order.
 */

#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Example 1 Walkthrough:
 * 
 * n(4) = abs(-4) > abs(10) : 10 * 10 = 100
 * n(3) = abs(-4) > abs(3) ? 4 * 4 = 16
 * n(2) = abs(-1) > abs(3) : 3 * 3 = 9
 * n(1) = abs(-1) > abs(0) ? 1 * 1 = 1
 * n(0) = abs(0) > abs(0) : 0 * 0 = 0
 * 
 */
vector<int> sortedSquares(vector<int>& A) 
{
  vector<int> B(A.size());

  int16_t i = 0, j = A.size() > 1 ? A.size() - 1 : 0, n = j;
  
  while (i <= j)
  {
    int first  = A[i];
    int second = A[j];

    if (abs(first) > abs(second))
    {
      B[n] = first * first;
      ++i;
    }
    else
    {
      B[n] = second * second;
      --j;
    }
    --n;
  }

  return B;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> q1{-4,-1,0,3,10};
  vector<int> a1{0,1,9,16,100};
  assert(sortedSquares(q1) == a1);

  vector<int> q2{-7,-3,2,3,11};
  vector<int> a2{4,9,9,49,121};
  assert(sortedSquares(q2) == a2);

  vector<int> q3{1};
  vector<int> a3{1};
  assert(sortedSquares(q3) == a3);
}