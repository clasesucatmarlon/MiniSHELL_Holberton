#include "shellh.h"

/**
 * _split - print all args
 *
 * @line: char *str from stdin
 * Return: *args[] or NULL if line == NULL.
 */
char **_split(char *line)
{
    char *str, *str2, *str3;
    char **array, *tok;
    int i = 0;

    if (line)
    {
        /* duplicate str to avoid _strtok damage and delete /n */
        str = _strdup(_strtok(line, "\n"));
        str2 = _strdup(str);

        tok = _strtok(str, " ");

        /* count number of tokens */
        while (tok != NULL)
        {
            i++;
            tok = _strtok(NULL, " ");
        }
        array = malloc(sizeof(char *) * (i + 1));
        tok = _strtok(str2, " ");
        i = 0;

        /* fill array with each token */
        while (tok != NULL)
        {
            str3 = _strdup(tok);
            array[i] = malloc(sizeof(char) * strlen(str3));
            array[i] = str3;
            i++;
            tok = _strtok(NULL, " ");
        }
        array[i] = NULL;
        
        /* free memory */
        free(str);
        free(str2);
        return (array);
    }

    return (NULL);
}

/**
 * _processing - process args and choose how to execute it
 *
 * @args: char **str
 * Return: *args[] or NULL if line == NULL.
 */
int _processing(char **args){

    int i = 0;

    built_in_t b_in[] = {
		{"exit", own_exit},
		{"env", _print_env},
		{NULL, NULL}
	};
    
    while (b_in[i].cmd)
	{
		if (_strcmp(args[0], b_in[i].cmd) == 0)
		{
			return (b_in[i].f(args));
		}
		i++;
	}
    
    _execve(args);   
    return (1);
}
