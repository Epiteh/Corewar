/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** asm
*/

#include "import.h"

#pragma once

typedef struct args_s {
    char *str;
    char type;
    int size;
    struct args_s *next;
} args_t;

typedef struct instructions_s {
    int idx; // OK
    char *str; // OK
    bool is_label;
    args_t *args; // TODO
    struct instructions_s *next;
} inst_t;

// Struct for hex
typedef struct hex_s {
    char *mnemonique;
    int code;
} hex_t;

extern const hex_t hex_s[];

// Asm struct
typedef struct asm_s {
    bool name_set;
    bool comment_set;
} asm_t;

// Error handling label
typedef struct node_label_s {
    struct node_label_s *prev;
    struct node_label_s *next;
    char *label;
    bool is_init;
} node_label_t;

typedef struct {
    node_label_t *begin;
    node_label_t *end;
    unsigned int length;
    unsigned int idx;
} label_list_t;

// PARSING
    int parse_file(char *filepath);
    void check_format(char *filepath);
    inst_t *open_file(char *filepath, header_t *head, inst_t *inst);
    inst_t *read_file(FILE *fd, inst_t *inst, header_t *head);
    void parse_line(label_list_t *list, char *line, inst_t **inst,
        header_t *head);
    void fill_header(char *line, header_t *head, int idx_name);
    void add_instruction(label_list_t *list, inst_t **inst,
        char *line, unsigned int idx);
    args_t *get_args(char *line);
    // HEADER
        void check_end(char *buffer);
        void check_between_name(char *buffer, char *name);
        int find_quotes(char *buffer);
    // SUBFUNCS
        bool is_header(char *line);
        bool is_instruction(char *line);
        bool is_label(label_list_t *list, char *line);
        char *get_instruction(char *tmp);

// ERROR HANDLING
    void err_output(char *msg);
    bool is_minemonic(char *element);
    char **remove_array_comments(char **array);
    void free_array(char **array);
    bool check_args_validity(label_list_t *list, char **array, unsigned int i,
        unsigned int j);
    bool check_line_validity(char *line, label_list_t *list);
    char *get_element_type(char *line);
    bool is_register(char *element);
    bool is_direct(label_list_t *list, char *element);
    bool is_indirect(label_list_t *list, char *element);
    bool check_type(label_list_t *list, char **array, unsigned int type_index,
        unsigned int j);
    void init_label_list(label_list_t *list);
    void browse_label_list(label_list_t *list, char *element, bool is_init);
    void add_label_var(label_list_t *list, char *label);
    void check_label_initialisation(label_list_t *list);
    void clear_label_list(label_list_t *list);
    void handle_labels_errors(label_list_t *list);
    void check_separator(char *line);

// UTILS
    char **split_into_double(char *buffer, char *separator);
    char *split_into_simple(char *buffer, char *separator);
    int count_element(char *buffer, char separator);
    char *output_cor(char *filepath);
    bool no_label(char *arg);
    int len_tab(char **tab);

// WRITE
    int write_cor(char *cor_file, header_t *head, inst_t *inst);
    // UTILS
        void *reverse_int(void *ptr, size_t ptr_size);
        bool valid_code_byte(char *str);
        void put_big_endian(void *ptr, int size, FILE *output);
        int get_byte_code(args_t *args);
    // HEADER
        void write_header(header_t *head, inst_t *inst, FILE *fd);
    // INSTRUCTION
        void write_instruction(inst_t *inst, FILE *fd);
        void find_index(inst_t *inst);
    // ARGS
        void write_args(inst_t *inst, args_t *args, FILE *fd, inst_t *ihead);
        int find_label(char *str, int line_nb, inst_t *ihead);
