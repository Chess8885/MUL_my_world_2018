/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** map
*/

#include "my.h"

int save_map(t_game *game)
{
    int i = 0;
    int j = 0;
    char buffer[3];
    int fd = open("map", O_WRONLY);

    while (j < game->height) {
        while (i < game->width) {
            buffer[0] = game->m3[j][i] + 48;
            buffer[1] = game->object[j][i] + 48;
            buffer[2] = '.';
            write(fd, buffer, 3);
            i++;
        }
        i = 0;
        j++;
        write(fd, "\n", 1);
    }
    return (1);
}

void free_struct(t_game *game)
{
    free(game->m3);
    game->height = 0;
    game->width = 0;
}

void free_map(t_game *game)
{
    int i = 0;

    while (i != game->height) {
        free(game->m3[i]);
        i++;
    }
    free_struct(game);
}

int check_load_map(t_game *game)
{
    if (game->m3 != NULL)
        free_map(game);
    if (get_map_size(game) != 0)
        return (-1);
    return (0);
}

int load_map(t_game *game)
{
    char *buffer = NULL;

    if (check_load_map(game) == -1) {
        return (-1);
    }
    buffer = get_buffer(((game->width + 1) * 3) * game->height);
    if (buffer == NULL)
        return (-1);
    game->m3 = get_map(buffer, *game);
    if (game->m3 == NULL)
        return (-1);
    game->object = get_object(buffer, *game);
    if (game->object == NULL)
        return (-1);
    free(buffer);
    return (1);
}
