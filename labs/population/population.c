#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt user for starting population size
    int s;
    do
    {
        s = get_int("Starting population size: \n");
    }
    while (s < 9);

    // TODO: Prompt for end size
    int e;
    do
    {
        e = get_int("ending population size: \n");
    }
    while (e < s);

    // TODO: Calculate number of years until we reach threshold

    int y = 0;
    while (e > s)
    {
        s = s + (s / 3) - (s / 4);
        y = y + 1;
    }

    // TODO: Print number of years
    printf("Years: %i\n", y);

}




