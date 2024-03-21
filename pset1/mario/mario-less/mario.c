#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char mario_less [] = "        ";
    int i;
    int n;
    do{
        n = get_int("enter posetive number:");
        printf("Height: %i\n",n);
    }
    while (n<=0 || n>8);
    for (i=n ; i>0 ; --i){
        mario_less[i-1]='#';
        printf("%s\n",mario_less);
    }
}