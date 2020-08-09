/*
    10-02-2015
    Adding Time

    This program's purpose is to add hours, minutes, and seconds. The extended description is written below.


    Have you ever tried to add hours and minutes together? Or how about minutes and seconds? It's difficult, isn't it? Especially since minutes
    can only go up to a value of 60 before resetting back to 0, and the same can be said for seconds. Thus, I have devised a special calculator to
    compute hours and minutes! This program will ask you how many times you would like to add instances of hours, minutes, and seconds, hereafter dubbed
    "event". Then, the program will ask you to enter a value for hours and minutes for each event. Finally, the calculator will tell you the final result
    after adding all of the events up!
*/

#include <stdio.h>

//#define DEBUG

int main(void)
{

    //Variable to store user's designated number of events.
    int numEvents;

    //Dummy variable for FOR loops.
    int i;

    //Variables to store user input.
    int userHours, userMinutes, userSeconds;

    //Variables to store conversions of hours to minutes and minutes to seconds.
    int eventMinutes, eventSeconds;

    //Variable to add up all of the converted event inputs from the array.
    int totalSeconds;

    //Variable to store minutes. Seconds are included separately.
    int totalMinutes;

    //Variables to display data in a more readable manner.
    int hours, minutes, seconds;




    //Asks the user how many events they would like to compute.
    printf("This program sums up multiple sets of hours, minutes, and seconds.\n"
           "An \"event\" is defined as an instance of time to compute,\n"
           "represented as a tuple of hours, minutes, and seconds.\n\n");
    printf("Please enter a number below indicating the number of \"events\", as defined above,\nthat you would like to compute.\n\n");
    scanf("%d", &numEvents);
    printf("\n\n\n");

    //Array to store each event's input.
    int memory[numEvents];

    //User input, conversion calculations, storage for final output.
    for (i = 0; i < numEvents; i++)
    {
        printf("-------------------");//To start a new iteration.
        printf("\n\n");
        //Asks user for the number of hours.
        printf("Please insert the number of hours below for event #%d.\nWe will ask for the number of minutes and seconds next.\n", i+1);
        scanf("%d", &userHours);
        printf("\n\n");

        //Asks user for the number of minutes.
        printf("Please insert the number of minutes below.\nWe will ask for the number of seconds afterwards.\n");
        scanf("%d", &userMinutes);
        printf("\n\n");

        //Asks user for the number of seconds.
        printf("Please insert the number of seconds below!\n");
        scanf("%d", &userSeconds);
        printf("\n\n");


        //Convert user's hours to minutes, and adds the product onto the user's specified minutes. Does nothing with seconds.
        eventMinutes = userHours * 60 + userMinutes;
        printf("Event #%d translates to %d minutes and %d seconds...\n", i+1, eventMinutes, userSeconds);
        //Converts the value above, which is in minutes, to seconds and adds the product onto the user's specified seconds.
        eventSeconds = eventMinutes * 60 + userSeconds;
        printf("which converts to %d seconds.\n\n", eventSeconds);


        //Adds eventSeconds to memory array.
        memory[i] = eventSeconds;
        #ifdef DEBUG
            printf("%d\n", memory[i]);
        #endif // DEBUG

    }//Closes first FOR loop.


    printf("-------------------");//To signal the end of the loop above.


    totalSeconds = 0;//Initializer.
    //Calculates the sum, in seconds, of the various eventSeconds in the array "memory".
    for (i = 0; i < numEvents; i++)
    {
        totalSeconds += memory[i];

    }//Closes second FOR loop.


    //Converts totalSeconds to the more readable format with hours, minutes, and seconds listed.
    seconds = totalSeconds % 60;

        //Stores minutes before calculating hours and finding the leftover number of minutes.
        totalMinutes = totalSeconds / 60;
        printf("\n\nIn essence, you just added up %d minutes and %d seconds.\n\n\n", totalMinutes, seconds);

    minutes = totalMinutes % 60;
    hours = totalMinutes / 60;

    //Final output for the program!
    printf("The resulting sum is...\n\n%d hours\n%d minutes\n%d seconds.\n", hours, minutes, seconds);


    return 0;

}//Closes MAIN function.
