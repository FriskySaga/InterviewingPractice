// Kevin Tran
// Spring 2016
// COP 3502C, Section 0002
// Program #1: Su-Do-Kode

#include <stdio.h>
#include <stdbool.h>

// These constants cannot be changed.
#define DIMENSIONS 9
#define SUBGRID_DIMENSIONS 3

bool is_valid_constants(void);
void get_solution(char solution[DIMENSIONS+1][DIMENSIONS+1]);
bool check_rows(char grid[DIMENSIONS+1][DIMENSIONS+1]);
bool check_columns(char grid[DIMENSIONS+1][DIMENSIONS+1]);
bool check_subgrids(char grid[DIMENSIONS+1][DIMENSIONS+1]);
bool check_subgrid(char grid[DIMENSIONS+1][DIMENSIONS+1], int startRow, int startCol);

// Output "NO" to indicate an invalid sudoku solution.
// Output "YES" to indicate a valid sudoku solution.
int main(void) {
    //Check that the constant values are suitable.
    if (!is_valid_constants()) {
        printf("Please assign these values to these constants:\n DIMENSIONS 9\n SUBGRID_DIMENSIONS 3");
        return -1;
    }

    // Determine the number of solutions to process.
    size_t numSolutions;
    scanf("%d", &numSolutions);

    // Check each solution for validity.
    for(size_t i = 0; i < numSolutions; i++) {
        char solution[DIMENSIONS+1][DIMENSIONS+1];

        // Store each solution in a 2D character array.
        get_solution(solution);

        // Check rows.
        if (!check_rows(solution)) {
            printf("NO\n");
            continue;
        }

        // Check columns.
        if (!check_columns(solution)) {
            printf("NO\n");
            continue;
        }

        // Check subgrids.
        if (!check_subgrids(solution)) {
            printf("NO\n");
            continue;
        }

        // If we've made it this far, indicate that the solution has passed all of the above tests.
        printf("YES\n");
    }

    return 0;
}

// Store the solution data from the input file into the passed 2D character array.
void get_solution(char solution[DIMENSIONS+1][DIMENSIONS+1]) {
    for (size_t row = 0; row < DIMENSIONS; row++) {
        //Read in each digit as a character. Store the ASCII value of each row character.
        scanf("%s", solution[row]);

        //Convert each ASCII character to an integer value.
        for (size_t col = 0; col < DIMENSIONS; col++) solution[row][col] -= '0';
    }
}

// Return true if all digits appear exactly once in each row.
bool check_rows(char grid[DIMENSIONS+1][DIMENSIONS+1]) {
    // This is a frequency array to keep track whether a digit has been seen.
    bool seen[DIMENSIONS+1];

    // Loop through all rows.
    for (size_t row = 0; row < DIMENSIONS; row++) {
        // Initialize the array before searching each row.
        for (size_t i = 0; i <= DIMENSIONS; i++) seen[i] = false;

        // Check each digit from left to right
        for (size_t col = 0; col < DIMENSIONS; col++) {
            // Return false if a repeating digit is found.
            if (seen[grid[row][col]]) return false;

            // Otherwise, mark each digit that has been seen.
            seen[grid[row][col]] = true;
        }
    }

    // If we've made it this far, indicate that the row is valid.
    return true;
}

// Return true if all digits appear exactly once in each column.
bool check_columns(char grid[DIMENSIONS+1][DIMENSIONS+1]) {
    // This is a frequency array to keep track whether a digit has been seen.
    bool seen[DIMENSIONS+1];

    // Loop through all columns.
    for (size_t col = 0; col < DIMENSIONS; col++) {
        // Initialize the array before searching each column.
        for (size_t i = 0; i <= DIMENSIONS; i++) seen[i] = false;

        // Check each digit from top to bottom.
        for (size_t row = 0; row < DIMENSIONS; row++) {
            // Return false if a repeating digit is found.
            if (seen[grid[row][col]]) return false;

            // Otherwise, mark each digit that has been seen.
            seen[grid[row][col]] = true;
        }
    }

    // If we've made it this far, indicate that the row is valid.
    return true;
}

// Separate each subgrid, and return false if any subgrid is invalid.
bool check_subgrids(char grid[DIMENSIONS+1][DIMENSIONS+1]) {
    for (size_t row = 0; row < DIMENSIONS; row += SUBGRID_DIMENSIONS)
        for (size_t col = 0; col < DIMENSIONS; col += SUBGRID_DIMENSIONS)
            if (!check_subgrid(grid, row, col)) return false;
    return true;
}

// Check the given subgrid to see if a digit appears more than once. If so, return false.
bool check_subgrid(char grid[DIMENSIONS+1][DIMENSIONS+1], int startRow, int startCol) {
    // This is a frequency array to keep track whether a digit has been seen.
    bool seen[DIMENSIONS+1] = {false};

    // Mark digits in the subgrid as seen.
    for (size_t i = startRow; i < startRow+SUBGRID_DIMENSIONS; i++)
        for (size_t j = startCol; j < startCol+SUBGRID_DIMENSIONS; j++)
            seen[grid[i][j]] = true;

    // Any digit from 1-9 that is not seen indicates that the subgrid was not well-formed.
    for (size_t i = 1; i <= DIMENSIONS; i++)
        if (!seen[i]) return false;

    // If we've made it this far, indicate that the subgrid is well-formed.
    return true;
}

// Check that the constant values are suitable in case they were modified.
bool is_valid_constants(void) {
    if (DIMENSIONS == 9 && SUBGRID_DIMENSIONS == 3) return true;
    else return false;
}
