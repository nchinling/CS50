#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    const int BLOCK_SIZE = 512;
    int *buffer = malloc(3 * sizeof(int));
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
        return 1;
    }

    while (fread(buffer, 1, BLOCK_SIZE, *input) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            sprintf(filename, "%03i.jpg", 2);
            FILE *img = fopen(filename, "w");
        }


    }
}