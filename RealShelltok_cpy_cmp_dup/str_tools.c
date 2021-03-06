#include "shellh.h"
/**
 * is_delim - check if char is equal to delim
 * @c: character
 * @delim: " "
 * Return: 0 if no match, 1 if matched
 */
 
int is_delim(char c, const char *delim)
{
	while (delim && *delim)
	{
		if (c == *delim)
		{
			return (1);
		}
		++delim;
	}
	return (0);
}
 
/**
 * _strtok -tokenizes a string and turn to array
 * @src: string from getline
 * @delim: " ";
 * Return: individual token in array format
 */
 
char *_strtok(char *src, const char *delim)
{
	static char *s;
	static unsigned int i;
	char *result = NULL;
	int is_space = 0;
 
	if (src)
	{
		s = src;
		for (i = 0; s[i]; i++)
		{
			if (is_delim(s[i], delim))
				s[i] = '\0';
		}
	}
 
	if (s == NULL || *s == '\0')
		return (NULL);

	result = s;
	i = _strlen(s);

	if (s[i] == '\0' && _strlen(s) > 0)
		is_space = 1;
		
	s = s + _strlen(s) + is_space;
	return (result);
}

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
