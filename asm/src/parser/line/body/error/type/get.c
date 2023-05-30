/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** get_separators.c
*/
#include "asm.h"

bool my_str_isnum(char *str)
{
    for (unsigned int i = 0; str[i] != '\0'; i += 1) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
            return (false);
    }
    return (true);
}

bool is_register(char *element)
{
    int reg_num = 0;
    char sep[3] = {SEPARATOR_CHAR, ' ', '\0'};

    element = my_strtok(my_strdup(element), sep);
    if (element[0] == 'r') {
        reg_num = my_getnbr(element);
        if (my_str_isnum(element + 1) && (reg_num > 0) &&
            (reg_num < REG_NUMBER)) {
            return (true);
        }
    }
    return (false);
}

bool is_direct(label_list_t *list, char *element)
{
    char sep[3] = {SEPARATOR_CHAR, ' ', '\0'};

    element = my_strtok(my_strdup(element), sep);
    if (element[0] == DIRECT_CHAR) {
        if (element[1] == LABEL_CHAR && is_label(list, element + 2)) {
            return (true);
        }
        if (!my_str_isnum(element + 1))
            return (false);
    } else {
        return (false);
    }
    if (my_strlen(element) > 1)
        return (true);
    return (false);
}

bool is_indirect(label_list_t *list, char *element)
{
    char sep[3] = {SEPARATOR_CHAR, ' ', '\0'};

    element = my_strtok(my_strdup(element), sep);
    if (element[0] == LABEL_CHAR) {
        if (is_label(list, element + 1))
            return (true);
    }
    if (my_str_isnum(element) && my_strlen(element) > 0)
        return (true);
    return (false);
}
