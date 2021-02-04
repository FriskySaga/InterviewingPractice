/**
 * Firecode - Level 5
 * Facebook
 * Leetcode Easy
 */

// Given an array consisting of both positive and negative integers, find the
// maximum sum among all the contiguous subsequences of the input array.

// In mathematics, a subsequence is a sequence that can be derived from another
// sequence by deleting some elements without changing the order of the remaining
// elements. For example, the sequence < A,B,D > is a subsequence of < A,B,C,D,E,F
// >. They should not be confused with substring which is a refinement of
// subsequence. 

// Write a function that takes in an array of integers arr with the size sz and
// returns the maximum sum.
// For an empty array, return 0. The maximum and minmimum possible numbers in the
// array can be 999 and -999

// Examples:
// max_sum_cont_sequence({-2,11,-4,13,-5,-2},6) --> 20
//   (maximum sequence is : {11,-4,13})
// max_sum_cont_sequence({1,-3,4,-2,-1,6},6) --> 7
//   (maximum sequence is : {4,-2,-1,6})
#include <algorithm>
int max_sum_cont_sequence(int arr[], int sz)
{
  if (sz == 0) return 0;
  int maxSoFar = arr[0];
  int currMax = arr[0];

  for (int i = 1; i < sz; ++i)
  {
    currMax = std::max(arr[i], currMax +  arr[i]);
    maxSoFar = std::max(maxSoFar, currMax);
  }
  return maxSoFar;
}
