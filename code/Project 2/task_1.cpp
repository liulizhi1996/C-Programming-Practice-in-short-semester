#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        perror("usage: ./reverse.out [string]\n");
    }

    int len;
    for (int i = argc-1; i > 0; --i)
    {
    	len = (int)strlen(argv[i]);
    	for (int j = len-1; j >= 0; --j)
    		printf("%c", argv[i][j]);
    	printf(" ");
    }
    printf("\n");

    return 0;
}
