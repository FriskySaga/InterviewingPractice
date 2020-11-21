/**
 * Firecode Level 2
 */

// Write a function that takes in an array of ints and
// uses the Selection Sort algorithm to sort the array 'in place' in ascending order.

// The function should return the same in-place sorted array.

// Note: Selection sort offers improved performance over bubble sort for arrays with large number of elements.
// Where bubble sort accumulated the largest elements towards the end of the array,
// selection sort accumulates the smallest elements at the beginning of the array.

// Examples: 
// selection_sort_array({1,5,2}, 3) -> {1,2,5}
// selection_sort_array({11},1) -> {11}
// selection_sort_array({}, 0) -> {}
// {} -> [Empty] Array 

// Selection Sort is a sorting algorithm, specifically an in-place comparison sort.
// It has O(n2) time complexity, making it inefficient on large lists,
// and generally performs worse than the similar insertion sort.

// Selection sort is noted for its simplicity, and it has performance advantages
// over more complicated algorithms in certain situations,
// particularly where auxiliary memory is limited. 

// The algorithm divides the input list into two parts:
// the sublist of items already sorted, which is built up from left to right at the front (left) of the list,
// and the sublist of items remaining to be sorted that occupy the rest of the list.

// Initially, the sorted sublist is empty and the unsorted sublist is the entire input list.
// The algorithm proceeds by finding the smallest (or largest, depending on sorting order) element in the unsorted sublist,
// exchanging it with the leftmost unsorted element (putting it in sorted order),
// and moving the sublist boundaries one element to the right.

// Example
// Sorted sublist 	     Unsorted sublist
// () 	                 (11, 25, 12, 22, 64)
// (11) 	               (25, 12, 22, 64)
// (11, 12) 	           (25, 22, 64)
// (11, 12, 22) 	       (25, 64)
// (11, 12, 22, 25)    	 (64)
// (11, 12, 22, 25, 64)  ()

// Big-O notation
// Worst case performance 	О(n2)
// Best case performance 	О(n2)
// Average case performance 	О(n2)
// Worst case space complexity 	O(1) 

#include <iostream>

using namespace std;

int* selectionSortArray(int arr[], int size)
{
  int left, right;
  for (int left = 0; left < size-1; ++left)
  {
    int rightMin = left;
    for (right = left+1; right < size; ++right)
    {
      if (arr[right] < arr[rightMin])
      {
        rightMin = right;
      }
    }

    if (rightMin != left)
    {
      swap(arr[left], arr[rightMin]);
    }
  }
  return arr;
}

int main()
{
  int a[5] = {11,25,12,22,64};
  selectionSortArray(a, 5);
  for (int i = 0; i < 5; ++i)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
