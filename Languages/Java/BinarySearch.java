// Kevin Tran
// August 28, 2018
// Binary Search
// Big-Oh(log n), Big Theta(log n), Big Omega(1)

import java.lang.Math;
import java.util.Random;

public class BinarySearch {
    public static void main(String [] args) {
        // Describe the program.
        System.out.println("\nBinary search for a random integer will be" + 
                           " performed on a hard-coded sorted array.\n");

        // Hard-code our sorted test array within the range 1 through 100.
        int [] a = new int[] {4, 12, 18, 19, 21, 22, 22, 35, 37, 39, 44, 50, 68,                   75, 84, 89, 93, 94, 99};
        
        // Show the array.
        printArray(a);

        // Come up with a random number to search for.
        int n = rng();
        System.out.println("\nThe number to be searched for is " + n + ".");

        // Run binary search, and get the index found.
        int index = binarySearch(a, n);
        System.out.println("\n" + ((index >= 0) ? "Found at index " + index +
                           "." : "Not found."));
    }

    // Print the array.
    private static void printArray(int [] a) {
        System.out.print("\n[");
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + (i < a.length-1  ? ", " : "]\n"));
        }
    }

    // Random Number Generator
    private static int rng() {
        Random generator = new Random();
        return Math.abs((generator.nextInt() % 100) + 1);
    }

    // Given an array of integers and an integer to search within the array,
    // utilize the binary search algorithm to return the index of the array
    // containing the integer. If the integer is not found, return -1.
    private static int binarySearch(int [] a, int n) {
        // Mark the starting and ending positions of our search range.
        int low = 0, high = a.length - 1;

        // Use binary search.
        while (low <= high) {
            int mid = (low + high) / 2;
            if (n < a[mid]) {
                high = mid - 1;
            } else if (n > a[mid]) {
                low = mid + 1;
            } else {
                return mid;
            }
        }

        // If we make it here, that means the integer was not found.
        return -1;
    }    
}

