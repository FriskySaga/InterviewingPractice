/*
 * Kevin Tran
 * 
 * October 26, 2017
 *
 * FirstDuplicate.java
 * =================== 
 * Given an array that contains only numbers in the range from 1 through the
 * length of the array, find the first duplicate number for which the second
 * occurrence has the minimal index.
 *
 * Big-Oh(n), Big-Theta(n), Big-Omega(1)
 */


import static java.lang.System.out;
import java.util.Random;


public class FirstDuplicate {
    /**
     * Find the first duplicate integer in the array.
     *
     * @param   array an integer array with random integers from 1 through
     *          the length of the array.
     * @return  the first duplicate integer in the array, else -1 if no duplicate
     *          integer exists in the array.
     */
    public static int findFirstDuplicate(int[] array) {
        boolean[] frequencyArray = new boolean[array.length];

        // Mark the occurrences of each integer with a frequency array.
        for (int i = 0; i < frequencyArray.length; i++) {
            if (!frequencyArray[array[i]-1]) {
                frequencyArray[array[i]-1] = true;
            } else {
                return array[i];
            }
        }
        return -1;
    }

    /**
     * Print the array to the screen.
     *
     * @param   array an integer array with random integers from 1 through 100
     */
    public static void printArray(int[] array) {
        out.print("\n  [");
		for (int i = 0; i < array.length; i++) {
			out.print(array[i] + ((i < array.length-1) ? ", " : "]\n\n"));
        }
	}

    /**
     * Print the first duplicate integer to the screen.
     *
     * @param   firstDuplicate the first duplicate integer found.
     */
    public static void showFirstDuplicate(int firstDuplicate) {
        if (firstDuplicate == -1) {
            out.println("There were no duplicate numbers.");
        } else {
            out.format("The first duplicate number found in the array was %d.\n", firstDuplicate);
        }
    }

    /**
     * Tell the user about the purpose of this program. Make and fill an array
     * with random integers from 1 through the length of the array. Print the
     * array to the screen, and find the first duplicate number in the array.
     *
     * @param   args is not used.
     */
    public static void main(String[] args) {
        int[] a = new int[10];

        // Populate the array with random integers from 1 through the length
        // of the array.
        for (int i = 0; i < a.length; i++) {
            a[i] = (int)(Math.random() * a.length) + 1;
        }

        // Tell the user about this program.
        out.println("\nGiven an array, this program will find the first" +
                    " duplicate number.\nHere is a randomly generated array:");
        
        // Print the array.
        printArray(a);

        // Find the first duplicate number.
        int firstDuplicate = findFirstDuplicate(a);

        // Show the first duplicate number.
        showFirstDuplicate(firstDuplicate);
    }
}
