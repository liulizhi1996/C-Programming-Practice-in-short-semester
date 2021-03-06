#include <stdio.h>

int screen[18][18] = {32, 32, 32, 32, 32, 32, 32, 32, 32, 95, 45, 126, 126, 126, 126, 126, 45, 95,
                      32, 32, 32, 32, 32, 32, 32, 32, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32,
                      -93, -34, 45, 45, 45, -93, -34, 45, 32, 32, 32, 92, 32, 32, 32, 32, 32, 10,
                      32, 32, 32, 32, 32, 32, 32, 32, 124, -93, -83, 32, 32, -93, -83, 32, 96, 92,
                      32, 32, 32, 124, 32, 32, 32, 32, 10, 32, 32, 32, 32, 32, 32, 32, 124, 32,
                      -93, -64, -95, -95, -93, -64, 32, 32, 32, 124, 47, 126, 92, 32, 32, 32, 32, 10,
                      32, 32, 32, 32, 44, 126, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
                      32, 32, 32, 124, 32, 32, 32, 32, 10, 32, 32, 32, 32, 124, 32, 32, 32, 32,
                      79, 32, 32, 32, 32, 32, 32, 32, 32, 32, 95, 45, 126, 32, 32, 32, 32, 10,
                      32, 32, 32, 32, 32, 126, 45, 95, 95, 95, 95, 95, 95, 95, 95, 95, 45, 45,
                      126, 32, 32, 126, 92, 32, 32, 32, 10, 32, 32, 32, 47, 32, 32, 44, 32, 32,
                      32, 46, 32, 32, 32, 32, 32, 46, 32, 32, 32, 92, 32, 32, 92, 32, 32, 10,
                      32, 32, 47, 95, 44, 39, 124, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
                      32, 32, 124, 96, 95, 95, 39, 32, 10, 32, 32, 32, 32, 32, 32, 124, 32, 32,
                      32, 124, 96, 46, 94, 46, 39, 124, 32, 32, 32, 124, 32, 32, 32, 32, 32, 10,
                      32, 32, 32, 32, 32, 32, 124, 32, 32, 32, 44, 40, 32, 32, 41, 47, 32, 92,
                      32, 32, 92, 95, 32, 32, 32, 32, 10, 32, 32, 32, 32, 32, 47, 95, 95, -93,
                      -81, 32, 32, 96, 39, 32, 32, 32, 32, -93, -36, 95, 95, 92, 32, 32, 32, 10};

int main()
{
    int *ptr = *screen;

    for (int i = 0; i < 18*18; ++i, ++ptr)
    {
        printf("%c", (char)((*ptr + 128) % 128));
    }

    return 0;
}
