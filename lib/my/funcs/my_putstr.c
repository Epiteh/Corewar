/*
** EPITECH PROJECT, 2023
** Base-project-for-C
** File description:
** my_putstr
*/

#include "../include/my.h"
#include <unistd.h>

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
