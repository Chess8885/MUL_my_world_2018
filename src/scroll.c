/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** scroll mouse
*/

#include "my.h"

int scroll_up(int key, t_game *game)
{
    if (key == 72)
        game->scroll_x = game->scroll_x + 20;
    if (key == 74)
        game->scroll_y = game->scroll_y + 20;
    return (0);
}

int scroll_down(int key, t_game *game)
{
    if (key == 71)
        game->scroll_x = game->scroll_x - 20;
    if (key == 73)
        game->scroll_y = game->scroll_y - 20;
    return (0);
}

int scroll_animation(int key, t_game *game)
{
    scroll_up(key, game);
    scroll_down(key, game);
    return (1);
}
