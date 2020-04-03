#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork + wait + execve:
 * executes the command ls -l /tmp
 * in 5 different child processes
 *
 * Return: Always 0.
 */
int main()
{
    int i, status;
    pid_t child_pid;
    char *av[] = {"/bin/ls", "-l", "/tmp", NULL};

    for (i = 0; i < 5; i++)
    {
        child_pid = fork();
        if (child_pid == 0)
        {
            if (execve(av[0], av, NULL) == -1)
            {
                perror("Error:");
            }
            
        }else
        {
            wait(&status);
            printf("wait %d finished\n", i);

        }        
    }
    return (0);
}