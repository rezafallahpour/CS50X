#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ffff\n");
        return 1;
    }
    else
    {
        char n[] = "1234567890";
        int count = 0;
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (argv[1][i] == n[j])
                {
                    count++;
                }
            }
        }
        if (count != strlen(argv[1]))
        {
            printf("Usage: kam dare\n");
            return 1;
        }
        else
        {
            int num = atoi(argv[1]);
            if (num <= 0 || num >= pow(2, 32) - 26)
            {
                printf("Usage: ./cesear key\n");
                return 1;
            }
            else
            {
                if (num % 26 == 0)
                {
                    num = 26;
                }
                else
                {
                    num = num % 26;
                }
                string input = get_string("plaintext: ");
                printf("ciphertext: ");
                for (int i = 0; i < strlen(input); i++)
                {
                    if (isalpha(input[i]) && isupper(input[i]))
                    {
                        if (input[i] + num > 90)
                        {
                            printf("%c", 64 + (input[i] + num) % 90);
                        }
                        else
                        {
                            printf("%c", input[i] + num);
                        }
                    }
                    else if (isalpha(input[i]) && islower(input[i]))
                    {
                        if (input[i] + num > 122)
                        {
                            printf("%c", 96 + (input[i] + num) % 122);
                        }
                        else
                        {
                            printf("%c", input[i] + num);
                        }
                    }
                    else
                    {
                        printf("%c", input[i]);
                    }
                }
                printf("\n");
            }
        }
    }
}