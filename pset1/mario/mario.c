#include <cs50.h>
#include <stdio.h>

int main(void)

{
    //prompt user for height
    int t;
    do
    {
        t = get_int("Height: \n");
    }
    while (t < 1 || t > 8);

    //draws first half of pyramid with proper spacing
    for (int a = 0; a < t; a++)
    {
        for (int c = t - 1; c > a; c--)
        {
            printf(" ");
        }
        for (int b = 0; b <= a; b++)
        {
            printf("#");
        }
        //print 2 space gap
        printf("  ");
        //print second half of pyramid
        for (int b = 0; b <= a; b++)
        {
            printf("#");
        }

        printf("\n");
    }
}