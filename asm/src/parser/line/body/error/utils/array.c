/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** array.c
*/

#include "asm.h"

static void free_array_content(char **array, unsigned int i)
{
    for (; array[i] != NULL; i++)
        free(array[i]);
}

char **remove_array_comments(char **array)
{
    for (unsigned int i = 0; array[i] != NULL; i++) {
        if (array[i][0] == COMMENT_CHAR) {
            array[i] = NULL;
            free_array_content(array, i + 1);
        }
    }
    return (array);
}

void free_array(char **array)
{
    for (unsigned int y = 0; array[y] != NULL; y++)
        free(array[y]);
    free(array);
}
