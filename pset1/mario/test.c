#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int t;
    do
    {
        t = get_int("Height: \n");
    }
    while (t < 1 || t > 8);


    for (int a = 0; a < t; a++)
    {
        for (int b = 0; b <= a; b++)
        {
            printf("good");
        }

        printf("\n");
    }
}
