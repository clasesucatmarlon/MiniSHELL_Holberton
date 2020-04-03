#include <stdio.h>
#include <unistd.h>

/**
 * main - print all args
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{    
	int i = 0, size = 0;
    char *str = av[1];
    char *del = av[2];
    char *tok[];

    while(str[i] != NULL) /* while av[i] */
    {
        if(str[i] == del[0])
            size++;    
        i++;
    }

    tok = malloc(sizeof(*char) * size + 1);

    /* en construccion - avanzado */

    

    /* while(str[i])
    {
        if(str[i] == del[0])
            i++;
    } */


	return (0);
}