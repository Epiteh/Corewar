/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** my_realloc
*/

#include "../include/my.h"
#include <stddef.h>
#include <stdlib.h>

void *my_realloc(void *ptr, size_t size)
{
    void *new_ptr;

    if (size == 0) {
        free(ptr);
        return (NULL);
    }
    if (ptr == NULL) {
        return (my_calloc(1, size));
    }
    new_ptr = my_calloc(1, size);
    if (new_ptr != NULL) {
        my_memcpy(new_ptr, ptr, size);
        free(ptr);
    }
    return (new_ptr);
}
