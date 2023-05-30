/*
** EPITECH PROJECT, 2023
** Base-project-for-C
** File description:
** my_isdigit
*/

int my_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}
