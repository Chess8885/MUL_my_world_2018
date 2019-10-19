/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** button
*/

#include "my.h"

int in_check_button_2(int mouse[3], int i, int j, t_game *game)
{
    if (mouse[2] == -1 && (game->m3[j][i] == -5 ||
        game->m3[j - 1][i - 1] == -5 ||
        game->m3[j][i - 1] == -5 ||
        game->m3[j - 1][i] == -5)) {
        return (0);
    }
    else if (mouse[2] == 1 && (game->m3[j][i] == 15 ||
            game->m3[j - 1][i - 1] == 15 ||
            game->m3[j][i - 1] == 15 ||
            game->m3[j - 1][i] == 15)) {
        return (0);
    }
    else {
        up_tile(game, mouse[2], i, j);
    }
    return (1);
}

int check_button_2(int mouse[3], int i, int j, t_game *game)
{
    sfVector2f *position = get_square(i, j, game);

    if (position == NULL)
        return (-1);
    if (mouse[1] > position[0].y + 5 &&
        mouse[1] < position[1].y - 5 &&
        mouse[0] > position[2].x + 5 &&
        mouse[0] < position[3].x - 5) {
        if (in_check_button_2(mouse, i, j, game) != 1) {
            return (0);
}
        return (1);
    }
    return (0);
}

int in_check_button(int mouse[3], int i, int j, t_game *game)
{
    if (mouse[2] == -1 && game->m3[j][i] > -5) {
        game->m3[j][i] = game->m3[j][i] + mouse[2];
    }
    else if (mouse[2] == 1 && game->m3[j][i] < 15) {
        game->m3[j][i] = game->m3[j][i] + mouse[2];
    }
    else {
        return (0);
    }
    return (3);
}

int check_button(int mouse[3], int i, int j, t_game *game)
{
    sfVector2f position;

    position.x = 0;
    position.y = 0;
    position = project_iso_point(i * game->scale_x, j * game->scale_y,
    game->m3[j][i] * game->scale_z, *game);
    position.y += WIN_H - WIN_H_4 + game->scroll_y;
    position.x += WIN_W_2 + game->scroll_x;
    if (position.x - 5 < mouse[0] && position.x + 5 > mouse[0] &&
        position.y - 5 < mouse[1] && position.y + 5 > mouse[1]) {
        if (in_check_button(mouse, i, j, game) == 0) {
            return (0);
        } else {
            return (1);
        }
    }
    return (2);
}
