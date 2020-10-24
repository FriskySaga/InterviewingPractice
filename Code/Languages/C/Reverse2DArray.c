// Kevin Tran
// January 19, 2018
// Reverse the order of the elements in an array.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDE_LENGTH 5

// Close the program after execution.
void close_program (void) {
    printf("\n\nHit Enter to stop the program...\n");
    getchar();
}

// Describe the purpose of this program.
void describe_program (void) {
    printf("\nThis program will generate a random 2D array with 25 elements."
           " Then this program will reverse the order of the 25 elements.\n");
}

// Given an empty 2D array, fill it with random integers.
void make_array(int array[SIDE_LENGTH][SIDE_LENGTH]) {
    // Seed the random number generator.
    srand(time(0));

    // Fill the array with random integers.
    for (int i = 0; i < SIDE_LENGTH; i++) {
        for (int j = 0; j < SIDE_LENGTH; j++) {
            array[i][j] = rand();
        }
    }
}

// Show the given 2Darray.
void print_array(int array[SIDE_LENGTH][SIDE_LENGTH]) {
    printf("\n\nHere is the array:\n");
    for (int i = 0; i < SIDE_LENGTH; i++) {
        printf("\n ");
        for (int j = 0; j < SIDE_LENGTH; j++) {
            printf(" %d", array[i][j]);
        }
    }
}

// Reverse the order of the indices in the given 2D array.
void reverse_array(int array[SIDE_LENGTH][SIDE_LENGTH]) {
    for (int i = 0, rp = SIDE_LENGTH-1; i <= rp; i++, rp--) {
        for (int j = 0, cp = SIDE_LENGTH-1; j < SIDE_LENGTH; j++, cp--) {
            // Prevent double swapping in the middle row.
            if (i == rp && j == cp) {
                break;
            }

            // Swap the next first element and the next last element.
            int temp = array[i][j];
            array[i][j] = array[rp][cp];
            array[rp][cp] = temp;
        }
    }
}

int main(void) {
    // Describe the purpose of this program.
    describe_program();

    // Make an array with random integers.
    int array[SIDE_LENGTH][SIDE_LENGTH];
    make_array(array);
    print_array(array);

    // Reverse the order of the array. O((n^2)/2)
    reverse_array(array);

    // Print the new array.
    print_array(array);

    // Wrap up the program.
    close_program();

    return 0;
}
