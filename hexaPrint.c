#include <stdio.h>

void Printhex(unsigned char *buffer, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%02X ", buffer[i]);
    }
    printf("\n");
}
int main(int argc, char **argv)
{
    unsigned char buffer[100];
    if (argc > 1)
    {
        FILE *file = fopen(argv[1], "rb");
        if (file == NULL)
        {
            printf("Error, cannot open the file\n");
            return 0;
        }
        int c = fread(buffer, sizeof(unsigned char), 100, file);
        while (c > 0)
        {
            Printhex(buffer, c);
            c = fread(buffer, sizeof(unsigned char), 100, file);
        }
        fclose(file);
        return 1;
    }
    else
        printf("No file has provided\n");
    return 0;
}