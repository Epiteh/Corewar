/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** read
*/

#include "asm.h"

static void rm_comment(char **buffer)
{
    for (unsigned int i = 0; (*buffer)[i] != '\0'; i++) {
        if ((*buffer)[i] == COMMENT_CHAR) {
            (*buffer)[i] = '\0';
        }
    }
}

static void clean_line(char **buffer)
{
    if (my_strlen(*buffer) > 0) {
        if ((*buffer)[my_strlen(*buffer) - 1] == '\n')
            (*buffer)[my_strlen(*buffer) - 1] = '\0';
        while ((*buffer)[0] == ' ' || (*buffer)[0] == '\t') {
                my_strcpy(*buffer + 1, *buffer);
        }
    }
    if (my_strlen(*buffer) == 0)
        return;
    for (unsigned int i = my_strlen(*buffer) - 1; i > 0; i--) {
        if ((*buffer)[i] == ' ' || (*buffer)[i] == '\t')
            (*buffer)[i] = '\0';
        else
            break;
    }
}

static int read_line(char **buffer, size_t *size, FILE *fd)
{
    int is = getline(buffer, size, fd);

    if (is == -1)
        return (-1);
    if (is == 1 && (*buffer)[0] == '\n')
        return (-2);
    clean_line(buffer);
    rm_comment(buffer);
    return (0);
}

static void handle_file_errors(int *is, char **buffer, size_t *size, FILE *fd)
{
    *is = read_line(buffer, size, fd);
    if (!buffer)
        err_output("File is empty.\n");
}

inst_t *read_file(FILE *fd, inst_t *inst, header_t *head)
{
    char *buffer = NULL;
    size_t size = 0;
    int is = read_line(&buffer, &size, fd);
    label_list_t list;

    init_label_list(&list);
    for (unsigned int line = 0; is != -1; line++) {
        if (my_strlen(buffer) != 1) {
            list.idx = line;
            parse_line(&list, buffer, &inst, head);
        }
        handle_file_errors(&is, &buffer, &size, fd);
    }
    fclose(fd);
    handle_labels_errors(&list);
    return (inst);
}
