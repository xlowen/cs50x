#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //prompt for credit card number
    long cc;
    do
    {
        cc = get_long("Number: \n");
    }
    while (cc < 0);

    long ccs = cc;
    long ccd = cc;
    long ldc = cc;
    int lda = 0;
    int count;
    int sume = 0;
    for (count = 0, lda = 0; ccs > 0; count++)
    {
        lda = ccs % 10;
        ccs = ccs / 10;
        lda = lda * 2;
        if (lda >= 10)
        {
            lda = lda % 10 + lda / 10;
        }
        else
            ;
        if (count % 2 == 0)
            ;
        else
        {
            sume = sume + lda;
        }
    }
    int ldb;
    int counta;
    int sumo = 0;
    for (counta = 0, ldb = 0; ccd > 0; counta++)
    {
        ldb = ccd % 10;
        ccd = ccd / 10;
        if (counta % 2 == 0)
        {
            sumo = sumo + ldb;
        }
        else
            ;
    }
    int amex = 0;
    int master = 0;
    int countb;
    int countc;
    for (countb = 0; ldc >= 100 ; countb++)
    {
        ldc = ldc / 10;
    }

    amex = ldc;
    master = ldc;
    int visa = ldb;
    int val = sumo + sume;
    if (val % 10 == 0 && (count == 13 || count == 16) && visa == 4)
    {
        printf("VISA\n");
    }
    else if (val % 10 == 0 && count == 15 && (amex == 34 || amex == 37))
    {
        printf("AMEX\n");
    }
    else if (val % 10 == 0 && count == 16 && (master == 51 || master == 52 || master == 53 || master == 54 || master == 55))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}