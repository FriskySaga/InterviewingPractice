// Kevin Tran
// February 03, 2018
// Find pairs in an integer array whose sum is equal to a certain positive value.
// This algorithm's runtime is O(n+m) for which n is the size of the given integer array
// and m is the range of the values within the given integer array.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 6
#define MIN_RANGE 0
#define MAX_RANGE 10
#define SUM_VALUE 10

// Describe the purpose of this program.
void describe_program (void) {
    printf("\nThis program will generate a random integer array with %d elements ranging from %d through %d."
           " Then this program will find all pairs of integers in this array whose sum is %d.\n", ARRAY_SIZE, MIN_RANGE, MAX_RANGE, SUM_VALUE);
}

// Find all pairs that sum to SUM_VALUE in O(n+m) runtime.
void find_pairs(int array[]) {

    // Make a frequency array that marks whether a value in our original array exists.
    int hasPair = 0;
    int freq[MAX_RANGE+1] = {0};
    for (int i = 0; i < ARRAY_SIZE; i++) {
        freq[array[i]]++;
    }

    // Search through the frequency array for pairs that sum to SUM_VALUE.
    for (int i = 0; i < MAX_RANGE+1; i++) {
        if (freq[i] > 0 && freq[MAX_RANGE-i] > 0) {

            // If I'm pairing the midpoint, I have to make sure at least two instances of that midpoint exist.
            if (i+i == SUM_VALUE) {
                if (freq[i] > 1) {
                    hasPair++;
                    printf("\n(%d, %d)", i, MAX_RANGE-i);
                }
                else {
                    continue;
                }
            }
            // But otherwise, if it's not the midpoint, then print the chosen pair.
            else {
                hasPair++;
                printf("\n(%d, %d)", i, MAX_RANGE-i);
            }
        }
    }

    // If no pairs were found, indicate as such.
    if (hasPair == 0) {
        printf("\nNo pairs were found.");
    }
}

// Given an empty array, fill it with random integers.
void make_array(int array[]) {

    // Seed the random number generator.
    srand(time(0));

    // Fill the array with random integers from MIN_RANGE through MAX_RANGE.
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = MIN_RANGE + rand() % (MAX_RANGE+1);
    }
}

// Show the given array.
void print_array(int array[]) {
    printf("\nHere is the array:\n  [");
    for (int i = 0; i < ARRAY_SIZE-1; i++) {
        printf("%d ", array[i]);
    }
    printf("%d]\n", array[ARRAY_SIZE-1]);
}

int main(void) {

    // Explain the purpose of this program.
    describe_program();

    // Generate a random integer array.
    int array[ARRAY_SIZE];
    make_array(array);

    // Show the unsorted array.
    print_array(array);

    // Look for all pairs that sum up to SUM_VALUE in O(n+m) runtime.
    find_pairs(array);

    // Wrap up the program.
    printf("\n\nHit Enter to stop the program...\n");
    getchar();

    return 0;
}
