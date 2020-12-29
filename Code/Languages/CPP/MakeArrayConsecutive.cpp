/*
    Kevin Tran
    Codefights Arcade Problem
    Make Array Consecutive 2

    Ratiorg got statues of different sizes as a present from CodeMaster for his birthday, each statue having an non-negative integer size. Since he likes to make things perfect, he wants to arrange them from smallest to largest so that each statue will be bigger than the previous one exactly by 1. He may need some additional statues to be able to accomplish that. Help him figure out the minimum number of additional statues needed.

    Example

    For statues = [6, 2, 3, 8], the output should be
    makeArrayConsecutive2(statues) = 3.

    Ratiorg needs statues of sizes 4, 5 and 7.

    Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] array.integer statues

    An array of distinct non-negative integers.

    Guaranteed constraints:
    1 ≤ statues.length ≤ 10,
    0 ≤ statues[i] ≤ 20.

    [output] integer

    The minimal number of statues that need to be added to existing statues such that it contains every integer size from an interval [L, R] (for some L, R) and no other sizes.

*/


int makeArrayConsecutive2(std::vector<int> statues) {
    // Initialize min and max values based on constraints.
    int min = 20, max = 0;

    // Make a frequency array corresponding to each statue size.
    bool freq[21] = {false};

    // Look at all statues.
    for (int i = 0; i < statues.size(); i++) {
        // Set the lowest value seen.
        if (statues[i] < min) {
            min = statues[i];
        }

        // Set the highest value seen.
        if (statues[i] > max) {
            max = statues[i];
        }

        // Indicate that a statue for this size exists.
        freq[statues[i]] = true;
    }

    // Look through each statue we have in ascending order, and increment
    // our counter whenever we expect a statue of the next size but don't find it.
    int cnt = 0;
    for (int i = min; i <= max; i++) {
        if (freq[i] == false) {
            cnt++;
        }
    }

    // Return the number of statues needed to be added.
    return cnt;
}

