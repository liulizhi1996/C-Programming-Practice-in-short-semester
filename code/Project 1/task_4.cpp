#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

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

void flood_fill(char *arr, int h, int w, int *hit, int x, int y)
{
    if (x < 0 || x >= h || y < 0 || y >= w || *(hit+x*w+y))
        return;

    if (*(arr+x*w+y) == ' ' || *(arr+x*w+y) == '\n' || *(arr+x*w+y) == '\r')
    {
        *(hit+x*w+y) = 1;
        flood_fill(arr, h, w, hit, x-1, y);
        flood_fill(arr, h, w, hit, x+1, y);
        flood_fill(arr, h, w, hit, x, y-1);
        flood_fill(arr, h, w, hit, x, y+1);
    }
}

void coverHit(char *arr, int h, int w)
{
    int **hit;
    hit = (int **)malloc(sizeof(int *) * h);
    for (int i = 0; i < h; i++)
    {
        hit[i] = (int *)malloc(sizeof(int) * w);
        memset(hit[i], 0, sizeof(int) * w);
    }

    flood_fill(arr, h, w, &hit[0][0], 0, 0);

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w-2; ++j)
        {
            if (*(*hit+i*w+j))
                printf("*");
            else
                printf(" ");
        }
        printf("\r");
        printf("\n");
    }
}

int main()
{
    char filename1[] = "pet.txt", filename2[] = "devil.txt";
    char pet[22][48] = { 0 }, devil[16][56] = { 0 };
    int pet_h = 22, pet_w = 48, devil_h = 16, devil_w = 56;

    showFile(filename1, &pet[0][0], pet_h, pet_w);
    printf("\n");
    showFile(filename2, &devil[0][0], devil_h, devil_w);
    printf("\n\n");
    coverHit(&pet[0][0], pet_h, pet_w);

    return 0;
}

