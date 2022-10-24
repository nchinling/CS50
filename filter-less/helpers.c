#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //For each row
    for (int i = 0; i < height; i++)
    {
        //For each column
        for (int j = 0; j < width; j++)
        {
            //find average
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            //assign average to each rgbt
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        //For each column
        for (int j = 0; j < width; j++)
        {

            //assign average to each rgbt
            int sepiaRed = round(image[i][j].rgbtBlue*0.189 + image[i][j].rgbtGreen*0.189 + image[i][j].rgbtRed*0.769);
            int sepiaGreen = round(image[i][j].rgbtBlue*0.168 + image[i][j].rgbtGreen*0.686 + image[i][j].rgbtRed*0.349);
            int sepiaBlue = round(image[i][j].rgbtBlue*0.131 + image[i][j].rgbtGreen*0.534 + image[i][j].rgbtRed*0.272);

            //limit value of each rgbt to 255 (white)
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{for (int i = 0; i < height; i++)
    {
        //For each column
        for (int j = 0; j < width; j++)
        {

 
        }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
