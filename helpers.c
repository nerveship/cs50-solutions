#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //create a loop that cycles through each row of pixels
    //create a loop that cycles through each pixel of that row
    //calculate the average RGB value of each pixel and set each colour value to that average
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double avgcolour;
            avgcolour = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = round(avgcolour);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //create a loop that cycles through each row of pixels
    //create a loop that cycles through each pixel of that row
    //calculate the sepiaRed, sepiaGreen, & speiaBlue for using the agorithms on the pset
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed  + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed  + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed  + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
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
            image[i][j].rgbtRed = round(sepiaRed);
            image[i][j].rgbtBlue = round(sepiaBlue);
            image[i][j].rgbtGreen = round(sepiaGreen);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //create a loop that cycles through each row of pixels
    //create a loop that cycles through each pixel of that row
    //swap each horizontal pixel on opposite sides
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create temporary array of RGBTRIPLE
    //create a loop that cycles through each row of pixels
    //create a loop that cycles through each pixel of that row
    //check values pixels within 1 row and 1 column
    //calculate the average colour of all 9 pixels around center pixels
    //account for pixels on the side, top and bottom and ignore anything out of range
    //change pixel to new colour value

    float new_red, new_blue, new_green;
    int count = 0;
    //create temporary array
    RGBTRIPLE imgCopy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imgCopy[i][j] = image[i][j];
        }
    }

    //cycle through height
    for (int i = 0; i < height; i++)
    {
        //cycle through width
        for (int j = 0; j < width; j++)
        {
            //reset counts
            count = new_red = new_blue = new_green = 0;
            //cycle through rows around pixel
            for (int k = -1; k <= 1; k++)
            {
                //cycle through columns around pixel
                for (int p = -1; p <=1; p++)
                {
                    if (i + k >= 0 && i + k < height && j + p >= 0 && j + p < width)
                    {
                        count++;
                        new_red += imgCopy[i + k][j + p].rgbtRed;
                        new_green += imgCopy[i + k][j + p].rgbtGreen;
                        new_blue += imgCopy[i + k][j + p].rgbtBlue;
                    }
                }
            }
            //copy blurred values to original picture
            image[i][j].rgbtBlue = round(new_blue / count);
            image[i][j].rgbtGreen = round(new_green / count);
            image[i][j].rgbtRed = round(new_red / count);
        }
    }
    return;
}
