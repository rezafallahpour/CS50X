#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;
            int average = round((red + green + blue) / 3);

            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float ored = image[i][j].rgbtRed;
            float ogreen = image[i][j].rgbtGreen;
            float oblue = image[i][j].rgbtBlue;
            int sred = round(0.393 * ored + 0.769 * ogreen + 0.189 * oblue);
            int sgreen = round(0.349 * ored + 0.686 * ogreen + 0.168 * oblue);
            int sblue = round(0.272 * ored + 0.534 * ogreen + 0.131 * oblue);
            if (sred > 255)
            {
                sred = 255;
            }
            if (sgreen > 255)
            {
                sgreen = 255;
            }
            if (sblue > 255)
            {
                sblue = 255;
            }

            image[i][j].rgbtRed = sred;
            image[i][j].rgbtGreen = sgreen;
            image[i][j].rgbtBlue = sblue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tm = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = tm;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE ttm[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            ttm[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int ttred, ttblue, ttgreen;
            ttred = ttblue = ttgreen = 0;
            float count = 0.0;
            for (int q = -1; q < 2; q++)
            {
                for (int w = -1; w < 2; w++)
                {
                    int ccq = i + q;
                    int ccw = j + w;
                    if (ccq < 0 || ccq > (height - 1) || ccq < 0 || ccw > (width - 1))

                    {
                        continue;
                    }
                    ttred += image[ccq][ccw].rgbtRed;
                    ttblue += image[ccq][ccw].rgbtBlue;
                    ttgreen += image[ccq][ccw].rgbtGreen;
                    count++;
                }
                ttm[i][j].rgbtRed = round(ttred / count);
                ttm[i][j].rgbtBlue = round(ttblue / count);
                ttm[i][j].rgbtGreen = round(ttgreen / count);
            }
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = ttm[i][j].rgbtRed;
            image[i][j].rgbtBlue = ttm[i][j].rgbtBlue;
            image[i][j].rgbtGreen = ttm[i][j].rgbtGreen;
        }
    }
    return;
}
