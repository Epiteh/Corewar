/*
** EPITECH PROJECT, 2023
** Tests_Criterion [WSL : Ubuntu-20.04]
** File description:
** test_welcome_message
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "asm.h"

static void redirect_all(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

Test (test_is_label, command_is_label, .init = redirect_all)
{
    label_list_t list;

    list.begin = NULL;
    list.end = NULL;
    list.length = 0;
    list.idx = 0;
    cr_assert(is_label(&list, my_strdup("crow")) == true);
}

Test (test_is_label, another_command_is_not_label, .init = redirect_all)
{
    label_list_t list;

    list.begin = NULL;
    list.end = NULL;
    list.length = 0;
    list.idx = 0;
    cr_assert(is_label(&list, my_strdup("%*rf-*")) == false);
}

Test (test_is_label, is_valid_label_with_separators, .init = redirect_all)
{
    label_list_t list;

    list.begin = NULL;
    list.end = NULL;
    list.length = 0;
    list.idx = 0;
    cr_assert(is_label(&list, my_strdup("crow,")) == true);
}

Test (test_is_label, is_valid_label_with_type_separators, .init = redirect_all)
{
    label_list_t list;

    list.begin = NULL;
    list.end = NULL;
    list.length = 0;
    list.idx = 0;
    cr_assert(is_label(&list, my_strdup("%:crow")) == true);
}

Test (test_is_label, is_valid_label_with_type_and_separators, .init = redirect_all)
{
    label_list_t list;

    list.begin = NULL;
    list.end = NULL;
    list.length = 0;
    list.idx = 0;
    cr_assert(is_label(&list, my_strdup("%:crow,")) == true);
}
