/**
 * Firecode Level 2
 * 
 * Given an array of integers, write a method that returns the maximum gain.
 * Maximum Gain is defined as the maximum difference between 2 elements in a list
 * such that the larger element appears after the smaller element.
 * If no gain is possible, return 0.
 */

#include <cassert>
#include <iostream>

using namespace std;

// Computes the maximum gain for adjacent numbers
int maxGainAdjacent(int arr[], int sz)
{
  int maxGain = 0;
  for (int i = 1; i < sz; ++i)
  {
    int diff = arr[i] - arr[i-1];
    if (diff > maxGain)
    {
      maxGain = diff;
    }
  }

  return maxGain;
}

int maxGain(int arr[], int sz)
{
  return 0;
}

int main()
{
  int a[0];
  assert(maxGain(a, 0) == 0);

  int b[1] = {5};
  assert(maxGain(b, 1) == 0);

  int c[2] = {2,1};
  assert(maxGain(c, 2) == 0);

  int d[2] = {1,2};
  assert(maxGain(d,2) == 1);

  int e[3] = {-1,0,2};
  assert(maxGain(e, 3) == 2);

  int f[6] = {4, 25, 5, 10, 26, -90};
  assert(maxGain(f, 6) == 21);

  int g[5] = {0, 50, 10, 100, 30};
  assert(maxGain(g, 5) == 100);

  return 0;
}
