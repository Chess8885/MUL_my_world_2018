/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** init
*/

#include "my.h"

int load_sprite(t_game *game)
{
    game->sprite = malloc(sizeof(sfSprite *) * 4);
    if (game->sprite == NULL)
        return (1);
    link_sprite(game);
    return (0);
}

int load_music(t_game *game)
{
    game->music = sfMusic_createFromFile("res/music.ogg");
    sfMusic_play(game->music);
    sfMusic_setLoop(game->music, sfTrue);
    return (0);
}
