/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** my_strtok
*/

#include "../include/my.h"
#include <stdlib.h>

char *find_next(char *str, char *separator, char **last)
{
    if (str)
        *last = str;
    else if (!*last)
        return (NULL);
    while (**last && my_strchr(separator, **last))
        (*last)++;
    if (!**last) {
        *last = NULL;
        return NULL;
    }
    return (*last);
}

char *find_end(char *token, char *separator, char **last)
{
    while (**last && !my_strchr(separator, **last))
        (*last)++;
    if (**last) {
        **last = '\0';
        (*last)++;
    } else {
        *last = NULL;
    }
    return (token);
}

char *my_strtok(char *str, char *separator)
{
    static char *last = NULL;
    char *next = find_next(str, separator, &last);
    char *end = NULL;

    if (!next)
        return NULL;
    end = find_end(next, separator, &last);
    return (end);
}
