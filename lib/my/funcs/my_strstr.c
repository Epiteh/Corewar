/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** my_strstr
*/

#include "../include/my.h"

char *my_strstr(char *str, char *needstr)
{
    int len = my_strlen(needstr);

    for (; *str; str++) {
        if (my_strncmp(str, needstr, len) == 0) {
            return (str);
        }
    }
    return (NULL);
}
