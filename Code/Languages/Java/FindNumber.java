// Kevin Tran
// August 28, 2018
// Find the given number in a given array.
// Big-Oh(n), Big-Theta(n), Big-Omega(1)

import java.util.Random;

public class FindNumber {
    // Return the index of the given number of the given array.
    private static int findNumber(int [] a, int n) {
        // Find the number.
        for (int i = 0; i < a.length; i++) {
            if (a[i] == n) {
                return i;
            }
        }

        // Return -1 if we didn't find.
        return -1;
    }

    // Print the given array.
    private static void printArray(int [] a) {
        System.out.print("\n[");
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + (i < a.length-1 ? ", " : "]\n"));
        }
    }

    // Describe the program, and set up the problem.
    public static void main(String [] args) {
        int [] a = new int[50];

        // Populate array with random integers from 1 through 100.
        for (int i = 0; i < a.length; i++) {
            a[i] = (int) (Math.random() * 100) + 1;
        }

        // Generate a random number we want to search for.
        int n = (int) (Math.random() * 100) + 1;

        // Tell the user about this program.
        System.out.println("\nThis program will find a given number with a" +
                           " random array.\nHere is the randomly generated" +
                           " integer array:");

        // Print the array.
        printArray(a);

        // Print the target random integer.
        System.out.println("\nHere is the target number: " + n);

        // Print the array index containing the target number.
        System.out.println("\nThe target number is found at index " +
                           findNumber(a, n) + ".");
    }
}
