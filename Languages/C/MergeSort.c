// Kevin Tran
// January 20, 2018
// Reverse the order of the elements in an array.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ARRAY_SIZE 60

// Close the program after execution.
void close_program (void) {
    printf("\nHit Enter to stop the program...\n");
    getchar();
}

// Describe the purpose of this program.
void describe_program (void) {
    printf("\nThis program will generate a random integer array with 60 elements, ranging from 1 to 99."
           " Then this program will sort all of these elements in O(n log n) runtime with merge sort.\n");
}

// Given an empty array, fill it with random integers.
void make_array(int array[]) {

    // Seed the random number generator.
    srand(time(0));

    // Fill the array with random integers from 0 through 50.
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = 1 + rand() % 100;
    }
}

// Given an array, its start, it mid, and its last indices, sort the array.
void merge(int array[], int start, int mid, int end) {

    // Make an auxiliary array. Keep track of the current index.
    int *aux = (int*) calloc(ARRAY_SIZE, sizeof(int));
    int x = 0;

    // Keep track of our indices in our sorted lists.
    int i = start;
    int j = mid;

    // Copy all values from both lists to the auxiliary array.
    while ((i < mid) || (j <= end)) {

        // As long as there are values from the first list to copy, and if
        // the value from the first list is smaller, put that value into
        // the auxiliary array.
        // Or if there are no more values from the second list, then copy all
        // remaining values from the first list.
        if ((i < mid && array[i] < array[j]) || j > end) {
            aux[x] = array[i];
            i++;
            x++;
        }

        // Otherwise if the value from the second list is smaller, or if
        // there are no more values from the first list to copy, then put the
        // value from the second list into the auxiliary array.
        else {
            aux[x] = array[j];
            j++;
            x++;
        }
    }

    // Copy all values from the auxiliary array into the correct position of
    // the original array.
    // Recall that the auxiliary array starts at index 0.
    // Suppose 'start' = 3, and 'end' = 4.
    // Then, copy the value from aux[3 - 3] to array[3].
    for (int i = start; i <= end; i++)
        array[i] = aux[i - start];

    // We have no need for the auxiliary array anymore.
    free(aux);
}

// Given the start and end indices, merge sort the given array.
void merge_sort(int array[], int start, int end) {
    // Check if the sorting range is more than one element.
    if (start < end) {
        int mid = (start + end) / 2;

        // Split the first half until we have only one element left.
        merge_sort(array, start, mid);

        // Split the second half until we have only one element left.
        merge_sort(array, mid+1, end);

        // Compare the values from the first and second halves.
        merge(array, start, mid+1, end);
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

    // Describe the purpose of this program.
    describe_program();

    // Make an array with random integers.
    int array[ARRAY_SIZE];
    make_array(array);

    // Show the unsorted array.
    print_array(array);

    // Sort the array in O(n log n) runtime. Provide the start and ending indices.
    printf("\nMerge sorting the array...\n");
    merge_sort(array, 0, ARRAY_SIZE-1);

    // Show the sorted array.
    print_array(array);

    // Wrap up the program.
    close_program();

    return 0;
}

