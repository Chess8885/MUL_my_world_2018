/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** link sprite and texture
*/

#include "my.h"

int link_sprite(t_game *game)
{
    sfTexture *texture = NULL;

    game->sprite[0] = sfSprite_create();
    texture = sfTexture_createFromFile("res/tree.png", NULL);
    sfSprite_setTexture(game->sprite[0], texture, 0);
    game->sprite[1] = sfSprite_create();
    texture = sfTexture_createFromFile("res/b_reset.png", NULL);
    sfSprite_setTexture(game->sprite[1], texture, 0);
    game->sprite[2] = sfSprite_create();
    texture = sfTexture_createFromFile("res/b_load.png", NULL);
    sfSprite_setTexture(game->sprite[2], texture, 0);
    game->sprite[3] = sfSprite_create();
    texture = sfTexture_createFromFile("res/b_save.png", NULL);
    sfSprite_setTexture(game->sprite[3], texture, 0);
    return (0);
}
