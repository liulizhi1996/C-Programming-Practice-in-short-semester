#include <stdio.h>
#include <stdlib.h>

void showFile(char *filename, char *arr, int h, int w)
{
    FILE* fp = fopen(filename, "r");
    int pixel;

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            fscanf(fp, "%x", &pixel);
            *(arr+i*w+j) = (char)pixel;
            printf("%c", *(arr+i*w+j));
        }
    }
    fclose(fp);
}

void sealDevil(char *arr, char *filename)
{
    FILE *fp = fopen(filename, "w");

    while (*arr)
    {
        fprintf(fp, "%d ", *arr);
        ++arr;
    }

    fclose(fp);
}

void unsealDevil(char *filename)
{
    FILE *fp = fopen(filename, "r");

    int ch;
    while (!feof(fp))
    {
        fscanf(fp, "%d", &ch);
        printf("%c", (char)ch);
    }

    fclose(fp);
}

int main()
{
    char filename1[] = "devil.txt", filename2[] = "NewSeal.txt";
    char devil[16][56] = { 0 };
    int h = 16, w = 56;

    showFile(filename1, &devil[0][0], h, w);
    printf("\n\n");
    sealDevil(&devil[0][0], filename2);
    unsealDevil(filename2);

    return 0;
}
