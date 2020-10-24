/**
 * Diagonal Difference
 * https://www.hackerrank.com/challenges/diagonal-difference/problem
 * Easy Algorithms
 *
 * The primary diagonal is:
 *
 * 11
 *    5
 *      -12
 *
 * Sum across the primary diagonal: 11 + 5 - 12 = 4
 *
 * The secondary diagonal is:
 *
 *      4
 *    5
 * 10
 * 
 * Sum across the secondary diagonal: 4 + 5 + 10 = 19 
 *
 * Difference: |4 - 19| = 15
 */

#include <cassert>
#include <cmath>
#include <vector>

using namespace std;

int diagonalDifference(vector<vector<int>> v)
{
  int leftRightSum = 0U, rightLeftSum = 0U;
  unsigned int rowIndex = 0U, colIndex = 0U;
  unsigned int complementColIndex;
  for (vector<vector<int>>::iterator row = v.begin(); row != v.end(); ++row)
  {
    rowIndex = distance(v.begin(), row);
    complementColIndex = v.size() - 1 - rowIndex;
    for (vector<int>::iterator col = row->begin(); col != row->end(); ++col)
    {
      colIndex = distance(row->begin(), col);
      if (rowIndex == colIndex)
      {
        leftRightSum += *col;
      }
      if (colIndex == complementColIndex)
      {
        rightLeftSum += *col;
      }
    }
  }
  return abs(leftRightSum - rightLeftSum);
}

int main()
{
  vector<vector<int>> v =
  {
    {11, 2, 4},
    {4, 5, 6},
    {10, 8, -12}
  };

  assert (diagonalDifference(v) == 15);
  return 0;
}

