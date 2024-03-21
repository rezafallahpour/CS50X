#include <stdio.h>
#include <cs50.h>



int main(void)
{
    //start size
    int n;
    do
    {
        n = get_int("input the positive number to start: ");
        printf("Start size: %i\n", n);
    }
    while (n < 9);
    //end size
    int m;
    do
    {
        m = get_int("input the positive number to end: ");
        printf("End size: %i\n", m);
    }
    while (m < n);
    //calculate number of years
    int years = 0;
    while (n < m)
    {
        n = n + n / 3 - n / 4;
        years += 1;
    }
    // print years
    printf("Years: %i \n", years);
}
