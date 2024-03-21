#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    // get the Height
    do
    {
        n = get_int("Height:");
    }
    while (n <= 0 || n > 8);
    for (int i = 0; i < n; i++)
    {
        // space before mario
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        //first step
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        for (int j = 0; j <= 1; j++)
        {
            // space midell of mario
            printf(" ");
        }
        //second step
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}