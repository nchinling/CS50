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
            int sepiaRed = round(image[i][j].rgbtBlue  * 0.189 + image[i][j].rgbtGreen * 0.769 + image[i][j].rgbtRed * 0.393);
            int sepiaGreen = round(image[i][j].rgbtBlue * 0.168 + image[i][j].rgbtGreen * 0.686 + image[i][j].rgbtRed * 0.349);
            int sepiaBlue = round(image[i][j].rgbtBlue * 0.131 + image[i][j].rgbtGreen * 0.534 + image[i][j].rgbtRed * 0.272);

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
{
    for (int i = 0; i < height; i++)
    {
        //For each column
        for (int j = 0; j < width / 2; j++)
        {
            //copy most left pixel to temp
            RGBTRIPLE temp = image[i][j];

            //most right pixel replaces most left pixel
            image[i][j] = image[i][width - (j + 1)];

            //temp (previously most left pix) replaces most right pixel
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        //For each column
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];

        }
    }

    for (int i = 0; i < height; i++)
    {
        //For each column
        for (int j = 0; j < width; j++)
        {
            float sumGreen = 0;
            float sumBlue = 0;
            float sumRed = 0;
            float counter = 0;

            //Get neighbouring pixels
            for (int y = -1; y < 2; y++)
            {
                for (int x = -1; x < 2; x++)
                {
                    int neighbourY = i + y;
                    int neighbourX = j + x;

                    //Check if pixel is valid
                    if (neighbourY < 0 || neighbourY > (height - 1) || neighbourX < 0 || neighbourX > (width - 1))
                    {
                        continue;
                    }

                    sumBlue = sumBlue + image[neighbourY][neighbourX].rgbtBlue;
                    sumGreen = sumGreen + image[neighbourY][neighbourX].rgbtGreen;
                    sumRed = sumRed + image[neighbourY][neighbourX].rgbtRed;

                    counter = counter + 1;

                    temp[i][j].rgbtBlue = round(sumBlue / counter);
                    temp[i][j].rgbtGreen = round(sumGreen / counter);
                    temp[i][j].rgbtRed = round(sumRed / counter);

                }
            }

        }
    }

    //copy temp into original image
    for (int i = 0; i < height; i++)
    {
        //For each column
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }

    return;
}
