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

Test (test_my_str_isnum, command_with_number, .init = redirect_all)
{
    cr_assert(my_str_isnum("120") == true);
}

Test (test_my_str_isnum, command_with_letter, .init = redirect_all)
{
    cr_assert(my_str_isnum("azerty") == false);
}

Test (test_my_str_isnum, command_with_letter_start_number, .init = redirect_all)
{
    cr_assert(my_str_isnum("154azerty") == false);
}

Test (test_my_str_isnum, command_with_letter_end_number, .init = redirect_all)
{
    cr_assert(my_str_isnum("azerty1569") == false);
}

Test (test_my_str_isnum, command_with_float, .init = redirect_all)
{
    cr_assert(my_str_isnum("1.20") == false);
}
