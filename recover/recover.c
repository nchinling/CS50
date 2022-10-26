#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    const int BLOCK_SIZE = 512;
    BYTE buffer[BLOCK_SIZE];
    FILE *output = NULL;
    int count = 0;
    char *filename = malloc(8*sizeof(char));

 // Check command-line arguments. Only 1
    if (argc != 2)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }

    while (fread(buffer, BLOCK_SIZE, 1, input) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            //create filename
            sprintf(filename, "%03i.jpg", count);

            //open filename to write
            output = fopen(filename, "w");

            //increase count for naming of files
            count = count + 1;
        }

        if (output != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, output);
        }

    }

    free(filename);
    fclose(output);
    fclose(input);

    return 0;
}