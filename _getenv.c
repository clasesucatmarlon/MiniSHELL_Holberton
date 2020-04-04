#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
char *_getenv(const char *name)
{
    extern char **environ;
    char *tok, *s;
    int i = 0;
    char *tmpenv;

    /* while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    } */
    printf("getenv en func %s --> %s\n", name, getenv(name));

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
            free(tmpenv);
            return (s);
        }
        free(tmpenv);
        i++;
    }
    
    return (NULL);
}

/**
 * main - prints the environment using _getenv
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    char *_env;
    _env = _getenv(av[1]);

    printf("_env %s --> %s\n", av[1], _env);
    printf("getenv %s --> %s\n", av[1], getenv(av[1]));
    free(_env);

    

   return (0);
}
