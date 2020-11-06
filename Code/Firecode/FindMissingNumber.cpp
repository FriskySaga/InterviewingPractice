/**
 * Firecode Level 2
 * 
 * Given an array of n integers in the range of 1 to n+1,
 * write a function to find and return the missing number in the array.
 * There are no duplicates in the array, and only one number is missing.
 * 
 * Examples:
 * find_missing_number({1,2,3,5,6,7,8}, 7) ==> 4
 * find_missing_number({1,2,3,4,5,6,7,8,10}, 9) ==> 9
 */

#include <cassert>
#include <iostream>

using namespace std;

int findMissingNumber(int arr[], int n) 
{
  for (int i = 0; i < n; ++i)
  {
    if (arr[i] != i+1)
    {
      return i+1;
    }
  }

  // Case when arr = {1}, so the missing element is the next integer, which is 2
  return 2;
}

int main()
{
  int a[7] = {1,2,3,5,6,7,8};
  assert(findMissingNumber(a, 7) == 4);

  int b[9] = {1,2,3,4,5,6,7,8,10};
  assert(findMissingNumber(b, 9) == 9);

  int c[1] = {2};
  assert(findMissingNumber(c, 1) == 1);

  int d[1] = {1};
  assert(findMissingNumber(d, 1) == 2);

  return 0;
}
