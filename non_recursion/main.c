#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h>     // for sleep()


//This program takes in a number from the command line as a factorial.
//Then computes the factorial using a loop.
//Then displays the result along with the runtime

//function for calculating factorial of a number using a loop
long double factorial(int n)
{
    long double fact = 1;

    for(int i = 1; i <= n; i++)
        fact = fact * i;

    return fact;
}

int main(int argc, char *argv[])
{

    int number;
    long double fact;
    // to store the execution time of code
    double time_spent = 0.0;

    //scan argument from command lin into number
    sscanf(argv[1], "%d", &number);

    //checking input
    if(number < 0 || number > 100)
    {
        fprintf(stderr, "Error: incorrect value inputted.  Please enter numbers between 0 and 100 inclusive\n");
        exit(1);
    }

    //begin time
    clock_t begin = clock();
    //calculate factorial
    fact = factorial(number);
    //print result
    printf("Factorial of %d using recursion is %.0Lf\n", number, fact);
    //end time
    clock_t end = clock();

    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    //print time elapsed
    printf("The elapsed time is %f seconds\n", time_spent);

    return 0;
}
