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

Test (test_is_direct, command_with_number, .init = redirect_all)
{
    label_list_t list;

    list.begin = NULL;
    list.end = NULL;
    list.length = 0;
    list.idx = 0;
    cr_assert(is_direct(&list, "%1") == true);
}

Test (test_is_direct, command_with_valid_label, .init = redirect_all)
{
    label_list_t list;

    list.begin = NULL;
    list.end = NULL;
    list.length = 0;
    list.idx = 0;
    cr_assert(is_direct(&list, "%:crow") == true);
}

Test (test_is_direct, command_with_valid_with_separator, .init = redirect_all)
{
    label_list_t list;

    list.begin = NULL;
    list.end = NULL;
    list.length = 0;
    list.idx = 0;
    cr_assert(is_direct(&list, "%1,") == true);
}

Test (test_is_direct, command_with_invalid_label, .init = redirect_all)
{
    label_list_t list;

    list.begin = NULL;
    list.end = NULL;
    list.length = 0;
    list.idx = 0;
    cr_assert(is_direct(&list, "%:c*/ger") == false);
}

Test (test_is_direct, command_with_invalid_type_char, .init = redirect_all)
{
    label_list_t list;

    list.begin = NULL;
    list.end = NULL;
    list.length = 0;
    list.idx = 0;
    cr_assert(is_direct(&list, "$1") == false);
}

Test (test_is_direct, command_with_without_direct_type_char, .init = redirect_all)
{
    label_list_t list;

    list.begin = NULL;
    list.end = NULL;
    list.length = 0;
    list.idx = 0;
    cr_assert(is_direct(&list, ":crow") == false);
}

Test (test_is_direct, command_with_without_value, .init = redirect_all)
{
    label_list_t list;

    list.begin = NULL;
    list.end = NULL;
    list.length = 0;
    list.idx = 0;
    cr_assert(is_direct(&list, "%") == false);
}

Test (test_is_direct, command_misplaced_type_char, .init = redirect_all)
{
    label_list_t list;

    list.begin = NULL;
    list.end = NULL;
    list.length = 0;
    list.idx = 0;
    cr_assert(is_direct(&list, "1%") == false);
}

Test (test_is_direct, command_mbad_value, .init = redirect_all)
{
    label_list_t list;

    list.begin = NULL;
    list.end = NULL;
    list.length = 0;
    list.idx = 0;
    cr_assert(is_direct(&list, "%A") == false);
}