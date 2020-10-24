// Kevin Tran
// January 18, 2018
// Reverse the order of the elements in an array.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVEN_ARRAY_SIZE 6
#define ODD_ARRAY_SIZE 7

// Describe the purpose of this program.
void describe_program (void) {
    printf("\nThis program will generate a random integer array."
           " Then this program will reverse the order of the elements.\n");
}

// End the program after execution.
void end_program (void) {
    printf("\nHit Enter to stop the program...\n");
    getchar();
}

// Given an empty array and its size, fill it with random integers.
void make_array(int array[], int n) {
    // Seed the random number generator.
    srand(time(0));

    // Fill the array with random integers.
    for (int i = 0; i < n; i++) {
        array[i] = rand();
    }
}

// Show the given array.
void print_array(int array[], int n) {
    printf("\nHere is the array:\n  [");
    for (int i = 0; i < n-1; i++) {
        printf("%d ", array[i]);
    }
    printf("%d]\n", array[n-1]);
}

// Reverse the order of the indices in the given array.
void reverse_array(int array[], int n) {
    for (int i = 0, j = n-1; i < j; i++, j--) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main(void) {
    // Describe the purpose of this program.
    describe_program();

    // Make even and odd arrays with random integers.
    int even_array[EVEN_ARRAY_SIZE];
    int odd_array[ODD_ARRAY_SIZE];
    make_array(even_array, EVEN_ARRAY_SIZE);
    make_array(odd_array, ODD_ARRAY_SIZE);
    print_array(even_array, EVEN_ARRAY_SIZE);
    print_array(odd_array, ODD_ARRAY_SIZE);

    // Reverse the order of the array. O(n/2)
    reverse_array(even_array, EVEN_ARRAY_SIZE);
    reverse_array(odd_array, ODD_ARRAY_SIZE);

    // Print the new array.
    print_array(even_array, EVEN_ARRAY_SIZE);
    print_array(odd_array, ODD_ARRAY_SIZE);

    // Wrap up the program.
    end_program();

    return 0;
}
