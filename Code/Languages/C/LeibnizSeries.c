// Kevin Tran
// February 16, 2018
// Approximate PI to 3.14159

#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main(void)
{
 	int term = 1, numerator = 4, denominator = 1;
 	float pi = 0; // initialize our sum

 	// header
 	printf("The Leibniz's Series to finding pi.");

 	// while (pi != PI) [in other words, loop until pi = 3.14159)
 	while (fabs(pi - PI) > 0.000001)
  {
    // every 1st, 3rd, 5th (every odd) term, add to [pi = 0]
 	  if (term % 2 == 1)
    {
 	    pi += (float) numerator / denominator;
 	    printf(" + %d/%d\n", numerator, denominator);
 	  }

    // every 2nd, 4th, 6th (every even) term, subtract from pi
 	  else
    {
       pi -= (float) numerator / denominator;
 	     printf(" - %d/%d\n", numerator, denominator);
	  }

 	  // print the new value of pi after each addition OR subtraction
 	  printf("Pi: %f\n", pi);

 	  // update term count
 	  term++;

 	  // add 2 to the denominator after each iteration, but keep numerator the same after each iteration
 	  denominator += 2;
  }

  // Print final result.
  printf("\nIt took %d terms to reach 3.14159.\n", term);
  return 0;
}
