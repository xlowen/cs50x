#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //prompt for credit card number
    long cc;
    do
    {
        cc = get_long("Number \n");
    }
    while (cc < 0);

    long ccd = (cc /10);
    long a = cc %10;
    long b = ccd %10;
    long c = ccd /10 %10;
    long d = ccd /10 /10 %10;
    long e = ccd /10 /10 /10 %10;
    long f = ccd /10 /10 /10 /10 %10;
    long g = ccd /10 /10 /10 /10 /10 %10;
    long h = ccd /10 /10 /10 /10 /10 /10 %10;
    long i = ccd /10 /10 /10 /10 /10 /10 /10 %10;
    long j = ccd /10 /10 /10 /10 /10 /10 /10 /10 %10;
    long k = ccd /10 /10 /10 /10 /10 /10 /10 /10 /10 %10;
    long l = ccd /10 /10 /10 /10 /10 /10 /10 /10 /10 /10 %10;
    long m = ccd /10 /10 /10 /10 /10 /10 /10 /10 /10 /10 /10 %10;
    long n = ccd /10 /10 /10 /10 /10 /10 /10 /10 /10 /10 /10 /10 %10;
    long o = ccd /10 /10 /10 /10 /10 /10 /10 /10 /10 /10 /10 /10 /10 %10;
    long p = ccd /10 /10 /10 /10 /10 /10 /10 /10 /10 /10 /10 /10 /10 /10 %10;
    
    int ln = p * 2 + n * 2 + l * 2 + j * 2 + g * 2 + e * 2 + c * 2 + a * 2 ;
    
    int visa;

    printf("%lo \n", a);
    printf("%lo \n", b);
    printf("%lo \n", c);
    printf("%lo \n", d);
    printf("%lo \n", e);
    printf("%lo \n", f);
    printf("%lo \n", g);
    printf("%lo \n", h);
    printf("%lo \n", i);
    printf("%lo \n", j);
    printf("%lo \n", k);
    printf("%lo \n", l);
    printf("%lo \n", m);
    printf("%lo \n", n);
    printf("%lo \n", o);
    printf("%lo \n", p);
    printf("%i \n", ln);
}