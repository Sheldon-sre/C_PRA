#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress()
{
    int seen_char = getchar();
    int next_char;
    int repeat_counter = 1;
    while ((next_char = getchar()) != EOF)
    {
        if (next_char == seen_char)
        {
                repeat_counter++;
                if (repeat_counter >= 255)
                {
                        putchar(seen_char);
                        putchar(repeat_counter);
                        repeat_counter = 0;
                }
        }
        else
        {
                putchar(seen_char);
                putchar(repeat_counter);
                seen_char = next_char;
                repeat_counter = 1;
        }
    }
    putchar(seen_char);
    putchar(repeat_counter);
}

void decompress()
{
    while(1)
    {
        int c = getchar();
        if (c == EOF)
            break;
        int count = getchar();

        for(int i=0; i<count; i++)
        {
            putchar(c);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s [compress|decompress]\n", argv[0]);
        exit(-1);
    }

    if (!strcmp(argv[1],"compress"))
    {
        compress();
    }
    else if (!strcmp(argv[1],"decompress"))
    {
        decompress();
    }
    else
    {
        printf("Usage: %s [compress|decompress]\n", argv[0]);
        exit(-1);
    }
    return 0;
}