/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** display.c
*/

#include "my.h"

void draw_base(sfRenderWindow *window, sfVector2f **m, t_game game)
{
    sfVertexArray *vertex = NULL;

    tool_draw(game, m, vertex, window);
}

int change_value_pos(t_game game, sfVector2f pos, sfVector2f p1, sfVector2f p2)
{
    pos.x = p1.x + WIN_W_2 + game.scroll_x -
        game.scale_x / 2 + game.scale_x / 6;
    pos.y = p2.y - (p2.y - p1.y) / 2
        + WIN_H - WIN_H_4 + game.scroll_y - game.scale_x / 1.2;
    return (0);
}

int init_obj(sfVector2f pos, sfVector2f scale, t_game game)
{
    scale.x = game.scale_x / 64.0;
    scale.y = game.scale_x / 64.0;
    pos.x = 0;
    pos.y = 0;
    return (0);
}

int draw_and_display(sfRenderWindow *window, t_game game, sfVector2f **map)
{
    draw_map(window, map, game);
    display_tool(window, game);
    return (0);
}

int display_map(sfRenderWindow *window, t_game game)
{
    sfVector2f **map = NULL;
    sfColor color;

    color.r = 40;
    color.g = 50;
    color.b = 60;
    color.a = 0;
    sfRenderWindow_clear(window, color);
    map = create_2d_map(game);
    if (map == NULL) {
        return (1);
    }
    draw_and_display(window, game, map);
    sfRenderWindow_display(window);
    return (0);
}
