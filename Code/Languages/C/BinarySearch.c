// Kevin Tran
// January 20, 2018
// Reverse the order of the elements in an array.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ARRAY_SIZE 31

// Using binary search, look through the sorted array for 'val'.
// Return 1 to indicate that we've found the value, else return -1.
int binary_search(int array[], int val) {

    // Indicate start and ending indices.
    int low = 0, high = ARRAY_SIZE-1;

    // Search until low and high cross past each other.
    /*
        1 - You would like to search 1 in the list [1]. In that case, start = 0, end = 0 and the algorithm would return -1 if you had the < operator.

        2 - You would like to search 2 in the list [1, 2]. In that case, start = 0, end = 1. The algorithm will set mid = (0+1)/2=0 in C.
            Thus arr[mid] < key. It will make start = 1, end = 1. Again, if you stop the loop here, the algorithm will return -1 instead of 1.
    */
    while (low <= high) {
        int mid = (low + high) / 2;

        // Confine the search area by one-half after each comparison.
        if (val < array[mid]) {
            high = mid - 1;
        }
        else if (val > array[mid]) {
            low = mid + 1;
        }
        else {
            return 1;
        }
    }

    // If we've made it here, that means the value does not exist.
    return -1;
}

// Close the program after execution.
void close_program (void) {
    printf("\nHit Enter to stop the program...\n");
    getchar();
    getchar();
}

// Check if the user's number is within the 0 through 50 range.
int check_range(int number) {
    if (number >= 0 && number <= 50) return 1;
    else return -1;
}

// Check if the user's number is an integer.
int check_type(int number) {
    if (number == floor(number)) return 1;
    else return -1;
}

// Check the user's input to see if it is an integer that is within the 0 through 50 range.
int check_user(int input) {
    if (check_type(input) == 1 && check_range(input) == 1)
        return 1;
    else return -1;
}

// Describe the purpose of this program.
void describe_program (void) {
    printf("\nThis program will generate a random integer array with 31 elements ranging from 0 to 50."
           " Then, this program will ask the user for an integer they would like to search for.\n"
           " This program will tell the user if the integer exists in this array.\n");
}

// Get an integer from the user to search for within the array.
int get_value(void) {
    int num;
    printf("\nWhich integer from 0 through 50 would you like to search for? ");
    scanf("%d", &num);

    // Check if the user gave a valid integer.
    int isValid = 0;
    do {
        isValid = check_user(num);
    } while (isValid == -1);

    return num;
}

// Given an empty array, fill it with random integers.
void make_array(int array[]) {

    // Seed the random number generator.
    srand(time(0));

    // Fill the array with random integers from 0 through 50.
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 51;
    }
}

// Given an array, its start, it mid, and its last indices, sort the array.
void merge(int array[], int start, int mid, int end) {

    // Allocate the proper amount of space for our auxiliary array.
    int *temp = (int*) calloc(ARRAY_SIZE, sizeof(int));

    // These will be our indexes into our two sorted lists.
    int count1 = start;
    int count2 = mid;

    // Keeps track of our index into our auxiliary array.
    int ax = 0;

    // Here we copy values into our auxiliary array, so long as there are
    // numbers from both lists to copy.
    while ((count1 < mid) || (count2 <= end)) {

        // Next value to copy comes from list one - make sure list
        // one isn't exhausted yet. Also make sure we don't access index
        // count2 if we aren't supposed to.
        if (count2 > end || (count1 < mid && array[count1] < array[count2])) {
            temp[ax] = array[count1];
            count1++;
            ax++;
        }

        // We copy the next value from list two.
        else {
            temp[ax] = array[count2];
            count2++;
            ax++;
        }
    }

    // Copy back all of our values into the original array.
    for (int i = start; i <= end; i++)
        array[i] = temp[i - start];

    // Don't need this space any more!
    free(temp);
}

// Given the start and end indices, merge sort the given array.
void merge_sort(int array[], int start, int end) {
    // Check if the sorting range is more than one element.
    if (start < end) {
        int mid = (start + end) / 2;

        // Split the first half.
        merge_sort(array, start, mid);

        // Split the second half.
        merge_sort(array, mid+1, end);

        // Put them all together.
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

// Tell the user whether the integer was found.
void tell_user(int result) {
    if (result == 1) printf("\nGood guessing! Your number does exist in the array!\n");
    else printf("\nBetter luck next time! Your number was not found!\n");
}

int main(void) {

    // Describe the purpose of this program.
    describe_program();

    // Make an array with random integers.
    int array[ARRAY_SIZE];
    make_array(array);

    // Sort the array in O(n log n) runtime. Provide the start and ending indices.
    merge_sort(array, 0, ARRAY_SIZE-1);

    // Show the sorted array.
    print_array(array);

    // Ask the user for an integer to search for.
    int searchVal = get_value();

    // Search for the value using binary search in O(log n) runtime.
    int found = binary_search(array, searchVal);

    // Tell the user the result.
    tell_user(found);

    // Wrap up the program.
    close_program();

    return 0;
}

