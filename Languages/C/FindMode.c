// Kevin Tran
// November 04, 2017
// Find the most frequent integer(s) in an array.
// Big-Oh(n), Big-Theta(n), Big-Omega(n)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 25
#define MAX_NUM 10

// Given a full integer array, find and return the mode.
int find_mode(int array[], int *maxCount) {
    // Use a frequency array to tally the number of occurrences of each integer.
    int freq[MAX_NUM] = {0};
    for (int i = 0; i < ARRAY_SIZE; i++)
        freq[array[i]]++;

    // Look through the frequency array, and mark the index with the highest
    // number of occurrences.
    int mode;
    for (int i = 0; i < MAX_NUM; i++) {
        if (freq[i] >= *maxCount) {
            *maxCount = freq[i];
            mode = i;
        }
    }
    return mode;
}

// Given an empty array, fill it up with random integers from 0 through 9.
// Return the pointer to the array.
int *make_array(int array[]) {
    // Seed the random number generator.
    srand(time(0));

    // Fill the array with random integers from 0 through MAX_NUM-1.
    for (int i = 0; i < ARRAY_SIZE; i++) array[i] = rand() % MAX_NUM;

    return array;
}

// Print the given array.
void print_array(int array[]) {
    printf("\nHere is the array:\n  [");
    for (int i = 0; i < ARRAY_SIZE-1; i++)
        printf("%d, ", array[i]);
    printf("%d]\n", array[ARRAY_SIZE-1]);
}

int main(void) {
    // Describe the purpose of this program.
    printf("\nThis program will find the most frequently occurring integer in"
           " any given array.\n");

    // Make an array with random integers from 0 through 9.
    int array[ARRAY_SIZE];
    make_array(array);

    // Show the contents of the array to the user.
    print_array(array);

    // Find the mode (i.e., most frequent integer).
    int maxCount = 0;
    int mode = find_mode(array, &maxCount);
    printf("\nThe most frequently occurring integer is %d, which has occurred"
           " %d times.\n", mode, maxCount);

    // Wrap up the program.
    printf("\nHit enter to stop the program...\n");
    getchar();

    return 0;
}
