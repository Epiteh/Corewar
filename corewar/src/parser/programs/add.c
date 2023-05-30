/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** add
*/

#include "vm.h"

static void init_prog(prog_t *tmp, int id, int load_adr)
{
    my_memset(tmp->regs, 0, sizeof(tmp->regs));
    tmp->id = id;
    tmp->load_adress = load_adr;
    tmp->pc = 0;
    tmp->size = 0;
    tmp->death_cycle = -1;
    tmp->dead = false;
}

static void read_prog(prog_t *prog, char *path)
{
    FILE *fd = fopen(path, "r");
    size_t bytes = 0;

    if (!fd)
        err_output("Error : File not found.\n");
    check_magic(fd);
    bytes = fread(prog->content, sizeof(char), MEM_SIZE, fd);
    if (bytes >= MEM_SIZE)
        err_output("Error : File too big.\n");
    if (bytes == 0)
        err_output("Error : File reading failure.\n");
    prog->content[bytes] = '\0';
    fclose(fd);
}

static uint32_t get_prog_size(FILE *fd)
{
    uint32_t size = 0;

    fseek(fd, 136, SEEK_SET);
    fread(&size, sizeof(uint32_t), 1, fd);
    size = ((size >> 24) & 0xff) | (((size >> 8) & 0xff00)) |
        ((size << 8) & 0xff0000) | (size << 24);
    return (size);
}

static void parse_prog_head(prog_t *tmp)
{
    int byte = 4;

    for (int i = 0; i < PROG_NAME_LENGTH; i++)
        tmp->header.name[i] = tmp->content[byte++];
    tmp->header.name[PROG_NAME_LENGTH] = '\0';
    byte += 4;
    tmp->size = tmp->content[byte] & 0xFF;
    for (int j = 1; j < 4; j++)
        tmp->size = (tmp->size << 8) | (tmp->content[byte + j] & 0xFF);
    byte += 4;
    for (int k = 0; k < COMMENT_LENGTH; k++)
        tmp->header.comment[k] = tmp->content[byte++];
    tmp->header.comment[COMMENT_LENGTH] = '\0';
    byte += 4;
    for (int l = 0; l < (MEM_SIZE - byte); l++)
        tmp->content[l] = tmp->content[byte + l];
}

void create_prog(prog_t **tmp, char *path, int id, int load_adr)
{
    (*tmp) = my_calloc(1, sizeof(prog_t));

    if (!(*tmp))
        err_output("Error : Memory allocation failure.\n");
    init_prog((*tmp), id, load_adr);
    read_prog((*tmp), path);
    parse_prog_head((*tmp));
}
