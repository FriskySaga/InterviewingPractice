/**
 * Implement all algorithms and data structures in C.
 */

#include "DSA.h"

int binarySearch(int array[], int arraySize, int value)
{
  int low = 0, high = arraySize - 1;

  // (low < high) would fail a valid match in an array of size 1
  // (low < high) would fail a valid match on the last index of any array
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (value < array[mid])
      high = mid - 1;

    else if (value > array[mid])
      low = mid + 1;

    else
      return true;
  }

  return false;
}

int main(void)
{
  testBinarySearch();
  return 0;
}
