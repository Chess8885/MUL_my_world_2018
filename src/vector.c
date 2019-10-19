/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** vector
*/

#include "my.h"

sfVector2f project_iso_point(int x, int y, int z, t_game game)
{
    sfVector2f point;

    point.x = cos(game.cos) * x - cos(game.cos) * y;
    point.y = sin(game.sin) * y + sin(game.sin) * x - z;
    return (point);
}

sfVector2f **malloc_map_height(int i, t_game game, sfVector2f **m2)
{
    while (i != game.height) {
        m2[i] = malloc(sizeof(sfVector2f) * game.width);
        i++;
    }
    return (m2);
}

sfVector2f **create_2d_map(t_game game)
{
    sfVector2f **m2 = malloc(sizeof(sfVector2f*) * game.height);
    int i = 0;
    int j = 0;

    malloc_map_height(i, game, m2);
    if (m2[i] == NULL || m2 == NULL)
        return (NULL);
    while (j != game.height) {
        i = 0;
        while (i != game.width) {
            m2[j][i] = project_iso_point(i * game.scale_x, j * game.scale_y,
            game.m3[j][i] * game.scale_z, game);
            m2[j][i].y = m2[j][i].y + WIN_H - WIN_H_4 + game.scroll_y;
            m2[j][i].x = m2[j][i].x + WIN_W_2 + game.scroll_x;
            i++;
        }
        j++;
    }
    return (m2);
}

sfVector2f get_point(int x, int y, t_game game)
{
    sfVector2f point;

    point = project_iso_point(x, y, 0, game);
    point.y = point.y + WIN_H - WIN_H_4 + 5 * game.scale_z + game.scroll_y;
    point.x = point.x + WIN_W_2 + game.scroll_x;
    return (point);
}
