/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** functions
*/

#include "my.h"

int init_color_point(sfColor color[2], sfVector2f point)
{
    color[0].r = 140;
    color[0].g = 130;
    color[0].b = 70;
    color[0].a = 255;
    color[1].r = 100;
    color[1].g = 85;
    color[1].b = 45;
    color[1].a = 255;
    point.x = 0;
    point.y = 0;
    return (0);
}

int init_color_base(int color[3])
{
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    return (0);
}

int display_tool(sfRenderWindow *window, t_game game)
{
    int i = 1;
    sfVector2f pos;

    pos.x = 10;
    pos.y = 10;
    while (i != 4) {
        sfSprite_setPosition(game.sprite[i], pos);
        sfRenderWindow_drawSprite(window, game.sprite[i], 0);
        pos.x = pos.x + 90;
        i++;
    }
    return (0);
}
