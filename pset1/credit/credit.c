#include <cs50.h>
#include <stdio.h>
#include <math.h>


int countDigits(long number)
{
    int count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    return count;
}
long counttotaldigit(long n)
{
    int number = 1;
    int total2k = 0;
    int total2k1 = 0;
    while( n != 0)
    {
      int g = n % 10;
      if(number%2 == 0)
      {
        if ((g*2)/10 >= 1)
        {
          g = g*2;
          while (g != 0)
          {
            int digit_g = g % 10;
            total2k += digit_g;
            g /=10;
          }
        }
        else
        {
          total2k += g * 2;
        }
      }
      else
      {
        total2k1 += g;
      }
      n /= 10;
      number ++;
    }
    //printf("%i\n" , total2k);
    //printf("%i\n" , total2k1);
    int total = total2k + total2k1;
    //printf("%i\n", total);
    return total;
}


int main()
{
  long n = get_long("Number: ");
  int power_div = (n / pow(10,(countDigits(n)-1)));
  if ((countDigits(n) == 13 || countDigits(n) == 16) &&  power_div== 4)
  {
    if (counttotaldigit(n)%10 == 0)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
  }
  else if(countDigits(n) == 15 && counttotaldigit(n)%10 == 0 && power_div == 3)
  {
    printf("AMEX\n");
  }
  else if(countDigits(n) == 16 && counttotaldigit(n)%10 == 0 && power_div == 5)
  {
    printf("MASTERCARD\n");
  }
  else
  {
    printf("INVALID\n");
    //printf("%i\n",countDigits(n));
    //printf("%i\n",power_div);
  }


}


