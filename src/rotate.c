/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** rotate animation
*/

#include "my.h"

int rotate_left(int key, t_game *game)
{
    if (key == 18 &&
        game->sin > 34.6) {
        game->sin = game->sin - 0.01;
        return (1);
    }
    return (0);
}

int rotate_right(int key, t_game *game)
{
    if (key == 25 &&
        game->sin < 35.2) {
        game->sin = game->sin + 0.01;
        return (1);
    }
    return (0);
}

int rotate_animation(int key, t_game *game)
{
    if (rotate_left(key, game) == 1) {
        return (1);
    }
    if (rotate_right(key, game) == 1) {
        return (1);
    }
    return (0);
}
