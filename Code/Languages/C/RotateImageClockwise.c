// Kevin Tran
// January 19, 2018
// Rotate the pixels of an image 2D array clockwise.

#include <stdio.h>
#include <math.h>

#define S 4

// Close the program after execution.
void close_program (void) {
    printf("\n\nHit Enter to stop the program...\n");
    getchar();
}

// Describe the purpose of this program.
void describe_program (void) {
    printf("\nThis program will show a square 2D array with integer values to represent an imaginary image."
           " Then this program will rotate the imagine image 90 degrees clockwise.\n");
}

// Make a 2D array.
int **make_2D_array(int a[S][S]) {
    int cnt = 0;
    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
            a[i][j] = cnt;
            if (cnt < 9) cnt++;
            else cnt = 0;
        }
    }
}

// Show the given 2D array.
void print_2D_array(int array[S][S]) {
    printf("\n\nHere is the array:\n");
    for (int i = 0; i < S; i++) {
        printf("\n ");
        for (int j = 0; j < S; j++) {
            printf(" %d", array[i][j]);
        }
    }
}

// Rotate the image clockwise.
// Wrote this algorithm based off a series of test cases with 3x3 and 4x4 grids.
void rotate_square_image_clockwise(int image[S][S]) {
    for (int i = 0; i < S / 2; i++) {
        for (int j = 0; j < ceil((float)S / 2.0); j++) {
            int tmp = image[i][j];
            image[i][j] = image[S-1-j][i];
            image[S-1-j][i] = image[S-1-i][S-1-j];
            image[S-1-i][S-1-j] = image[j][S-1-i];
            image[j][S-1-i] = tmp;
        }
    }
}

int main(void) {
    // Describe the purpose of this program.
    describe_program();

    // Make a 2D array to represent an image.
    int image[S][S];
    make_2D_array(image);
    print_2D_array(image);

    // Rotate the image clockwise in O(n^2), or more precisely: O(n^2/4).
    rotate_square_image_clockwise(image);

    // Print the new array.
    print_2D_array(image);

    // Wrap up the program.
    close_program();

    return 0;
}
