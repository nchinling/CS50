#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
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
