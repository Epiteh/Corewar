/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** my_putstrerr
*/

#include "../include/my.h"
#include <unistd.h>

void my_putstrerr(char const *str)
{
    for (unsigned int i = 0; *(str + i); i++) {
        write(2, (str + i), 1);
    }
}
