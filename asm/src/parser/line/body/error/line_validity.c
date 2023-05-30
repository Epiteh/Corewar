/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** line_validity.c
*/
#include "asm.h"

bool is_init_label(label_list_t *list, char *element)
{
    if ((element[my_strlen(element) - 1] != LABEL_CHAR) ||
        !is_label(list, element)) {
            return (false);
        }
    return (true);
}

static int compare_minemonic(char **array, label_list_t *list, unsigned int i,
    unsigned int j)
{
    if (my_strcmp(array[j], op_tab[i].mnemonique) == 0) {
        if (!check_args_validity(list, array, i, j)) {
            return (0);
        }
        return (1);
    }
    return (2);
}

static bool browse_mnemonique(char **array, label_list_t *list, unsigned int j)
{
    int compare_return = 2;

    for (unsigned int i = 0; op_tab[i].mnemonique != NULL; i++) {
        compare_return = compare_minemonic(array, list, i, j);
        if (compare_return == 0)
            return (false);
        if (compare_return == 1)
            return (true);
    }
    return (NULL);
}

bool check_line_validity(char *line, label_list_t *list)
{
    char delim[4] = {SEPARATOR_CHAR, ' ', '\t', '\0'};
    char **array = split_into_double(my_strdup(line), delim);
    unsigned int j = 0;

    check_separator(line);
    array = remove_array_comments(array);
    if (array == NULL)
        return (true);
    if (!is_minemonic(array[0])) {
        j = 1;
        if (is_init_label(list, array[0])) {
            browse_label_list(list, array[0], true);
            return (true);
        } else
            return (false);
    }
    if (browse_mnemonique(array, list, j) == false)
        return (false);
    free_array(array);
    return (true);
}
