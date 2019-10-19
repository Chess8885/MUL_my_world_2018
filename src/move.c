/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** move
*/

#include "my.h"

int check_move(int x, int y, t_game *game)
{
    int ret = 0;
    sfColor c1;

    c1.r = 255;
    c1.g = 255;
    c1.b = 255;
    c1.a = 255;
    ret = is_move(x, y, game, c1);
    return (ret);
}

int set_color(t_game *game, int i)
{
    sfColor c2;

    c2.r = 255;
    c2.g = 10;
    c2.b = 255;
    c2.a = 255;
    if (game->button[i - 1] == 0) {
        sfSprite_setColor(game->sprite[i], c2);
        game->button[i - 1] = 1;
        return (1);
    }
    return (0);
}

int is_move(int x, int y, t_game *game, sfColor c1)
{
    int i = 1;
    int ret = 0;

    while (i != 4) {
        if (x > i * 10 + (i - 1) * 80 &&
            x < i * 10 + i * 80 &&
            y > 10 && y < 90) {
            ret = set_color(game, i);
}
        else if (game->button[i - 1] == 1) {
            sfSprite_setColor(game->sprite[i], c1);
            game->button[i - 1] = 0;
            ret = 1;
}
        i++;
    }
    return (ret);
}
