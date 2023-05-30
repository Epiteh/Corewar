/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** output_file
*/

#include "asm.h"

static char *remove_extension(char *filepath)
{
    unsigned int i = 0;
    unsigned int j = 0;
    char *tmp = my_strdup(filepath);
    char *cor_file = my_calloc((my_strlen(tmp) + 1), sizeof(char));

    for (; tmp[i] != '\0'; i++) {
        if (tmp[i] == '.')
            break;
        cor_file[j] = tmp[i];
        j++;
    }
    free(tmp);
    return (cor_file);
}

char *output_cor(char *filepath)
{
    char *cor_file = NULL;
    char **tab = split_into_double(filepath, "/");
    int fd = 0;

    cor_file = my_strdup(tab[len_tab(tab) - 1]);
    cor_file = remove_extension(cor_file);
    cor_file = my_strcat(cor_file, ".cor");
    fd = open(cor_file, O_CREAT | O_WRONLY, 420);
    if (fd == -1)
        err_output("Error while creating .cor file.\n");
    close(fd);
    return (cor_file);
}
