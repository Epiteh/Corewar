/*
** EPITECH PROJECT, 2023
** Base-project-for-C
** File description:
** my_strcmp
*/

int my_strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2)) {
        str1 += 1;
        str2 += 1;
    }
    return (*str1 - *str2);
}
