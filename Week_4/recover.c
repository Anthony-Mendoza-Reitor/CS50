#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check for correct input
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    // Open input file
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    // Buffer structure
    uint8_t buffer[512];
    // Output name
    char filename[8];
    int fileCounter = 0;
    FILE *img = NULL;
    // Read 512 bytes into buffer until there's no more 512
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Check JPEG start
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous file
            if (img != NULL)
            {
                fclose(img);
            }
            // New File
            sprintf(filename, "%03d.jpg", fileCounter);
            // Open a new file for writing
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create file.\n");
                return 1;
            }
            fileCounter++;
        }

        // write the data into fiile
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    // Close any remaining files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);
    return 0;
}
