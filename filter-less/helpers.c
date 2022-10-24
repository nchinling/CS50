#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //For each row
    for (int i = 0; i < height; i++)
    {
        //For each column
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pix = image[h][w];
            BYTE value = round((pix.rgbtBlue + pix.rgbtGreen + pix.rgbtRed) / 3.0);
            pix.rgbtBlue = value;
            pix.rgbtGreen = value;
            pix.rgbtRed = value;
            image[h][w] = pix;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            RGBTRIPLE pix = image[h][w];
            double sepiaRed = 0.393 * pixel.rgbtRed + 0.769 * pixel.rgbtGreen + 0.189 * pixel.rgbtBlue;
            double sepiaGreen = 0.349 * pixel.rgbtRed + 0.686 * pixel.rgbtGreen + 0.168 * pixel.rgbtBlue;
            double sepiaBlue = 0.272 * pixel.rgbtRed + 0.534 * pixel.rgbtGreen + 0.131 * pixel.rgbtBlue;

            pix.rgbtBlue = round_and_cap(sepiaBlue);
            pix.rgbtGreen = round_and_cap(sepiaGreen);
            pix.rgbtRed = round_and_cap(sepiaRed);
            image[h][w] = pix;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
