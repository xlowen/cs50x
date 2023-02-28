#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string encrypt(string ptxt, int key);
int main(int argc, string argv[])
{
    //Checks number of arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //checks validity of argument
    else
    {
        for (int i = 0; i < strlen(argv[1]); i++)
            if (!isdigit(argv[1][i]) && argv[1][i] > 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
    }
    //convert argument from string to int
    int key = atoi(argv[1]);
    //prompt user for Plaintext
    string ptxt = ("Plaintext:");
    //iterates each char of plaintext checking if it is alphabetic, uppercase or lowercase.
    //applies formula to shift characters.
    for (int i = 0; i < strlen(ptxt); i++)
    {

        if (isalpha(ptxt[i]) && isupper(ptxt[i]))
        {
            ptxt[i] = (ptxt[i] - 65 + key) % 26 + 65;

        }
        else if (isalpha(ptxt[i]) && islower(ptxt[i]))
        {
            ptxt[i] = (ptxt[i] - 97 + key) % 26 + 97;
        }


    }
    //print ciphertext
    printf("ciphertext: %s\n", ptxt);

}