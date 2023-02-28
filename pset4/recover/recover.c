#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//Creates an int for the size of blocks inside the memory card

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    //check if 1 argument
    if (argc != 2)
    {
        printf("Incorrect usage. ./recover filename.raw \n");
        return 1;
    }
    //Open input file
    FILE *rawimg = fopen(argv[1], "r");
    if (rawimg == NULL)
    {
        printf("Could not open file");
        return 1;
    }

    //initialize variables
    int counter = 0;
    int firstfile = 1;
    FILE *img;
    uint8_t buffer[BLOCK_SIZE];
    char fname[50];
    //starts reading card
    while (fread(buffer, 1, BLOCK_SIZE, rawimg) == BLOCK_SIZE)
    {
        //check first four bytes
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter == 0)
            {
                sprintf(fname, "%03i.jpg", counter);
                img = fopen(fname, "w");
                fwrite(buffer, 1, BLOCK_SIZE, img);
                counter++;
            }
            else
            {
                fclose(img);
                sprintf(fname, "%03i.jpg", firstfile);
                img = fopen(fname, "w");
                fwrite(buffer, 1, BLOCK_SIZE, img);
                firstfile ++;
            }
        }
        else if (counter >= 1)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }
    fclose(img);
}