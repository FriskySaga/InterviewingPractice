/**
 * Functional test for DSA
 */

#include "DSA.h"

int arrayZero[0] = {};
int arrayOne[1] = {1};
int arrayEvenSortedA[EVEN_SIZE] = {2, 8, 17, 18};
int arrayOddSortedA[ODD_SIZE] = {4, 7, 9, 11, 15};

bool success;

void testBinarySearch(void)
{
  printf("\n******************** BINARY SEARCH ********************\n");

  // Binary search for even-sized arrays
  printf("\nExpect SUCCESS for a successful lookup in an even-sized array "
         "using binary search.\n       ");
  success = binarySearch(arrayEvenSortedA, EVEN_SIZE, 17);
  fputs(success ? "SUCCESS\n" : "FAIL\n", stdout);

  printf("\nExpect FAIL for an invalid lookup in an even-sized array "
         "using binary search.\n       ");
  success = binarySearch(arrayEvenSortedA, EVEN_SIZE, 19);
  fputs(success ? "SUCCESS\n" : "FAIL\n", stdout);

  // Binary search for odd-sized arrays
  printf("\nExpect SUCCESS for a successful lookup in an odd-sized array "
         "using binary search.\n       ");
  success = binarySearch(arrayOddSortedA, ODD_SIZE, 4);
  fputs(success ? "SUCCESS\n" : "FAIL\n", stdout);

  printf("\nExpect FAIL for an invalid lookup in an odd-sized array "
         "using binary search.\n       ");
  success = binarySearch(arrayOddSortedA, ODD_SIZE, 6);
  fputs(success ? "SUCCESS\n" : "FAIL\n", stdout);

  // Binary search for edge-case arrays
  printf("\nExpect FAIL for searching an empty array "
         "using binary search.\n       ");
  success = binarySearch(arrayZero, 0, 12);
  fputs(success ? "SUCCESS\n" : "FAIL\n", stdout);

  printf("\nExpect SUCCESS for a successful lookup in a one-sized array "
         "using binary search.\n       ");
  success = binarySearch(arrayOne, 1, 1);
  fputs(success ? "SUCCESS\n" : "FAIL\n", stdout);
}

