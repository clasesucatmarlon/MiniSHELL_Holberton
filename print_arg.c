#include <stdio.h>
#include <unistd.h>

/**
 * main - print all args
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{    
	/* int i = 0; */

    while(*av) /* while av[i] */
    {
        printf("%s\n", *av); /* printf("%s\n", av[i]); */
        av++; /* i++ */
    }
	return (0);
}