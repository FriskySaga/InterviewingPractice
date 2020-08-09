// Kevin Tran
// October 24, 2017
// Calculate the area and circumference of a circle.

#include <stdio.h>
#include <math.h>

// Given the radius, find the area of the circle: A = pi*r^2
double find_area(double radius) {
    double area = M_PI * pow(radius, 2);
    printf("\nThe area of your circle is %lf.\n", area);
    return area;
}

// Given the radius, find the circumference of the circle: C = 2*pi*r
double find_circumference(double radius) {
    double circumference = 2 * M_PI * radius;
    printf("\nThe circumference of your circle is %lf.\n", circumference);
    return circumference;
}

// Get the radius of the circle from the user.
double get_radius() {
    double radius;
    printf("\nEnter the radius of your circle: ");
    scanf("%lf", &radius);

    // A circle cannot have a non-positive radius!
    while (radius <= 0) {
        printf("\nHold up! You need to enter a positive value!"
               "\nTry again here: ");
        scanf("%lf", &radius);
    }
    return radius;
}

int main(void) {
    // Tell the user about this program.
    printf("\nThis program will calculate the area and circumference of any"
           " circle with a user-specified radius."
           "\nYou do not need to include the units.\n");

    // Calculate the area and circumference of the circle.
    char sentinel;
    do {
        // Get radius from user.
        double radius = get_radius();

        // Calculate area of the circle.
        double area = find_area(radius);

        // Calculate circumference of the circle.
        double circumference = find_circumference(radius);

        // Ask user if they would like to find the area and circumference of
        // a different circle.
        printf("\nWould you like to find the area and circumference of"
               " another circle?"
               "\nPress [Y] for yes, and press any other key for no."
               " Omit the brackets."
               "\nIndicate your choice here: ");
        scanf(" %c", &sentinel);
    } while (sentinel == 'Y' || sentinel == 'y');

    return 0;
}
