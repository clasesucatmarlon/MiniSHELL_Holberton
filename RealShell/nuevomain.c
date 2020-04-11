#include "shellh.h"

/**
 * main - Simple_shell main function
 * 
 * @ac: args count
 * @av: args array
 *
 * Return: Always 0.
 */
int main(int ac, char *av[])
{
    char *line;
    size_t len = 0;
    int status = 1, interactive = 0;
    /* int j = 0; */
    char **args;
    int x = 1;
    
    line = malloc(sizeof(char));

    /* revisa si hay una entrada conectada con el stdin */
    if (isatty(STDIN_FILENO) != 0)
            interactive = 1;
    do
    {
        /* Imprime $ y espera el primer comando */
        if(interactive)
            printf("$ ");

        /* lee del stdin, controla ctrl + D */
        if (getline(&line, &len, stdin) == -1) {
            printf("\n");
            continue;
        }

        /*controla lineas vacias*/
        if(strcmp(line, "\n") == 0){
            continue;    
        }

        /* parte la linea y la almacena en un char **str */
        
        args = _split(line);
        
 /*        marlon */
        x = _check_builtin(args);
        /*  x = _check_builtin(args, line); */
        if (x == 1)
        {
            perror("comando no válido");
            printf("\n");
            continue;
        }
/*         else if (x == 0)
        {
            exit (98);
        } */
        



        /* marlon      */

        /* for(j = 0; args[j] != NULL; j++)
        {
            printf("posicion %d ----> %s\n",j , args[j]);
            
        } */

        /*procesa el array de str y ejecuta dependiendo del tipo */
        status = _processing(args);

    }while (status && interactive);
    free(line);
    free(args);

    return (0);
}

int _check_builtin(char **args)
{
    /* char *straux[] = {"exit", "env"}; */
    
    if (strcmp(args[0], "exit") == 0)
    {
        printf("Estoy en la funcion exit y hay que llamar esa función\n");
        exit (98);
        /* execve(args[0], args, NULL); */
        /* return (0); */
    }
    else if (strcmp(args[0], "env") == 0)
    {
        _
        printf("Estoy en la funcion env y hay que llamar a esa función");
        return (0);
    }
    return (1);
}
