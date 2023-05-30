/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** vm
*/

#include "import.h"

#pragma once

// Corewar Struct
typedef struct winner_s {
    char name[PROG_NAME_LENGTH + 1];
    int id;
} winner_t;

typedef struct proghead_s {
    char name[PROG_NAME_LENGTH + 1];
    char comment[COMMENT_LENGTH + 1];
} proghead_t;

typedef struct prog_s {
    proghead_t header;
    int pc;
    int id;
    int size;
    bool dead;
    int carry;
    int call_live;
    int load_adress;
    int death_cycle;
    char content[MEM_SIZE];
    char regs[REG_NUMBER];
    struct prog_s *next;
} prog_t;

typedef struct vm_s {
    int memory[MEM_SIZE];
    int cycle_max;
    int cycle_dump;
    int cycle;
    int prog_nbr;
    int live_call;
    prog_t *prog;
    winner_t winner;
} vm_t;

// ERROR
    void err_output(char *msg);

// TAB
    void free_tab(char **tab);
    int len_tab(char **tab);
    void show_tab(char **tab);

// PARSING
    int corewar(int ac, char **av);
    void init_structs(vm_t *corewar, int ac, char **av);
    void get_progs(prog_t **progs, int ac, char **av);
    void create_prog(prog_t **tmp, char *path, int id, int load_adr);
    void add_prog(prog_t **progs, prog_t *new);
    void set_ids(prog_t *progs);
    void set_loads(vm_t *corewar);
    void set_mem(vm_t *corewar, prog_t *prog, int adr);
    // UTILS
        char **split_into_double(char *buffer, char *separator);
        char *split_into_simple(char *buffer, char *separator);
        int count_element(char *buffer, char separator);
        void check_magic(FILE *fd);
        int get_fight_size(prog_t *prog);
        void check_magic(FILE *fd);
        int get_fight_size(prog_t *prog);

// ARENA
    void arena_loop(vm_t *vm);
    // INSTRUCTIONS
        void handle_instruction(vm_t *vm);
        void launch_instruction(vm_t *vm, prog_t *prog, int instruction);
    // STRUCT INSTRUCTIONS
        typedef struct inst_s {
            void (*func)(vm_t *vm, prog_t *prog);
        } inst_t;
    // INSTRUCTIONS LIST
        void my_live(vm_t *vm, prog_t *prog);
        void my_ld(vm_t *vm, prog_t *prog);
        void my_st(vm_t *vm, prog_t *prog);
        void my_add(vm_t *vm, prog_t *prog);
        void my_sub(vm_t *vm, prog_t *prog);
        void my_and(vm_t *vm, prog_t *prog);
        void my_or(vm_t *vm, prog_t *prog);
        void my_xor(vm_t *vm, prog_t *prog);
        void my_zjmp(vm_t *vm, prog_t *prog);
        void my_ldi(vm_t *vm, prog_t *prog);
        void my_sti(vm_t *vm, prog_t *prog);
        void my_fork(vm_t *vm, prog_t *prog);
        void my_lld(vm_t *vm, prog_t *prog);
        void my_lldi(vm_t *vm, prog_t *prog);
        void my_lfork(vm_t *vm, prog_t *prog);
        void my_aff(vm_t *vm, prog_t *prog);
    // UTILS
        void update_pcounter(prog_t *prog, int num);
        int get_prog_adress(prog_t *prog);
        int correct_reg_num(int *type_arg, int *arg);
        int get_memory_adress(int prog_address);
        int get_inst_value(vm_t *vm, int pc, int val_len);
        bool is_direct_arg(int cmd);
        void get_args_types(vm_t *vm, int prog_addr,
            int *args_types);
        int get_inst_len(int *type_args, int instr_addr);
        int get_valid_register(int reg);
        prog_t *my_prog_cpy(prog_t *prog);
        void get_arg(vm_t *vm, int prog_addr, int *type_args,
            int *args);
        void write_memory_int(int *memory, int addr, int value);
        int get_sti_args(int arg, int type_arg, prog_t *prog);
        void add_memory_prog(prog_t *prog, vm_t *vm, int addr);
        void champion_win(vm_t *vm);
        void sort_champion_id(vm_t **vm);
        bool is_hexa_format(char *str);
        void handle_hexa_err(int i, char **av);
        void display_dump_error(void);
        int get_correct_addr(int addr);
        void display_dump_error(void);
