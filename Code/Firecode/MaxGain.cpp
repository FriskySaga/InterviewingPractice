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

int maxGain(int arr[], int sz)
{
  int min = 0, maxGain = 0;

  if (sz > 1)
  {
    min = arr[0];
  }

  for (int i = 1; i < sz; ++i)
  {
    if (arr[i] < min)
    {
      min = arr[i];
    }
    else if (arr[i] - min > maxGain)
    {
      maxGain = arr[i] - min;
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

  int f[6] = {4, 25, 5, 10, 26, -90};
  assert(maxGain(f, 6) == 22);

  int g[5] = {0, 50, 10, 100, 30};
  assert(maxGain(g, 5) == 100);

  return 0;
}