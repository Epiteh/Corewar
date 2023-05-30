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

Test (test_count_element, command_without_element, .init = redirect_all)
{
    cr_assert(count_element("120", 'c') == 0);
}

Test (test_count_element, command_three_element, .init = redirect_all)
{
    cr_assert(count_element("ccc", 'c') == 3);
}

Test (test_count_element, command_start_element, .init = redirect_all)
{
    cr_assert(count_element("*efzef", '*') == 1);
}

Test (test_count_element, command_special_element, .init = redirect_all)
{
    cr_assert(count_element("*zefe", '\t') == 0);
}
