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

    //create temporary array
    RGBTRIPLE imgCopy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imgCopy[i][j] = image[i][j];
        }
    }

    for (int i = 0, red, green, blue, counter; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = green = blue = counter = 0;

            if (i >= 0 && j >= 0)
            {
                red += imgCopy[i][j].rgbtRed;
                green += imgCopy[i][j].rgbtGreen;
                blue += imgCopy[i][j].rgbtBlue;
                counter++;
            }
            if (i >= 0 && j - 1 >= 0)
            {
                red += imgCopy[i][j-1].rgbtRed;
                green += imgCopy[i][j-1].rgbtGreen;
                blue += imgCopy[i][j-1].rgbtBlue;
                counter++;
            }
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                red += imgCopy[i][j+1].rgbtRed;
                green += imgCopy[i][j+1].rgbtGreen;
                blue += imgCopy[i][j+1].rgbtBlue;
                counter++;
            }
            if (i - 1 >= 0 && j >= 0)
            {
                red += imgCopy[i-1][j].rgbtRed;
                green += imgCopy[i-1][j].rgbtGreen;
                blue += imgCopy[i-1][j].rgbtBlue;
                counter++;
            }
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                red += imgCopy[i+1][j].rgbtRed;
                green += imgCopy[i+1][j].rgbtGreen;
                blue += imgCopy[i+1][j].rgbtBlue;
                counter++;
            }
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                red += imgCopy[i+1][j-1].rgbtRed;
                green += imgCopy[i+1][j-1].rgbtGreen;
                blue += imgCopy[i+1][j-1].rgbtBlue;
                counter++;
            }
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                red += imgCopy[i+1][j+1].rgbtRed;
                green += imgCopy[i+1][j+1].rgbtGreen;
                blue += imgCopy[i+1][j+1].rgbtBlue;
                counter++;
            }
            image[i][j].rgbtRed = round(red / (counter * 1.0));
            image[i][j].rgbtGreen = round(green / (counter * 1.0));
            image[i][j].rgbtBlue = round(blue / (counter * 1.0));
        }
        return;
    }
}
