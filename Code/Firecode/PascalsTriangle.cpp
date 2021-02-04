/**
 * Firecode - Level 5
 */

#include <vector>


// Given an input parameter num_rows, generate the first num_rows number of rows of
// Pascal's triangle. As a quick refresher - in a Pascal's triangle, each number is
// equal to the sum of the two directly above it.

// Example:
// Input  : 4  
// Output : 
//         [
//              [1],
//             [1,1],
//            [1,2,1],
//           [1,3,3,1]
         
//         ]

std::vector<std::vector<int>> generate_pascal_triangle(int num_rows) 
{
  std::vector<std::vector<int>> pascalsTriangle;

  for (int i = 0; i < num_rows; i++)
  {
    std::vector<int> row = {1};
    int prev = 1;
    for(int k = 1; k <= i; k++)
    {
      int result = (prev * (i + 1 - k)) / k;
      prev = result;
      row.push_back(result);
    }
    pascalsTriangle.push_back(row);
  }
  
  return pascalsTriangle;
}
