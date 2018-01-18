#include <stdio.h>
#include <stdlib.h>

void showFile(char *filename, char *arr, int h, int w)
{
    FILE* fp = fopen(filename, "r");
    int i = 0, j = 0, pixel;

    while (!feof(fp))
    {
        fscanf(fp, "%x", &pixel);
        *(arr+i*w+j) = (char)pixel;
        j++;
        if (j == w)
        {
            j = 0;
            i++;
        }
    }
    fclose(fp);
}

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

void mirrorTrans(char *arr, int h, int w)
{
    for (int i = 0; i < h; ++i)
    {
        for (int j = w-3; j > 0; --j)
        {
            if (*(arr+i*w+j) == '/')
                printf("\\");
            else if (*(arr+i*w+j) == '}')
                printf("{");
            else if (*(arr+i*w+j) == '(')
                printf(")");
            else if (*(arr+i*w+j) == ')')
                printf("(");
            else if (*(arr+i*w+j) == '\\')
                printf("/");
            else if (*(arr+i*w+j) == 'p')
                printf("q");
            else
                printf("%c", *(arr+i*w+j));
        }
        printf("%c", *(arr+i*w+w-2));
        printf("%c", *(arr+i*w+w-1));
    }
}

int main()
{
    char filename[] = "pet.txt";
    char arr[22][48] = { 0 };
    int h = 22, w = 48;

    printf("Before transpose:\n");
    showFile(filename, &arr[0][0], h, w);
    printf("\nAfter transpose:\n");
    mirrorTrans(&arr[0][0], h, w);

    return 0;
}
