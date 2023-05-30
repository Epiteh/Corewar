/*
** EPITECH PROJECT, 2023
** Tests_Criterion [WSL : Ubuntu-20.04]
** File description:
** test_welcome_message
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "asm.h"
bool my_str_isnum(char *str);

static void redirect_all(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

Test (test_is_indirect, command_with_number, .init = redirect_all)
{
    label_list_t list;

    list.begin = NULL;
    list.end = NULL;
    list.length = 0;
    list.idx = 0;
    cr_assert(is_indirect(&list, "120") == true);
}

Test (test_is_indirect, command_with_label, .init = redirect_all)
{
    label_list_t list;

    list.begin = NULL;
    list.end = NULL;
    list.length = 0;
    list.idx = 0;
    cr_assert(is_indirect(&list, ":crow") == true);
}

Test (test_is_indirect, command_with_bad_label, .init = redirect_all)
{
    label_list_t list;

    list.begin = NULL;
    list.end = NULL;
    list.length = 0;
    list.idx = 0;
    cr_assert(is_indirect(&list, ":*fzf") == false);
}

Test (test_is_indirect, command_with_bad_value, .init = redirect_all)
{
    label_list_t list;

    list.begin = NULL;
    list.end = NULL;
    list.length = 0;
    list.idx = 0;
    cr_assert(is_indirect(&list, "*fzf") == false);
}