#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - prints "$ ", wait for the user to enter a command,
 * prints it on the next line
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line;
	size_t len = 0;
	int i = 0;

	line = malloc(sizeof(char));

	printf("$ ");
	i = getline(&line, &len, stdin);
	printf("%s", line);
	printf("len: %d\n", (int) len);
	printf("getline return: %d\n", i);

	free(line);
	return (0);
}
