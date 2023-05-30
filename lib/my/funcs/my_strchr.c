/*
** EPITECH PROJECT, 2023
** Base-project-for-C
** File description:
** my_strchr
*/

#include <stddef.h>

char *my_strchr(char *str, int ch)
{
    char *p = str;

    while (*p != ch) {
        if (*p == '\0')
            return (NULL);
        p++;
    }
    return (p);
}
