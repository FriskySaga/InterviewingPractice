/*
    Kevin Tran
    Codefights Interview Practice Problem with Arrays
    sudoku2
*/

// Converts a character digit to its equivalent digit in integer form.
int convertToInt(char c) {
    return (int)c - 48;
}

/* PROBLEM STATEMENT

Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 grid with
numbers in such a way that each column, each row, and each of the nine 3 × 3
sub-grids that compose the grid all contain all of the numbers from 1 to 9 one time.

Implement an algorithm that will check whether the given grid of numbers represents
a valid Sudoku puzzle according to the layout rules described above.
Note that the puzzle represented by grid does not have to be solvable.

============
Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.array.char grid

A 9 × 9 array of characters, in which each character is either a digit from '1' to '9' or a period '.'.

[output] boolean

Return true if grid represents a valid Sudoku puzzle, otherwise return false.

*/
bool sudoku2(std::vector<std::vector<char>> grid) {
    // Declare frequency arrays for both rows and columns.
    // The number of rows represents the actual row, column, or subgrid.
    // The number of columns represent the counter for the digit.
    int freqRow[9][10] = {0};
    int freqCol[9][10] = {0};
    int freqSubGrid[9][10] = {0};
    int subGridCounter = 0;

    // Loop through each 3 x 3 sub-grid.
    for (int row = 0; row < 9; row += 3) {
        for (int col = 0; col < 9; col += 3) {

            // Loop within the given subgrid.
            for (int i = row; i < row + 3; i++) {
                for (int j = col; j < col + 3; j++) {
                    // Count the number of occurrences of each number in each row and column.
                    if (isdigit(grid[i][j])) {
                        int n = convertToInt(grid[i][j]);
                        ++freqRow[i][n];
                        ++freqCol[j][n];
                        ++freqSubGrid[subGridCounter][n];
                        printf("%c: %d, %d, %d, %d\n", grid[i][j], i, j, subGridCounter, n);
                    }
                }
            }

            // Move to the next subgrid.
            subGridCounter++;
        }
    }

    // Loop through each frequency array to check for no more than one occurrence of each digit in each row, column, and subgrid.
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10; j++) {
            if (freqRow[i][j] > 1 || freqCol[i][j] > 1 || freqSubGrid[i][j] > 1) {
                printf("False: %d %d %d, %d %d\n", freqRow[i][j], freqCol[i][j], freqSubGrid[i][j], i, j);
                return false;
            }
        }
    }

    // If we've made it this far, that means this must be a valid sudoku grid... probably.
    return true;
}
