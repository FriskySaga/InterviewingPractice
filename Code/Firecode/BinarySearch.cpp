/**
 * Firecode Level 2
 */

// Binary search or half-interval search algorithm finds the position of a specified
// input value (the search "key") within an array sorted by key value. For binary
// search, the array should be arranged in ascending or descending order.

// Algorithm

// In each step, the algorithm compares the search key value with the key value of
// the middle element of the array. If the keys match, then a matching element has
// been found and its index, or position, is returned. Otherwise, if the search key
// is less than the middle element's key, then the algorithm repeats its action on
// the sub-array to the left of the middle element or, if the search key is greater,
// on the sub-array to the right. If the remaining array to be searched is empty,
// then the key cannot be found in the array and a special "not found" indication is
// returned.

// A binary search halves the number of items to check with each iteration, so
// locating an item (or determining its absence) takes logarithmic time. A binary
// search is a dichotomic divide and conquer search algorithm.

// Write a function that searches an array of integers for a given integer using the
// Binary Search Algorithm. If the element is found in the array, return true.
// Otherwise, return false. You can assume that the given array of integers is
// already sorted in ascending order.

// Examples:
// binary_search({2,5,7,8,9},5,9) -> true
// binary_search({2,8,9,12},4,6) -> false
// binary_search({2},1,4) -> false
// binary_search({},0,9) -> false

#include <cassert>

bool binarySearch(int arr[], int size, int n)
{
  int low = 0, high = size - 1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (n < arr[mid])
      high = mid - 1;
    else if (n > arr[mid])
      low = mid + 1;
    else 
      return true;
  }

  return false;
}

int main()
{
  int a[5] = {2,5,7,8,9};
  assert(binarySearch(a, 5, 9) == true);

  int b[4] = {2,8,9,12};
  assert(binarySearch(b, 4, 6) == false);

  int c[1] = {2};
  assert(binarySearch(c, 1, 4) == false);

  int d[0] = {};
  assert(binarySearch(d, 0, 9) == false);

  return 0;
}