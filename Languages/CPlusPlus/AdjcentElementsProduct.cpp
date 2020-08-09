/*
    Kevin Tran
    Codefights Arcade Problem
    adjacentElementsProduct

    Given an array of integers, find the pair of adjacent elements that has the largest product and return that product.

    Example

    For inputArray = [3, 6, -2, -5, 7, 3], the output should be
    adjacentElementsProduct(inputArray) = 21.

    7 and 3 produce the largest product.

    Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] array.integer inputArray

    An array of integers containing at least two elements.

    Guaranteed constraints:
    2 ≤ inputArray.length ≤ 10,
    -1000 ≤ inputArray[i] ≤ 1000.

    [output] integer

    The largest product of adjacent elements.
*/

int adjacentElementsProduct(std::vector<int> inputArray) {
    int largestProduct = -1000;
    for (int i = 0, j = 1; j < inputArray.size(); i++, j++) {
        int n = inputArray[i] * inputArray[j];
        if (n > largestProduct) {
            largestProduct = n;
        }
    }
    return largestProduct;
}
