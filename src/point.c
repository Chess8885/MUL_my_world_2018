/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** maths
*/

#include "my.h"

int check_point(int mouse[3], t_game *game)
{
    int i = 0;
    int j = 0;
    int ret = 2;

    while (j != game->height && ret == 2) {
        i = 0;
        while (i != game->width && ret == 2) {
            ret = check_button(mouse, i, j, game);
            i++;
        }
        j++;
    }
    return (ret);
}
