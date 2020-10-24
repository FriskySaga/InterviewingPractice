#include <stdio.h>

int factorial_recursive(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n * factorial_recursive(n-1);
    }
}

int main(void) {
    int factorial;
    printf("Find factorial of: ");
    scanf("%d", &factorial);

    // Find factorial recursively.
    int recursive_result = factorial_recursive(factorial);
    printf("\nFactorial recursive yields %d\n", recursive_result);

    return 0;
}
