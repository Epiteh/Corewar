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

Test (test_find_quotes, command_with_quote, .init = redirect_all)
{
    cr_assert(find_quotes("120\"") == 3);
}

Test (test_find_quotes, command_with_multiple_end_quote, .init = redirect_all)
{
    cr_assert(find_quotes("120\"\"\"") == 3);
}

Test (test_find_quotes, command_with_multiple_start_quote, .init = redirect_all)
{
    cr_assert(find_quotes("\"\"\"120") == 0);
}

Test (test_find_quotes, command_with_multiple_middle_quote, .init = redirect_all)
{
    cr_assert(find_quotes("1\"\"\"20") == 1);
}

Test (test_find_quotes, command_without_quote, .init = redirect_all)
{
    cr_assert(find_quotes("120") == 3);
}
