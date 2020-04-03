#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - prints "$ ", wait for the user to enter a command,
 * execute it and wait for another. Super-Simple-Shell
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line;
	size_t len = 0;
	int readed = 0, status;
	char *array[2], *tok;
	pid_t pid;

	array[1] = NULL;
	line = malloc(sizeof(char));
	/* Imprime $ y espera el primer comando */
	printf("$ ");
	readed = getline(&line, &len, stdin);

	/* Ciclo para esperar un nuveo comando al terminar execv  */
	while (line && readed > 1)
	{
		/* obtener linea - 1 solo elemento - sin arg */
		tok = strtok(line, "\n");
		array[0] = tok;
		/* printf("array[0] = %s\n",array[0]);
		printf("array[1] = %s\n",array[1]); */


		/* Crear hijo y controlar error*/
		pid = fork();
		if (pid == -1)
		{
			perror("Error: forking");
			return (1);
		
		}
		if (pid == 0)
		{
			
			if (execve(array[0], array, NULL) == -1)
			{
				perror("Error: executing");
			}
		}
		else
		{
			wait(&status);
		}
		/*  Imprime $ yotro coman Espera por do */
		printf("$ ");
		getline(&line, &len, stdin);
	}
	free(line);
	return (0);
}
