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

// WARN: Computes the maximum gain for adjacent numbers
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

// O(n^2) solution
int maxGainN2(int arr[], int sz)
{
  int maxGain = 0;
  for (int i = 0; i < sz; ++i)
  {
    for (int j = 0; j < sz; ++j)
    {
      if (j > i)
      {
        int diff = arr[j] - arr[i];
        if (diff > maxGain)
        {
          maxGain = diff;
        }
      }
    }
  }
  return maxGain;
}

// O(n) solution
int maxGain(int arr[], int sz)
{
  if (sz <= 1) return 0;

  int minVal = arr[0];
  int maxGain = 0;

  for (int i = 1; i < sz; ++i)
  {
    if (arr[i] < minVal) minVal = arr[i];
    else
    {
      int diff = arr[i] - minVal;
      if (diff > maxGain) maxGain = diff;
    }
  }

  return maxGain;
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
  assert(maxGain(e, 3) == 3);

  int f[6] = {25, 5, 4, 10, 26, -90};
  assert(maxGain(f, 6) == 22);

  int g[5] = {50, 0, 10, 100, 30};
  assert(maxGain(g, 5) == 100);

  // Max gain is 99 even though 0 is the new minimum
  // because the only available max gain after is 10.
  int h[4] = {1, 100, 0, 10};
  assert(maxGain(h, 4) == 99);

  // Max gain is 110
  int i[4] = {1, 100, 0, 110};
  assert(maxGain(i, 4) == 110);

  return 0;
}
