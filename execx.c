#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    // the command is executed whichever argv equals that string
    int f, j;
    if (strcmp(argv[3], "clear") == 0 && argc == 4)
    {
        printf("\033[H\033[J");
    }
    else if (strcmp(argv[3], "ls") == 0 && argc == 4)
    {
        for (int i = 0; i < atoi(argv[2]); i++)
        {
            system("/bin/ls");
        }
    }
    else if (strcmp(argv[3], "bash") == 0 && argc == 4)
    {
        for (int i = 0; i < atoi(argv[2]); i++)
        {
            system("/bin/bash");
        }
    }
    else if (strcmp(argv[3], "writef") == 0 && !strcmp(argv[4], "-f") && argv[5] != NULL && argc == 6)
    {
        for (int i = 0; i < atoi(argv[2]); i++)
        {
            // the fork runs until the number entered
            f = fork();
            if (f == 0)
            {
                j = execve("writef", argv, NULL);
                exit(0);
                perror("exec failed");
            }
            else
            {
                wait(&j);
            }
        }
    }
    else
    {
        // if the input is not equal to any command, the input is written
        printf("Wrong Command!");
    }
}
