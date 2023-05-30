/*
** EPITECH PROJECT, 2023
** Base-project-for-C
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int counter = 0;

    while (*str) {
        counter += 1;
        str ++;
    }
    return counter;
}
