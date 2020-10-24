/*
    Kevin Tran
    10-05-2015
    Subtracting Time

    Have you ever tried to calculate how much time you would have left after completing a series of "events"? This is a calculator that will
    serve this purpose!
*/

#include <stdio.h>

int main(void)
{
    //Variables to record user's input for starting hours, minutes, and seconds.
    int startingHours, startingMinutes, startingSeconds;

    //Converts startingHours to startingMinutes.
    int startingMinutesOnly;

    //Converts startingMinutesOnly to seconds only.
    int startingTime;

    //Variable to save user's input for the number of times they would like to subtract from the starting time.
    int numEvents;

    //Dummy variable for FOR loops.
    int i;

    //Records user's input for each event's hours, minutes, and seconds.
    int eventHours, eventMinutes, eventSeconds;

    //Stores the conversion of eventHours to eventMinutes.
    int eventMinutesOnly;

    //Stores the conversion of eventMinutesOnly to seconds.
    int eventTime;

    //Array to store eventTime.
    int events[numEvents];

    //Stores conversions of final hours, minutes, and seconds after subtracting each event.
    int hoursRemaining;
    int minutesOnlyRemaining; //Used as a step to convert minutes to hours.
    int minutesRemaining;
    int secondsRemaining;



    //Asks user how much time they are subtracting from.
    printf("What is the starting time or the amount of time you have left to accomplish your tasks?\n");
    printf("Please enter the number of hours, minutes, and seconds. Separate each value by a space.\n");
    scanf("%d %d %d", &startingHours, &startingMinutes, &startingSeconds);
    //Converts user's hours to minutes.
    startingMinutesOnly = startingHours * 60 + startingMinutes;
    //Converts user's minutes to seconds.
    startingTime = startingMinutesOnly * 60 + startingSeconds;

    //Asks user how many events or calculations to be made.
    printf("How many tasks or \"events\" do you have to do? Enter an integer below!\n");
    scanf("%d", &numEvents);

    //Records events.
    for(i = 0; i < numEvents; i++)
    {
        //Records user's input for each event.
        printf("What is the number of hours, minutes, and seconds for Event #%d?\n", i+1);
        printf("As usual, separate each value by a space.\n");
        scanf("%d %d %d", &eventHours, &eventMinutes, &eventSeconds);
        //Converts event's hours to minutes.
        eventMinutesOnly = eventHours * 60 + eventMinutes;
        //Converts user's minutes to seconds.
        eventTime = eventMinutesOnly * 60 + eventSeconds;

        events[i] = eventTime;
    }//Closes first FOR loop.

    //Formatting for final output.
    printf("\n\n\n");

    //Goes through each value of the array and subtracts them from startingTime.
    for (i = 0; i < numEvents; i++)
    {
        startingTime = startingTime - events[i];


        //Conversion of startingTime to seconds.
        secondsRemaining = startingTime % 60;
            //Conversion of all seconds startingTime to minutes only.
            minutesOnlyRemaining = startingTime / 60;
        //Conversion of minutesOnlyRemaining to minutes.
        minutesRemaining = minutesOnlyRemaining % 60;
        //Conversion of startingTime to hours.
        hoursRemaining = minutesOnlyRemaining / 60;

        //Final print statement.
        printf("After Event #%d, you now have %d hours, %d minutes, and %d seconds left.\n", i+1, hoursRemaining, minutesRemaining, secondsRemaining);

    }//Closes second FOR loop.


    return 0;
}//Closes MAIN function.
