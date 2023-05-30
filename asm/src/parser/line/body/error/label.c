/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** label.c
*/

#include "asm.h"

static bool authorized_char(char c)
{
    char *authorized = LABEL_CHARS;
    unsigned int i = 0;

    for ( ; authorized[i] != '\0'; i += 1) {
        if (authorized[i] == c)
            return (true);
    }
    return (false);
}

static bool authorized_content(char *element)
{
    char separators[5] = {LABEL_CHAR, DIRECT_CHAR, SEPARATOR_CHAR, '\0'};
    char *new_elem = my_strtok(my_strdup(element), separators);

    for (unsigned int i = 0; new_elem[i] != '\0'; i += 1) {
        if (authorized_char(new_elem[i]) == false)
            return (false);
    }
    return (true);
}

bool is_label(label_list_t *list, char *element)
{
    if (!authorized_content(element))
        return (false);
    browse_label_list(list, element, false);
    return (true);
}

void handle_labels_errors(label_list_t *list)
{
    check_label_initialisation(list);
    clear_label_list(list);
}
