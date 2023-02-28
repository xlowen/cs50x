#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int j = 0;

    for (int i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtGreen = image[i][j].rgbtRed;
            image[i][j].rgbtBlue = image[i][j].rgbtRed;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed = 0;
    int sepiaGreen = 0;
    int sepiaBlue = 0;
    //checks each row
    for (int i = 0; i < height; i++)
    {
        //checks each column
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round(.393 *  image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            //checks if the rgb value exceeds max value
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            //copy the new rgb value into element
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int j = 0;
    //checks each row
    for (int i = 0; i < height; i++)
    {
        //checks each column
        for (j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int pixn;
    int j = 0;
    //create a copy of the image array
    for (int i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    //checks each row
    for (int i = 0; i < height; i++)
    {
        //checks each column
        for (j = 0; j < width; j++)
        {
            float red_sum = 0;
            float green_sum = 0;
            float blue_sum = 0;
            int count = 0;
            //starts checking if pixel exists or is out of the array boundary
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    //if the pixel is out of boundary it reloops and ignore the sums
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    red_sum += copy[i + k][j + l].rgbtRed;
                    green_sum += copy[i + k][j + l].rgbtGreen;
                    blue_sum += copy[i + k][j + l].rgbtBlue;
                    count++;
                }
            }
            image[i][j].rgbtRed = round(red_sum / count);
            image[i][j].rgbtGreen = round(green_sum / count);
            image[i][j].rgbtBlue = round(blue_sum / count);
        }
    }
    return;
}
