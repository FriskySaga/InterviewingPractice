/*
    Kevin Tran
    09-30-2015
    Study Time

    This program asks the user for the number of hours and minutes spent studying for each day of the week.
    The program then calculates the hours to minutes and adds up the hours to the minutes.
    Finally, the program will translate the resulting sum back to hours and minutes by dividing the value above by 60 to convert the hours,
    and then find the remainder which will represent the number of minutes.

    Basically, this program solves the complication of adding hours and minutes since the maximum value for minutes is 60 rather than 100.
*/

#include <stdio.h>

int main(void)
{
    //Opens "Study Time Weekly Log.txt" as an output file to write to.
    FILE * fp_output = fopen("Study Time Weekly Log.txt", "a");

    //Variables defined to record user's input.
    int mondayHours, mondayMinutes;
    int tuesdayHours, tuesdayMinutes;
    int wednesdayHours, wednesdayMinutes;
    int thursdayHours, thursdayMinutes;
    int fridayHours, fridayMinutes;
    int saturdayHours, saturdayMinutes;
    int sundayHours, sundayMinutes;

    //Variables defined to translate user input to minutes ONLY.
    int mondayTotalMinutes;
    int tuesdayTotalMinutes;
    int wednesdayTotalMinutes;
    int thursdayTotalMinutes;
    int fridayTotalMinutes;
    int saturdayTotalMinutes;
    int sundayTotalMinutes;

    //The all-encompassing sum of each day's "total minutes."
    int totalMinutes;

    //totalMinutes is translated into the more readable and user-friendly x hours and y minutes.
    int hours, minutes;



    //------------------------------------------------------------------------------------------




    //Asks for the user's input for each weekday, as separated by header comments.
    //Monday
    printf("How many hours and minutes did you spend studying on Monday?\nEnter the number of hours and minutes separated by a space.\n");
    scanf("%d %d", &mondayHours, &mondayMinutes);
    printf("You studied for %d hours and %d minutes on Monday.\n", mondayHours, mondayMinutes); //Reprints the user's input.

    mondayTotalMinutes = mondayHours*60 + mondayMinutes; //Hours to minutes. Then add that to minutes specified by user.
    printf("This translates to %d minutes.\n\n", mondayTotalMinutes);


    //Tuesday.
    printf("How many hours and minutes did you spend studying on Tuesday?\nEnter the number of hours and minutes separated by a space.\n");
    scanf("%d %d", &tuesdayHours, &tuesdayMinutes);
    printf("You studied for %d hours and %d minutes on Tuesday.\n", tuesdayHours, tuesdayMinutes); //Reprints the user's input.

    tuesdayTotalMinutes = tuesdayHours*60 + tuesdayMinutes; //Hours to minutes. Then add that to minutes specified by user.
    printf("This translates to %d minutes.\n\n", tuesdayTotalMinutes);


    //Wednesday.
    printf("How many hours and minutes did you spend studying on Wednesday?\nEnter the number of hours and minutes separated by a space.\n");
    scanf("%d %d", &wednesdayHours, &wednesdayMinutes);
    printf("You studied for %d hours and %d minutes on Wednesday.\n", wednesdayHours, wednesdayMinutes); //Reprints the user's input.

    wednesdayTotalMinutes = wednesdayHours*60 + wednesdayMinutes; //Hours to minutes. Then add that to minutes specified by user.
    printf("This translates to %d minutes.\n\n", wednesdayTotalMinutes);


    //Thursday.
    printf("How many hours and minutes did you spend studying on Thursday?\nEnter the number of hours and minutes separated by a space.\n");
    scanf("%d %d", &thursdayHours, &thursdayMinutes);
    printf("You studied for %d hours and %d minutes on Thursday.\n", thursdayHours, thursdayMinutes); //Reprints the user's input.

    thursdayTotalMinutes = thursdayHours*60 + thursdayMinutes; //Hours to minutes. Then add that to minutes specified by user.
    printf("This translates to %d minutes.\n\n", thursdayTotalMinutes);


    //Friday.
    printf("How many hours and minutes did you spend studying on Friday?\nEnter the number of hours and minutes separated by a space.\n");
    scanf("%d %d", &fridayHours, &fridayMinutes);
    printf("You studied for %d hours and %d minutes on Friday.\n", fridayHours, fridayMinutes); //Reprints the user's input.

    fridayTotalMinutes = fridayHours*60 + fridayMinutes; //Hours to minutes. Then add that to minutes specified by user.
    printf("This translates to %d minutes.\n\n", fridayTotalMinutes);


    //Saturday.
    printf("How many hours and minutes did you spend studying on Saturday?\nEnter the number of hours and minutes separated by a space.\n");
    scanf("%d %d", &saturdayHours, &saturdayMinutes);
    printf("You studied for %d hours and %d minutes on Saturday.\n", saturdayHours, saturdayMinutes); //Reprints the user's input.

    saturdayTotalMinutes = saturdayHours*60 + saturdayMinutes; //Hours to minutes. Then add that to minutes specified by user.
    printf("This translates to %d minutes.\n\n", saturdayTotalMinutes);


    //Sunday.
    printf("How many hours and minutes did you spend studying on Sunday?\nEnter the number of hours and minutes separated by a space.\n");
    scanf("%d %d", &sundayHours, &sundayMinutes);
    printf("You studied for %d hours and %d minutes on Sunday.\n", sundayHours, sundayMinutes); //Reprints the user's input.

    sundayTotalMinutes = sundayHours*60 + sundayMinutes; //Hours to minutes. Then add that to minutes specified by user.
    printf("This translates to %d minutes.\n\n", sundayTotalMinutes);




    //------------------------------------------------------------




    //Sum of total minutes for each day.
    totalMinutes = mondayTotalMinutes + tuesdayTotalMinutes + wednesdayTotalMinutes + thursdayTotalMinutes + fridayTotalMinutes + saturdayTotalMinutes + sundayTotalMinutes;
    printf("This week, you studied for a total of %d minutes.\n", totalMinutes);

    //Translation of totalMinutes to hours and minutes format.
    hours = totalMinutes / 60; //This will round down to the nearest whole number.
    minutes = totalMinutes % 60;
    printf("Basically, you were hard at work for %d hours and %d minutes.\n\n", hours, minutes);




    //--------------------------------------------






    //Records the number of hours and minutes spent studying for each week.

    //MAKE SURE TO MODIFY THE DATES! MAKE SURE TO MODIFY THE DATES!
    //MAKE SURE TO MODIFY THE DATES! MAKE SURE TO MODIFY THE DATES!
    //MAKE SURE TO MODIFY THE DATES! MAKE SURE TO MODIFY THE DATES!
    //MAKE SURE TO MODIFY THE DATES! MAKE SURE TO MODIFY THE DATES!
    fprintf(fp_output, "From the week of January 25, 2016 to January 31, 2016, you worked for %d hours and %d minutes.", hours, minutes);
    fprintf(fp_output, "\n");//1
    fprintf(fp_output, "\n");//2
    fprintf(fp_output, "\n");//3
    fprintf(fp_output, "\n");//4
    fprintf(fp_output, "\n");//5
    fprintf(fp_output, "\n");//6
    fprintf(fp_output, "\n");//7
    fprintf(fp_output, "\n");//8







    //-------------------------------------------------------------------



    //Closes output file "Study Time Weekly Log.txt"
    fclose(fp_output);

    return 0;
}
