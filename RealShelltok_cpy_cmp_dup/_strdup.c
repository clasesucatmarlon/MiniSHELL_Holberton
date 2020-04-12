#include "shellh.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string to be copied
 * Return: copied string
 */
char *_strdup(char *str)
{
    int i, len;
    char *str2;
 
    if (!str)
        return (NULL);

    len = _strlen(str);
    str2 = malloc(sizeof(char) * len + 1);
    
    if (!str2)
    {
        perror("Malloc failed\n");
        exit(errno);
    }
    for (i = 0; i < len; i++)
        str2[i] = str[i];

    str2[i] = 0;
    return (str2);
}
