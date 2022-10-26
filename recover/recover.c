#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    const int BLOCK_SIZE = 512;
    int *buffer = malloc(3 * sizeof(int));
    typedef uint8_t buffer[BLOCK_SIZE];
    int count = 0;
    


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

    while (fread(buffer, 1, BLOCK_SIZE, input) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            sprintf(input, "%03i.jpg", 2);
            FILE *img = fopen(input, "w");
            fwrite(input, BLOCK_SIZE, 1, output);
        }

    }
}