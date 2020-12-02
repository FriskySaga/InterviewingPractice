/**
 * Count Paths on a Game Board
 * Twitter
 * Firecode - Level 3
 */

// You're given a game board that has m x n squares on it,
// represented by an m x n array.
// Write a method - count_paths that takes in m and n and returns the number
// of possible paths from the top left corner to the bottom right corner.
// Only down and right directions of movement are permitted.

// Note: Your method should output the result in a reasonable amount of time for
// large values of m and n. If you're thinking of using DFS, consider the tree depth
// and branching factor for m and n > 15!

// m = number of rows, n = number of columns

// Example:  
// countPaths(m = 2, n = 2) => 2

// As on the following 2x2 Board, the two paths are A->C->D and A->B->D

// A B
// C D

#include <cassert>
#include <iostream>

// Exponential time complexity
int countPaths(int rows, int cols)
{
  if (rows == 1 || cols == 1) return 1;
  else return countPaths(rows-1, cols) + countPaths(rows, cols-1);
}

int main()
{
  assert(countPaths(2,2) == 2);
  return 0;
}