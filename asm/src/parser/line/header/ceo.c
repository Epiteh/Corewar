/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** header
*/

#include "asm.h"

static bool is_name(char *line)
{
    if (my_strncmp(line, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)) == 0)
        return (true);
    return (false);
}

static bool is_comment(char *line)
{
    if (my_strncmp(line, COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING))
        == 0)
        return (true);
    return (false);
}

static char *get_name(char *line)
{
    char *name = my_calloc((my_strlen(line) + 3), sizeof(char));
    unsigned int i = (find_quotes(line) + 1);
    unsigned int quotes = count_element(line, '\"');

    if (quotes != 2)
        err_output("Invalid name.");
    for (unsigned int y = 0; line[i] != '\"'; i += 1, y += 1)
        name[y] = line[i];
    check_between_name(line, NAME_CMD_STRING);
    check_end(line);
    name = split_into_simple(name, "\"");
    return (name);
}

static char *get_comment(char *line)
{
    char *name = my_calloc((my_strlen(line) + 3), sizeof(char));
    unsigned int i = (find_quotes(line) + 1);
    unsigned int quotes = count_element(line, '\"');

    if (quotes != 2)
        err_output("Invalid name.");
    for (unsigned int y = 0; line[i] != '\"'; i += 1, y += 1)
        name[y] = line[i];
    check_between_name(line, COMMENT_CMD_STRING);
    check_end(line);
    name = split_into_simple(name, "\"");
    return (name);
}

void fill_header(char *line, header_t *head, int idx_name)
{
    char *name = NULL;
    char *comment = NULL;
    if (is_name(line)) {
        if (idx_name != 1)
            err_output("Name must be first line.\n");
        name = get_name(line);
        if (my_strlen(name) > PROG_NAME_LENGTH)
            err_output("Champion name too long.\n");
        my_strcpy(name, head->prog_name);
    }
    if (is_comment(line)) {
        if (idx_name != 2)
            err_output("Comment must be after name.\n");
        comment = get_comment(line);
        if (my_strlen(comment) > COMMENT_LENGTH)
            err_output("Champion comment too long.\n");
        my_strcpy(comment, head->comment);
    }
}
