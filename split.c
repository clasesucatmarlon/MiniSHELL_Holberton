#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - print all args
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    char *str, *str2;
    const char *del = av[2];
    char **array, *tok;
    int i = 0, j = 0;
    
    str = av[1];
    str2 = strdup(str);

    if (ac == 3)
    {
        tok = strtok(str, del);
        while (tok != NULL)
        {
            i++;
            tok = strtok(NULL, del);
        }       

        array = malloc(sizeof(char *) * i);
        tok = strtok(str2, del);
        i = 0;

        while (tok != NULL)
        {
            array[i] = malloc(sizeof(char) * strlen(tok));
            array[i] = tok;
            i++;
            tok = strtok(NULL, del);
        }
        
        /* instead of return - print */
        for(j = 0; j < i; j++)
        {
            printf("%s\n", array[j]);
        }

        /* Falta liberar free() */
    }

    return (0);
}