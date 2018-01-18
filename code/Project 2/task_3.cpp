#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char english_months[][15] = {"", "January", "February", "March", "April", "May", "June", 
                             "July", "August", "September", "October", "November", "December"};
char english_days[][15] = {"", "first", "second", "third", "fourth", "fifth", "sixth", "seventh", 
                           "eighth", "ninth", "tenth", "eleventh", "twelfth", "thirteenth", 
                           "fourteenth", "fifteenth", "sixteenth", "seventeenth", "eighteenth", 
                           "nineteenth", "twentieth", "twenty-first", "twenty-second", "twenty-third", 
                           "twenty-fourth","twenty-fifth", "twenty-sixth", "twenty-seventh",
                           "twenty-eighth", "twenty-ninth", "thirtieth", "thirty-first"};

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        perror("usage: ./datefile.out [date]\n");
    }

    FILE *fp_in = fopen("in.txt", "w");
    FILE *fp_out = fopen("out.txt", "w");
    int month, day, is_legal, j;
    for (int i = 1; i < argc; ++i)
    {
        fprintf(fp_in, "%s\n", argv[i]);

        is_legal = 1;

    	month = 0;
        for (j = 0; argv[i][j] && argv[i][j] != '.'; ++j)
        {
            if ('0' <= argv[i][j] && argv[i][j] <= '9')
                month = month * 10 + (argv[i][j] - '0');
            else
            {
                is_legal = 0;
                break;
            }
        }
        if (!is_legal)
        {
            fprintf(fp_out, "Error\n");
            continue;
        }

        day = 0;
        for (j++; argv[i][j]; ++j)
        {
            if ('0' <= argv[i][j] && argv[i][j] <= '9')
                day = day * 10 + (argv[i][j] - '0');
            else
            {
                is_legal = 0;
                break;
            }
        }
        if (!is_legal)
        {
            fprintf(fp_out, "Error\n");
            continue;
        }

        if (1 <= month && month <= 12)
        {
            if (1 <= day && day <= days[month])
                fprintf(fp_out, "%s the %s\n", english_months[month], english_days[day]);
            else
            {
                fprintf(fp_out, "Error\n");
                continue;
            }
        }
        else
        {
            fprintf(fp_out, "Error\n");
            continue;
        }
    }
    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
