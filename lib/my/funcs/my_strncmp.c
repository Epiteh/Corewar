/*
** EPITECH PROJECT, 2023
** Base-project-for-C
** File description:
** my_strncmp
*/

static int condition(int i, const char *s1, const char *s2)
{
    if (s1[i] != s2[i]) {
        return (s1[i] - s2[i]);
    } else if (s1[i] == '\0') {
        return (0);
    }
    return (0);
}

int my_strncmp(const char *s1, const char *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (condition(i, s1, s2) != 0) {
            return (condition(i, s1, s2));
        }
    }
    return (0);
}
