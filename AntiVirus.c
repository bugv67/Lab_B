#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct virus
{
    unsigned short SigSize;
    unsigned char *VirusName;
    unsigned char *Sig;
} virus;
virus *readVirus(FILE *file)
// Input: file pointer and returns a virus* that represents the next virus in the file.
//  To read from a file, use fread(). See man fread(3) for assistance.
{
    virus *v = (virus *)malloc(sizeof(virus));
    if (v == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    // read the virus signature size, 1 short (2 bytes)
    if (fread(&v->SigSize, sizeof(unsigned short), 1, file) != 1)
    { // end of filr or error - return NULL
        free(v);
        return NULL;
    }
    // read the virus name, 16 bytes
    v->VirusName = malloc(16);
    // rad the virus signature, SigSize N bytes
    v->Sig = (unsigned char *)malloc(v->SigSize);
    if (v->VirusName == NULL || v->Sig == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        if (v->VirusName)
            free(v->VirusName);
        if (v->Sig)
            free(v->Sig);
        free(v);
        return NULL;
    }
    fread(v->VirusName, sizeof(unsigned char), 16, file);
    fread(v->Sig, sizeof(unsigned char), v->SigSize, file);
    return v;
}

void printVirus(virus *virus, FILE *output)
// Input: virus and a pointer to an output file.
// Output: prints the virus to the given output.
// virus name(in ASCII),  virus signature length(in decimal), virus signature(in hexadecimal representation).
{
    if (virus == NULL || output == NULL)
    {
        fprintf(stderr, "Not valid input \n");
        return;
    }
    fprintf(output, "Virus name: %s\n", virus->VirusName);
    fprintf(output, "Virus size: %d\n", virus->SigSize);
    fprintf(output, "Virus signature:\n");
    for (int i = 0; i < virus->SigSize; i++)
    {
        fprintf(output, "%02X ", virus->Sig[i]);
    }
    fprintf(output, "\n");
}
int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        FILE *file = fopen(argv[1], "rb");
        if (file == NULL)
        {
            printf("Error, cannot open the file\n");
            return 0;
        }
        char magic[4]; // good file?
        if (fread(magic, 1, 4, file) != 4)
        {
            fprintf(stderr, "Error reading magic number\n");
            fclose(file);
            return 1;
        }
        else
        {
            if (memcmp(magic, "VIRL", 4) != 0 && memcmp(magic, "VIRB", 4) != 0)
            {
                fprintf(stderr, "Invalid file- no magic word \n");
                fclose(file);
                return 1;
            }
            else
            {
                virus *v = readVirus(file);
                while (v != NULL)
                {
                    printVirus(v, stdout);
                    free(v->VirusName);
                    free(v->Sig);
                    free(v);
                    v = readVirus(file);
                }
            }
        }
        fclose(file);
    }
    else
        printf("No file has provided\n");
    return 0;
}
