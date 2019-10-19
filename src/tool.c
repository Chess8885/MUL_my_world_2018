/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** functions
*/

#include "my.h"

int init_color_tool(sfColor c[2])
{
    c[1].r = 255;
    c[1].g = 255;
    c[1].b = 255;
    c[1].a = 255;
    c[2].r = 255;
    c[2].g = 255;
    c[2].b = 10;
    c[2].a = 255;
    return (0);
}

int check_tool_condition(int i, int mouse[3])
{
    if (mouse[0] > i * 10 + (i - 1) * 80 &&
        mouse[0] < i * 10 + i * 80 &&
        mouse[1] > 10 && mouse[1] < 90) {
        return (1);
    }
    return (0);
}

int check_tool(int mouse[3], t_game *game, int j)
{
    int i = 1;
    sfColor c[2];
    int (*ptr[3])() = {&reset_map, &load_map, &save_map};

    init_color_tool(c);
    while (i != 4) {
        if (check_tool_condition(i, mouse) != 0) {
            sfSprite_setColor(game->sprite[i], c[j]);
            return ((*ptr[i - 1])(game));
        }
        i++;
    }
    return (0);
}
