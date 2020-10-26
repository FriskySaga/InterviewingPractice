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

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

vector<int> sortedSquares(vector<int>& A)
{
  vector<int> B;
  for (const auto& iter : A)
  {
    B.push_back(iter*iter);
  }
  
  sort(B.begin(), B.end());
  
  return B;
}

int main()
{
  vector<int> q1{-4,-1,0,3,10};
  vector<int> a1{0,1,9,16,100};
  assert(sortedSquares(q1) == a1);

  vector<int> q2{-7,-3,2,3,11};
  vector<int> a2{4,9,9,49,121};
  assert(sortedSquares(q2) == a2);

  vector<int> q3;
  vector<int> a3;
  assert(sortedSquares(q3) == a3);
}