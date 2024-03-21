#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int n;
    // get amount of cash the client want
    do
    {
        n = get_int("Change owed: ");
    }
    while(n < 0);
    return n;
}

int calculate_quarters(int cents)
{
    // return number of quarters
    int q = cents/25;
    return q;
}

int calculate_dimes(int cents)
{
    // return number of dimes
    int q = cents/25;
    int d = (cents-q*25)/10;
    return d;
}

int calculate_nickels(int cents)
{
    // return number of nickels
    int q = cents/25;
    int d = (cents-q*25)/10;
    int n = (cents-(q*25+d*10))/5;
    return n;
}

int calculate_pennies(int cents)
{
    // return number of pennies
    int q = cents/25;
    int d = (cents-q*25)/10;
    int n = (cents-(q*25+d*10))/5;
    int p = cents-(q*25+d*10+n*5);
    return p;
}
