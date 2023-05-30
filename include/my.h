/*
** EPITECH PROJECT, 2023
** read_html_file
** File description:
** Made by @hodooos, @Tilu, @BigS
*/

#include <stdlib.h>

#pragma once
// LibC functions
    void *my_calloc(int element, int size);
    void *my_memset(void *ptr, int count, int size);
    void my_putstr(char const *str);
    int my_strlen(char const *str);
    int my_isdigit(char c);
    int my_getnbr(char const *str);
    int my_put_nbr(int nb);
    void my_putchar(char c);
    int my_strcmp(const char *str1, const char *str2);
    char *my_strcpy(const char *src, char* dest);
    void my_show_array(char **array);
    char *my_strchr(char *str, int ch);
    char *my_strdup(char const *str);
    int my_strncmp(const char *s1, const char *s2, int n);
    void *my_memcpy(void* dest, const void* src, size_t nbr_bytes);
    void *my_realloc(void *ptr, size_t size);
    char *my_strtok(char *str, char *separator);
    void my_putstrerr(char const *str);
    char *my_strcat(char *dest, const char *src);
    char *my_strstr(char *str, char *needstr);
