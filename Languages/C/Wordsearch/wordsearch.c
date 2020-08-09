/*
    Kevin Tran
    May 27, 2019
    CS1 Program 2 (Spring 2016 with Arup Guha)

    Solve word search puzzles.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DICTIONARY_FILE "dictionary.txt"

const int DX_SIZE = 8;
const int DX[] = {-1, -1, -1,  0, 0,  1, 1, 1};
const int DY[] = {-1,  0,  1, -1, 1, -1, 0, 1};
const int NUM_DIRECTIONS = 8;

const int MIN_WORD_LENGTH = 4;
const int MAX_WORD_LENGTH = 19;

// Load the dictionary from a text file.
// @param filename - String representing storing name of text file containing dictionary
// @param dictionary_size - Integer indicating number of words inside dictionary
// @return dictionary - 2D character array holding the dictionary of words
char **load_dictionary(char filename[], int *dictionary_size) {
    FILE *ifp = fopen(filename, "r");
    fscanf(ifp, "%d", dictionary_size);
    char **dictionary = (char **) malloc(sizeof(char *) * *dictionary_size);
    for (int i = 0; i < *dictionary_size; i++) {
        dictionary[i] = (char *) malloc(sizeof(char) * (MAX_WORD_LENGTH + 1));
        fscanf(ifp, "%s", dictionary[i]);
    }
    fclose(ifp);
    return dictionary;
}

// Free the memory of the dictionary
// @param dictionary - 2D character array holding the dictionary of words
// @param dictionary_size - Integer indicating number of words inside dictionary
void free_dictionary(char **dictionary, int dictionary_size) {
    for (int i = 0; i < dictionary_size; i++) {
        free(dictionary[i]);
    }
    free(dictionary);
}

// Use binary search to determine if a given word is inside the dictionary
// @param dictionary - 2D character array holding the dictionary of words
// @param dictionary_size - Integer indicating number of words inside dictionary
// @param word - String representing word to search for
// @param word_length - Integer representing the desired length of the sequence of letters to grab
// @return True if the word is inside the dictionary; False otherwise
int is_valid_word(char **dictionary, int dictionary_size, char word[], int word_length) {
    int low = 0, high = dictionary_size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int strnCmpRes = strncmp(word, dictionary[mid], word_length + 1);
        if (strnCmpRes < 0) {
            // first string comes first
            high = mid - 1;
        } else if (strnCmpRes > 0) {
            // first string comes second
            low = mid + 1;
        } else {
            return 1;
        }
    }
    return 0;
}

// Check whether row and column are inbounds of the grid
// @param row - Integer indicating current row
// @param col - Integer indicating current column
// @param numRows - Integer indicating number of rows
// @param numCols - Integer indicating number of columns
// @return 1 iff row and column are inbounds; 0 otherwise
int is_inbounds(int row, int col, int numRows, int numCols) {
    return row >= 0 && col >= 0 && row < numRows && col < numCols;
}

// Get a sequence of length letters in the grid
// @param grid - 2D character representing a wordsearch puzzle
// @param start_row - Integer indicating the row of the first letter to search from
// @param start_col - Integer indicating the column of the first letter to search from
// @param direction - Integer representing index in DX/DY arrays to indicate direction to search in
// @param word_length - Integer representing the desired length of the sequence of letters to grab
// @param numRows - Integer indicating the number of rows in grid
// @param numCols - Integer indicating the number of columns in grid
char *get_word(char **grid, int start_row, int start_col, int direction,
               int word_length, int numRows, int numCols) {

    // Check whether the farther index from the start is inbounds
    // For direction 0, a hypothetical example could be:
    // grid[0 + ((19 - 1) * -1)][0 + ((19 - 1 * -1))]
    // grid[-18][-18]
    if (!is_inbounds(start_row + (word_length - 1) * DX[direction],
                     start_col + (word_length - 1) * DY[direction],
                     numRows, numCols)) {
        return NULL;
    }

    // Take each letter from the starting index in the indicated direction
    // until the word length requirement has been satisfied
    char *word = (char *) malloc(sizeof(char) * (word_length + 1));
    for (int i = 0; i < word_length; i++) {
        word[i] = grid[start_row + i * DX[direction]]
                      [start_col + i * DY[direction]];
    }
    word[word_length] = '\0';
    return word;
}

// Solve a particular given wordsearch puzzle
// @param dictionary - 2D character array holding the dictionary of words
// @param dictionary_size - Integer indicating number of words inside dictionary
// @param grid - 2D character representing a wordsearch puzzle
// @param numRows - Integer indicating the number of rows in grid
// @param numCols - Integer indicating the number of columns in grid
void solve(char **dictionary, int dictionary_size, char **grid, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            for (int k = 0; k < NUM_DIRECTIONS; k++) {
                for (int l = MIN_WORD_LENGTH; l <= MAX_WORD_LENGTH; l++) {
                    char *word_to_try = get_word(grid, i, j, k, l, numRows, numCols);

                    if (word_to_try != NULL) {
                        if (is_valid_word(dictionary, dictionary_size, word_to_try, l)) {
                            printf("%s\n", word_to_try);
                        }
                    }
                    free(word_to_try);
                }
            }
        }
    }
}

// Solve all the given wordsearch puzzles
// @param dictionary - 2D character array holding the dictionary of words
// @param dictionary_size - Integer indicating number of words inside dictionary
// @param filename - String representing storing name of text file containing wordsearch puzzles
void solve_wordsearch_puzzles(char **dictionary, int dictionary_size, char filename[]) {
    FILE *ifp = fopen(filename, "r");
    int numPuzzles, numRows, numCols;
    fscanf(ifp, "%d", &numPuzzles);
    for (int n = 0; n < numPuzzles; n++) {
        fscanf(ifp, "%d%d", &numRows, &numCols);
        char **grid = (char **) calloc(numRows, sizeof(char *));
        for (int r = 0; r < numRows; r++) {
            grid[r] = (char *) calloc(numCols + 1, sizeof(char));
            fscanf(ifp, "%s", grid[r]);
        }
        printf("\nWords Found Grid #%d:\n", n+1);
        solve(dictionary, dictionary_size, grid, numRows, numCols);

        // Clean up
        for (int r = 0; r < numRows; r++) {
            free(grid[r]);
        }
        free(grid);
    }
    fclose(ifp);
}

int main(int argc, char **argv) {
    int dictionary_size = 0;
    char **dictionary = load_dictionary(DICTIONARY_FILE, &dictionary_size);
    solve_wordsearch_puzzles(dictionary, dictionary_size, argv[1]);
    free_dictionary(dictionary, dictionary_size);
    return 0;
}
