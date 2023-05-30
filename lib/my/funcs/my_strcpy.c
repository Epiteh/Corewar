/*
** EPITECH PROJECT, 2023
** Base-project-for-C
** File description:
** my_strcpy
*/

char *my_strcpy(const char *src, char* dest)
{
    unsigned int i = 0;

    while ((dest[i] = src[i]) != '\0')
        i++;
    dest[i] = '\0';
    return (dest);
}
