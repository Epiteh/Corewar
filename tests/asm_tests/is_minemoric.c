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

Test (test_is_minemonic, start_valid_instruction, .init = redirect_all)
{
    cr_assert(is_minemonic("live") == true);
}

Test (test_is_minemonic, end_valid_instruction, .init = redirect_all)
{
    cr_assert(is_minemonic("lldi") == true);
}

Test (test_is_minemonic, middle_valid_instruction, .init = redirect_all)
{
    cr_assert(is_minemonic("and") == true);
}

Test (test_is_minemonic, invalid_instruction, .init = redirect_all)
{
    cr_assert(is_minemonic("lezive") == false);
}

Test (test_is_minemonic, start_garbage_with_instruction, .init = redirect_all)
{
    cr_assert(is_minemonic("azertylive") == false);
}

Test (test_is_minemonic, end_garbage_with_instruction, .init = redirect_all)
{
    cr_assert(is_minemonic("liveazerty") == false);
}