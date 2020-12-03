/**
 * Find duplicates in array
 * Amazon
 * Firecode Level 3
 */

// Write a function to find the redundant or repeated elements in an array.
// Save the set of redundant numbers in the given output array in ascending order.
// If no element is repeated return NULL

// Examples:
// remove_dup({3,1,2,4,1}, 5) ==> {1}
// remove_dup({1,2,4,4,5,6,2,1}, 8) ==> {1,2,4}

#include <iostream>
#include <unordered_map>

// NOTE Poorly named function, but this is what Firecode calls it
int* remove_dup(int A[], int sz)
{
  // NOTE Ideally we should be using a set :P
  int* output = nullptr;

  std::unordered_map<int, unsigned int> hm;
  unsigned int numDupes = 0;
  for (int i = 0; i < sz; ++i)
  {
    ++hm[A[i]];
    if (hm.at(A[i]) == 2) ++numDupes;
  }

  if (numDupes == 0) return nullptr;
  output = new int[numDupes];
  unsigned int idx = 0;
  for (const auto& x : hm)
    if (x.second > 1)
      output[idx++] = x.first;

  // Print output since we can't use cassert
  for (unsigned int i = 0; i < numDupes; ++i)
    std::cout << output[i] << " ";
  std::cout << std::endl;

  return output;
}

int main()
{
  int a[5] = {3,1,2,4,1};
  int b[1] = {1};
  int c[8] = {1,2,4,4,5,6,2,1};
  int d[3] = {1,2,4};
  int* ans1 = remove_dup(a, 5);
  int* ans2 = remove_dup(c, 8);
  delete ans1;
  delete ans2;

  return 0;
}