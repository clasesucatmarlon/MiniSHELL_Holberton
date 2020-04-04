#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
void _getPATH()
{
    extern char **environ;
    char *tok, *name, *s;
    int i = 0;
    char *tmpenv;

    name = "PATH";

    /* while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    } */

    /* print to all PATH before strtok(PATH, ":") */
    printf("getenv en func %s --> %s\n\n", name, getenv(name));

    i = 0;
    while (environ[i])
    {
        /* evita dañar el environ */
        tmpenv = strdup(environ[i]);
        

        /* strtok sobre la copia */ 
        tok = strtok(tmpenv, "=");
        

        if (strcmp(name, tok) == 0)
        {            
            tok = strtok(NULL, "=");
            /* avoid valgrind error */
            s = strdup(tok);
            tok = strtok(s, ":");
            while(tok)
            {
                printf("%s\n", tok);
                tok = strtok(NULL, ":");
            }
            free(s);
            free(tmpenv);
            return;
        }
        free(tmpenv);
        i++;
    }
    
}

/**
 * main - prints the environment using _getenv
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{    
    _getPATH();

    return (0);
}
