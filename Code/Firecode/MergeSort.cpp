/**
 * Firecode Level 2
 */

// Merge sort (also commonly spelled mergesort) is an O(n log n) comparison-based
// sorting algorithm. Most implementations produce a stable sort, which means that
// the implementation preserves the input order of equal elements in the sorted
// output. Mergesort is a divide and conquer algorithm that was invented by John von
// Neumann in 1945.

// Algorithm Merge-sort-example
// 1. Divide the unsorted list into n sublists, each containing 1 element (a list of
//    1 element is considered sorted).
// 2. Repeatedly merge sublists to produce new sorted sublists until there is only 1
//    sublist remaining. This will be the sorted list.

// Example
// First divide the list into the smallest unit (1 element).
// Then compare each element with the adjacent list to sort and merge the two
// adjacent lists.
// Finally all the elements are sorted and merged.

// The idea behind the classic Mergesort algorithm is to divide an array in half,
// sort each half and then use a merge() function to merge the two halves into a
// single sorted array.

// Implement a merge() function that takes in two sorted arrays and returns a third
// sorted array that contains elements of both the input arrays in the ascending
// order

// You can assume that the input arrays will always be sorted in ascending order and
// can have different sizes.

// Examples:
// merge({2,5,7,8,9},5,{9},1) -> {2,5,7,8,9,9}
// merge({7,8},2,{1,2},2) -> {1,2,7,8}
// merge({2},1,{},0) -> {2}

#include <iostream>

int* merge(int arrLeft[], int szLeft,
           int arrRight[], int szRight)
{
  unsigned int sz = szLeft + szRight;
  int* arr_merged = new int [sz];

  unsigned int i = 0, j = 0, k = 0;

  while (k < sz)
  {
    if (i == szLeft) arr_merged[k++] = arrRight[j++];

    else if (j == szRight) arr_merged[k++] = arrLeft[i++];

    else if (arrLeft[i] <= arrRight[j]) arr_merged[k++] = arrLeft[i++];

    else arr_merged[k++] = arrRight[j++];
  }

  return arr_merged;
}

int main()
{
  int a[5] = {2,5,7,8,9};
  int b[1] = {9};
  int* arr = merge(a, 5, b, 1);
  for (unsigned int i = 0; i < 6; ++i)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  delete arr;
  return 0;
}
