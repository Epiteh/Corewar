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

Test (command_with_reg, test_is_register, .init = redirect_all)
{
    cr_assert(is_register("r1") == true);
}

Test (command_separator, test_is_register, .init = redirect_all)
{
    cr_assert(is_register("r1,") == true);
}

Test (command_invalid_type_char, test_is_register, .init = redirect_all)
{
    cr_assert(is_register("R1") == false);
}

Test (second_command_invalid_type_char, test_is_register, .init = redirect_all)
{
    cr_assert(is_register("a1") == false);
}

Test (command_invalid_value_zero, test_is_register, .init = redirect_all)
{
    cr_assert(is_register("r0") == false);
}

Test (command_invalid_value_negative, test_is_register, .init = redirect_all)
{
    cr_assert(is_register("r-1") == false);
}

Test (command_invalid_value_float, test_is_register, .init = redirect_all)
{
    cr_assert(is_register("r1.5") == false);
}

Test (command_invalid_value_too_big, test_is_register, .init = redirect_all)
{
    cr_assert(is_register("r150") == false);
}

Test (command_invalid_value_big, test_is_register, .init = redirect_all)
{
    cr_assert(is_register("r16") == false);
}
