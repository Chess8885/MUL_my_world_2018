/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** print
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(const char *str, int filedes)
{
    if (str)
        write(filedes, str, my_strlen(str));
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i]) {
        if (s1[i] < s2[i]) {
            return (-1);
        }
        if (s1[i] > s2[i]) {
            return (1);
        }
        i = i + 1;
    }
    return (0);
}

int check_help(int argc, char **argv)
{
    if (argc > 1 && my_strcmp(argv[1], "-h") == 0) {
        my_putstr("This is the help command.\nUsage is: ./my_world\n", 1);
        return (-1);
    } else {
        return (0);
    }
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str != 0 && str[i] != 0) {
        i++;
    }
    return (i);
}
