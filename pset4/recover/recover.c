#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 0;
    }

    FILE *inputfile = fopen(argv[1], "r");

    if (inputfile == NULL)
    {
        printf("couldnt open file ");
        return 1;
    }

    unsigned char buffer[512];

    int countimage = 0;

    FILE *outputfile = NULL;
    char *filename = malloc(8 * sizeof(char));
    while (fread(buffer, sizeof(char), 512, inputfile))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", countimage);

            outputfile = fopen(filename, "w");

            countimage++;
        }
        if (outputfile != NULL)
        {
            fwrite(buffer, sizeof(char), 512, outputfile);
        }
    }
    free(filename);
    fclose(outputfile);
    fclose(inputfile);

    return 0;
}