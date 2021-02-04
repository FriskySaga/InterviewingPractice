/**
 * Firecode - Level 5
 * Amazon
 * Leetcode Medium
 * Partition Sum Problem
 * 
 * Credits:
 * https://www.geeksforgeeks.org/partition-problem-dp-18/
 */

// Write a function to determine if it is possible to split an array of integers arr
// with its size sz into two parts such that the sum of all integers in each partition is
// the same. An empty array cannot be split.

// Examples:
// split_array({1,2,3,4},3) ==> true
// split_array({1,2,4},3) ==> false

bool split_array(int arr[], int sz)
{
  int sum = 0;

  // Calculate sum of all elements
  for (int i = 0; i < sz; ++i)
    sum += arr[i];

  // Odd sum, can't split evenly
  if (sum % 2 != 0)
    return false;

  bool partition[sum / 2 + 1];

  // Initialze the partition array as 0
  for (int i = 0; i <= sum / 2; ++i)
    partition[i] = 0;

  // Fill the partition table in bottom up manner
  for (int i = 0; i < sz; ++i)
  {
    // The element to be included in the sum cannot be greater than the sum
    for (int j = sum / 2; j >= arr[i]; --j)
    {
      // Check if sum - arr[i] could be formed from a subset using elements before index i
      if (partition[j - arr[i]] == 1 || j == arr[i])
        partition[j] = 1;
    }
  }

  return partition[sum / 2];
}