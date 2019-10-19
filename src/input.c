/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** input
*/

#include "my.h"

int get_shadow(int **mouse, int i, int j)
{
    t_shadow shadow;

    if (j > 0 &&
        i > 0) {
        shadow.p_1 = mouse[j][i];
        shadow.p_2 = mouse[j - 1][i];
        shadow.p_3 = mouse[j][i - 1];
        shadow.p_4 = mouse[j - 1][i - 1];
        if (shadow.p_1 == shadow.p_2 && shadow.p_2 == shadow.p_3 &&
            shadow.p_3 == shadow.p_4)
            return (1);
        if ((shadow.p_1 < shadow.p_2 || shadow.p_3 < shadow.p_2 ||
            shadow.p_4 < shadow.p_2) || (shadow.p_1 < shadow.p_4 &&
            shadow.p_2 == shadow.p_3)) {
            return (0);
        } else
            return (2);
    }
    return (1);
}

void up_tile(t_game *game, int up, int i, int j)
{
    game->m3[j][i] = game->m3[j][i] + up;
    game->m3[j - 1][i - 1] = game->m3[j - 1][i - 1] + up;
    game->m3[j][i - 1] = game->m3[j][i - 1] + up;
    game->m3[j - 1][i] = game->m3[j - 1][i] + up;
}

int check_tile(int mouse[3], t_game *game)
{
    int i  = 0;
    int j = game->height - 1;
    int ret = 0;

    while (j != 0 && ret == 0) {
        i = game->width - 1;
        while (i != 0 && ret == 0) {
            ret = check_button_2(mouse, i, j, game);
            i = i - 1;
        }
        j = j - 1;
    }
    return (ret);
}
