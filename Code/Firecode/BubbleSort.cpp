/**
 * Firecode Level 2
 */

// Write a function that takes in an array of ints and the size of the array and
// uses the Bubble Sort algorithm to sort the array in ascending order. The function
// should return the same, in-place sorted array.


// Note: Bubble sort is one of the most inefficient ways to sort a large array of
// integers. Nevertheless, it is an interview favorite. Bubble sort has a time
// complexity of O(n2). However, if the sample size is small, bubble sort provides a
// simple implementation of a classic sorting algorithm.

// Examples:

// bubble_sort_array({5,4,3},3) -> {3,4,5} bubble_sort_array({3},1) -> {3}
// bubble_sort_array({},0) -> {}

// Bubble sort, is a simple sorting algorithm that works by repeatedly stepping
// through the list to be sorted, comparing each pair of adjacent items and swapping
// them if they are in the wrong order. The pass through the list is repeated until
// no swaps are needed, which indicates that the list is sorted. The algorithm gets
// its name from the way smaller elements "bubble" to the top of the list. Because
// it only uses comparisons to operate on elements, it is a comparison sort.
// Although the algorithm is simple, most of the other sorting algorithms are more
// efficient for large lists.

// Bubble sort has worst-case and average complexity both О(n2), where n is the
// number of items being sorted. There exist many sorting algorithms with
// substantially better worst-case or average complexity of O(nlog n). Even other
// О(n2) sorting algorithms, such as insertion sort, tend to have better performance
// than bubble sort. Therefore, bubble sort is not a practical sorting algorithm
// when n is large.

// The only significant advantage that bubble sort has over most other
// implementations, even quicksort, but not insertion sort, is that the ability to
// detect that the list is sorted is efficiently built into the algorithm. When the
// list is already sorted (best-case), the complexity of bubble sort is only O(n).
// By contrast, most other algorithms, even those with better average-case
// complexity, perform their entire sorting process on the set and thus are more
// complex. However, not only does insertion sort have this mechanism too, but it
// also performs better on a list that is substantially sorted (having a small
// number of inversions).

// Bubble sort should be avoided in case of large collections. It will not be
// efficient in case of reverse ordered collection.

// From Wikipedia, the free encyclopedia. Big-O notation Worst case performance
// О(n2) Best case performance  O(n) Average case performance   О(n2) Worst case
// space complexity  O(1) 

#include <iostream>

int* bubbleSortArray(int arr[], int size)
{
  bool isSorted = false;
  while (!isSorted)
  {
    isSorted = true;
    for (int i = 0; i < size-1; ++i)
    {
      if (arr[i] > arr[i+1])
      {
        std::swap(arr[i], arr[i+1]);
        isSorted = false;
      }
    }
  }
  return arr;
}

int main()
{
  int a[3] = {5,4,3};
  bubbleSortArray(a, 3);
  for (int i = 0; i < 3; ++i)
  {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}