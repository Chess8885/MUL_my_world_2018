/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** destroy
*/

#include "my.h"

int destroy_music(t_game *game)
{
    sfMusic_stop(game->music);
    sfMusic_destroy(game->music);
    return (0);
}

void destroy_sprite(t_game *game)
{
    for (int i = 0; i != 4; i++) {
        sfSprite_destroy(game->sprite[i]);
    }
}

int destroy_all(t_game *game)
{
    destroy_music(game);
    destroy_sprite(game);
    return (0);
}
