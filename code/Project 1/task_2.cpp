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

int main()
{
    char filename[] = "pet.txt";
    char arr[22][48] = { 0 };
    int h = 22, w = 48;

    showFile(filename, &arr[0][0], h, w);

    return 0;
}
