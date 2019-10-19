/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** square
*/

#include "my.h"

sfVector2f *four_square(sfVector2f *point, t_game *game, int i, int j)
{
    point[3] = project_iso_point((i)*game->scale_x,
    (j - 1) * game->scale_y,
    game->m3[j - 1][i] * game->scale_z, *game);
    point[3].y = point[3].y + WIN_H - WIN_H_4 + game->scroll_y;
    point[3].x = point[3].x + WIN_W_2 + game->scroll_x;
    return (point);
}

sfVector2f *third_square(sfVector2f *point, t_game *game, int i, int j)
{
    point[2] = project_iso_point((i-1) * game->scale_x,
    (j) * game->scale_y,
    game->m3[j][i-1] * game->scale_z, *game);
    point[2].y = point[2].y + WIN_H - WIN_H_4 + game->scroll_y;
    point[2].x = point[2].x + WIN_W_2 + game->scroll_x;
    return (point);
}

sfVector2f *second_square(sfVector2f *point, t_game *game, int i, int j)
{
    point[1] = project_iso_point((i - 1)*game->scale_x, (j - 1)*game->scale_y,
    game->m3[j - 1][i - 1] * game->scale_z, *game);
    point[1].y = point[1].y + WIN_H - WIN_H_4 + game->scroll_y;
    point[1].x = point[1].x + WIN_W_2 + game->scroll_x;
    return (point);
}

sfVector2f *first_square(sfVector2f *point, t_game *game, int i, int j)
{
    point[0] = project_iso_point(i * game->scale_x, j *
    game->scale_y, game->m3[j][i] *game->scale_z, *game);
    point[0].y = point[0].y + WIN_H - WIN_H_4 + game->scroll_y;
    point[0].x = point[0].x + WIN_W_2 + game->scroll_x;
    return (point);
}

sfVector2f *get_square(int i, int j, t_game *game)
{
    sfVector2f *point = malloc(sizeof(sfVector2f) * 4);

    if (point == NULL)
        return (NULL);
    first_square(point, game, i, j);
    second_square(point, game, i, j);
    third_square(point, game, i, j);
    four_square(point, game, i, j);
    return (point);
}
