/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** map
*/

#include "my.h"

int get_map_error(FILE *map)
{
    if (map == NULL) {
        return (1);
    }
    return (0);
}

int get_map_height(int i, t_game *game, char buffer[1], FILE *map)
{
        while (fread(buffer, 1, 1, map) == 1) {
        if (buffer[0] == '\n') {
            game->height++;
        }
        i++;
    }
        return (i);
}

int get_map_size(t_game *game)
{
    FILE *map = fopen("map", "r");
    char buffer[1];
    int i = 0;

    i = get_map_height(i, game, buffer, map);
    game->width = (i / game->height) / 3;
    fclose(map);
    return (0);
}

int reset_map(t_game *game)
{
    int i = 0;
    int j = 0;

    while (j < game->height) {
        i = 0;
        while (i < game->width) {
            game->m3[j][i] = 0;
            i++;
        }
        j++;
    }
    return (1);
}

int error_save_map(int fd)
{
    if (fd == -1) {
        return (-1);
    }
    return (0);
}
