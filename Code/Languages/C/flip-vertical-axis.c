// 3/6/2020 - Unknown whether this works

#include <stdio.h>

void print_matrix(int matrix[][], int m) {
    for (int i = 0; i < m; i++) {
        printf("%s\n", matrix[i]);
    }
}

void flip_vertical_axis(int matrix[][], int m, int n) {
    printf("\nGiven matrix:\n");
    print_matrix(matrix, m);
}

int main(void) {
    int matrix_2_2[2][2] = [
        [1,0],
        [1,0]
    ]

    int matrix_2_3[2][3] = [
        [1, 2, 3],
        [1, 2, 3]
    ]

    flip_vertical_axis(matrix_2_2, 2, 2)
    flip_vertical_axis(matrix_2_3, 2, 3)

    return 0;
}