// Kevin Tran
// Program started on: March 02, 2018
// Program revisited on: September 03, 2018
// Provide an example of two valid matrices being multiplied.
// This is a little hard-coded, but I wanted to quickly knock out this program
// after having put this on the backlog for so long due to school.

#include <stdio.h>
#define M_DIM 3
#define N_DIM 2

void multiply_matrix(int a[M_DIM][N_DIM], int b[N_DIM][N_DIM], int c[M_DIM][N_DIM]) {
    for (int i = 0; i < M_DIM; i++) {
        for (int j = 0; j < N_DIM; j++) {
            c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
        }
    }
}

void print_matrix(int matrix[M_DIM][N_DIM], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    int A[M_DIM][N_DIM] = {
      {8, 3},
      {6, 4},
      {5, 11},
    };
    print_matrix(A, M_DIM, N_DIM);

    int B[N_DIM][N_DIM] = {
      {12, 7},
      {9, 8}
    };
    print_matrix(B, N_DIM, N_DIM);

    int C[M_DIM][N_DIM];
    multiply_matrix(A, B, C);
    print_matrix(C, M_DIM, N_DIM);

    return 0;
}

