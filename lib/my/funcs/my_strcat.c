/*
** EPITECH PROJECT, 2023
** B-PSU-200-NAN-2-1-minishell1-thomas.rochefeuille
** File description:
** my_strcat
*/

#include "../include/my.h"

char *my_strcat(char *dest, const char *src)
{
    int size = my_strlen(dest) + my_strlen(src);
    char *buffer = my_calloc(sizeof(char), size + 1);
    int var = 0;

    for (int i = 0; dest[i] != '\0' && dest[i] != '\n'; i++, var++)
        buffer[var] = dest[i];

    for (int i = 0; src[i] != '\0' && src[i] != '\n'; i++, var++)
        buffer[var] = src[i];

    buffer[var] = '\0';
    return (buffer);
}
