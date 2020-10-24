/*
    Kevin Tran
    May 10, 2019
    COP3223C Program 7

    Sort information on when TAs are available.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_SHIFTS = 100;

struct Shift {
    char name[100];
    char day_of_week[10];
    int start_hour;
    int end_hour;
};


// @param hour - Integer representing military hour
// @return convertedHour - Integer representing twelve hour notation
int convertToTwelveHourNotation(int hour) {
    int convertedHour = hour;
    if (hour > 12) {
        convertedHour = hour - 12;
    }
    return convertedHour;
}

// @param hour - Integer representing military hour
// @param hourPeriod - String returning "am" or "pm"
void getAMorPMString(char *hourPeriod, int hour) {
    if (hour < 12) {
        strcpy(hourPeriod, "am");
    } else {
        strcpy(hourPeriod, "pm");
    }
}

// This function provides an alternative to using strlen() on a given string
// @param *name - String containing name of TA
// @return c - Integer containing length of name
int getNameLength(char *name) {
    int c = 0;
    while (name[c] != '\0') {
        c++;
    }
    return c;
}

// Get the length of longest TA's name
// @param shift - array of structure "Shift"
// @param num_shifts - Integer indicating number of shifts
// @return longestNameLength - Integer representing the length of the lognest name
int getLongestNameLength(struct Shift shift[], int num_shifts) {
    int longestNameLength = 0;
    for (int i = 0; i < num_shifts; i++) {
        int nameLength = getNameLength(shift[i].name);
        if (nameLength > longestNameLength) {
            longestNameLength = nameLength;
        }
    }
    return longestNameLength;
}

// Preconditions: array of structure "Shift"
// integer value indicating number of shifts
// Postconditions: none - this function does not return anything.
// Actions: Print the sorted data in the format described below.
void print_data(struct Shift shift[], int num_shifts) {
    int longestNameLength = getLongestNameLength(shift, num_shifts);

    printf("\nTA Shifts\n");
    printf("==========================================\n");
    for (int i = 0; i < num_shifts; i++) {
        // Convert military starting and ending hours to twelve hour notation
        int twelveHourStartTime = convertToTwelveHourNotation(shift[i].start_hour);
        int twelveHourEndTime = convertToTwelveHourNotation(shift[i].end_hour);

        // Determine whether the starting hours are AM or PM
        char *isStartTimeAMorPM = (char *) malloc(sizeof(char) * 3);
        getAMorPMString(isStartTimeAMorPM, shift[i].start_hour);

        // Determine whether the ending hours are AM or PM
        char *isEndTimeAMorPM = (char *) malloc(sizeof(char) * 3);
        getAMorPMString(isEndTimeAMorPM, shift[i].end_hour);

        //        *0   1    2     3        4     5
        printf(" %*s  %9s  %2d:00 %s  to  %2d:00 %s\n", longestNameLength,    // *
                                                        shift[i].name,        // 0
                                                        shift[i].day_of_week, // 1
                                                        twelveHourStartTime,  // 2
                                                        isStartTimeAMorPM,    // 3
                                                        twelveHourEndTime,    // 4
                                                        isEndTimeAMorPM);     // 5
        free(isEndTimeAMorPM);
        free(isStartTimeAMorPM);
    } // ends for loop
}

// Preconditions: array of structure "Shift"
// integer value indicating number of shifts
// Postconditions: none - this function does not return anything.
// Actions: Sort the shifts by the TA's first name.
void sort_data(struct Shift shift_data[], int num_shifts) {
    // @param name1 - String of first name to compare
    // @param name2 - String of second name to compare
    // @return -1 if the first string comes before;
    //          0 if both strings match;
    //          1 if the first string comes after
    int compare (const void *name1, const void *name2) {
        struct Shift *s1 = (struct Shift *) name1;
        struct Shift *s2 = (struct Shift *) name2;
        return strcmp(s1->name, s2->name);
    }
    qsort(shift_data, num_shifts, sizeof(struct Shift), compare);
}

// Preconditions: array of structure "Shift" to store data
// Postconditions: number of shifts read in from data file
// Actions: Ask user for name of input file. Read the number
//          of shifts, then read in the data for all
//          of the shifts. Return the number of shifts.
int read_data(struct Shift shift_data[]) {
    int num_shifts = 0;
    char *infile_name = (char *) malloc(sizeof(char) * 100);
    printf("\nEnter name of input file: ");
    scanf("%s", infile_name);
    FILE *ifp = fopen(infile_name, "r");
    if (ifp == NULL) {
        printf("No such input file!\n");
    }
    else {
        fscanf(ifp, "%d", &num_shifts);
        for (int i = 0; i < num_shifts; i++) {
            fscanf(ifp, "%s%s%d%d", shift_data[i].name,
                                    shift_data[i].day_of_week,
                                    &shift_data[i].start_hour,
                                    &shift_data[i].end_hour);
        }
        fclose(ifp);
    }
    free(infile_name);
    return num_shifts;
}

int main(void) {
    struct Shift shift_data[MAX_SHIFTS];
    int num_shifts = read_data(shift_data);
    if (num_shifts > 0) {
        sort_data(shift_data, num_shifts);
        print_data(shift_data, num_shifts);
    }
    return 0;
}
