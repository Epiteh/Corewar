/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** split
*/

#include "asm.h"
#include <string.h>

char **split_into_double(char *buffer, char *separator)
{
    char **array = my_calloc((my_strlen(buffer) + 3), sizeof(char *));
    char *token = my_strtok(buffer, separator);
    unsigned int i = 0;

    for (; token != NULL; i++) {
        array[i] = my_strdup(token);
        token = my_strtok(NULL, separator);
    }
    return (array);
}

char *split_into_simple(char *buffer, char *separator)
{
    char *name = my_calloc((my_strlen(buffer) + 3), sizeof(char));
    char *token = my_strtok(buffer, separator);

    while (token != NULL) {
        name = my_strcat(name, token);
        token = my_strtok(NULL, separator);
    }
    return (name);
}
