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

Test (test_get_instruction, start_valid_instruction, .init = redirect_all)
{
    cr_assert(get_instruction("live") != NULL);
}

Test (test_get_instruction, end_valid_instruction, .init = redirect_all)
{
    cr_assert(get_instruction("lldi") != NULL);
}

Test (test_get_instruction, middle_valid_instruction, .init = redirect_all)
{
    cr_assert(get_instruction("and") != NULL);
}

Test (test_get_instruction, invalid_instruction, .init = redirect_all)
{
    cr_assert(get_instruction("lezive") == NULL);
}

Test (test_get_instruction, start_garbage_with_instruction, .init = redirect_all)
{
    cr_assert(get_instruction("azertylive") == NULL);
}

Test (test_get_instruction, end_garbage_with_instruction, .init = redirect_all)
{
    cr_assert(get_instruction("liveazerty") == NULL);
}

