#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //TODO
    //OPEN MEMORY CARD
    //LOOK FOR BEGINNING OF JPEG
    //OPEN A NEW JPEG FILE
    //WRITE 512 bytes until a new JPEG is found
    //STOP AT THE END OF THE FILE
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    else
    {
        //open memory card
        char *input_file_name = argv[1];
        FILE *input_pointer = fopen(input_file_name, "r");
        if (input_pointer == NULL)
        {
            printf("Error: cannot open file");
            return 2;
        }

        BYTE buffer[512];
        int count = 0;
        FILE *img_pointer = NULL;
        char filename[8];

        while (fread(&buffer, 512, 1, input_pointer))
        {
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                sprintf(filename, "%03i.jpg", count);
                img_pointer = fopen(filename, "w");
                count++;
            }
            if (!(count == 0))
            {
                fwrite(&buffer, 512, 1, img_pointer);
            }
        }
        fclose(input_pointer);
        fclose(img_pointer);
        return 0;
    }
}
