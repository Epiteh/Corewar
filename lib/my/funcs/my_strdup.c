/*
** EPITECH PROJECT, 2023
** Base-project-for-C
** File description:
** my_strdup
*/

#include "../include/my.h"

char *my_strdup(char const *str)
{
    char *res = my_calloc(my_strlen(str) + 1, sizeof(char));

    for (int i = 0; str[i] != '\0'; i++) {
        res[i] = str[i];
    }
    return (res);
}
