#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //prompt the user for change
    float o;
    do
    {
        o = get_float("Change Owed: \n");
    }
    while (o <= 0);

    //convert dollars to cents
    int cents = round(o * 100);

    //define coins
    int quarter = 0;
    while (cents >= 25)
    {
        quarter = quarter + 1;
        cents = cents - 25;
    }

    int dime = 0;
    while (cents >= 10 && cents <= 25)
    {
        dime = dime + 1;
        cents = cents - 10;
    }

    int nickel = 0;
    while (cents >= 5 && cents <= 10)
    {
        nickel = nickel + 1;
        cents = cents - 5;
    }

    int penny = 0;
    while (cents >= 1 && cents <= 5)
    {
        penny = penny + 1;
        cents = cents - 1;
    }
    //sum number of coins
    int coins = quarter + dime + nickel + penny;
    //print number of coins
    printf("%i\n", coins);

}