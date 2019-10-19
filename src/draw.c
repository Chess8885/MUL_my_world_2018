/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** draw
*/

#include "my.h"

int draw_tile_obj(sfRenderWindow *w, sfVector2f **map, int evt[3], t_game g)
{
    draw_tile(w, map, evt);
    draw_obj(w, g, evt[0], evt[1]);
    return (0);
}

int draw_map(sfRenderWindow *window, sfVector2f **map, t_game game)
{
    int event[3] = {0};

    event[1] = game.height - 1;
    while (event[1] != -1) {
        event[0] = game.width - 1;
        while (event[0] != -1) {
            event[2] = get_shadow(game.m3, event[0], event[1]);
            draw_tile_obj(window, map, event, game);
            event[0] = event[0] - 1;
        }
        event[1] = event[1] - 1;
    }
    draw_base(window, map, game);
    return (0);
}

void draw_tile(sfRenderWindow *window, sfVector2f **mouse, int event[3])
{
    sfVertexArray *vertex = NULL;

    if (event[1] > 0 && event[0] > 0) {
        vertex = create_dirt(&mouse[event[1]-1][event[0]-1],
        &mouse[event[1]][event[0]-1],
        &mouse[event[1]][event[0]], event[2]);
        sfRenderWindow_drawVertexArray(window, vertex, NULL);
        vertex = create_dirt(&mouse[event[1]-1][event[0]-1],
        &mouse[event[1]-1][event[0]],
        &mouse[event[1]][event[0]], event[2]);
        sfRenderWindow_drawVertexArray(window, vertex, NULL);
    }
    tile_event(window, mouse, event, vertex);
}

void draw_obj(sfRenderWindow *window, t_game game, int i, int j)
{
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f point1;
    sfVector2f point2;

    init_obj(pos, scale, game);
    if (j > 0 && j < game.height &&
        i > 0 && i < game.width &&
        game.object[j][i] != 0) {
        point1 = project_iso_point(i * game.scale_x, j * game.scale_y,
        game.m3[j][i] * game.scale_z, game);
        point2 = project_iso_point((i - 1) * game.scale_x,
        (j - 1) * game.scale_y, game.m3[j - 1][i - 1] * game.scale_z, game);
        change_value_pos(game, pos, point1, point2);
        sfSprite_setScale(game.sprite[0], scale);
        sfSprite_setPosition(game.sprite[0], pos);
        sfRenderWindow_drawSprite(window, game.sprite[0], 0);
    }
}

int tool_draw(t_game game, sfVector2f **m, sfVertexArray *v, sfRenderWindow *w)
{
    sfVector2f p1 = get_point(0, 0, game);
    sfVector2f p2 = get_point((game.width - 1) * game.scale_x, 0, game);
    sfVector2f p3 = get_point(0, (game.height - 1) * game.scale_y, game);

    v = get_base(1, game.width, m, game);
    sfRenderWindow_drawVertexArray(w, v, NULL);
    v = get_base(2, game.height, m, game);
    sfRenderWindow_drawVertexArray(w, v, NULL);
    v = create_line(&m[0][0], &p1);
    sfRenderWindow_drawVertexArray(w, v, NULL);
    v = create_line(&m[game.height - 1][0], &p3);
    sfRenderWindow_drawVertexArray(w, v, NULL);
    v = create_line(&m[0][game.width - 1], &p2);
    sfRenderWindow_drawVertexArray(w, v, NULL);
    v = create_line(&p2, &p1);
    sfRenderWindow_drawVertexArray(w, v, NULL);
    v = create_line(&p3, &p1);
    sfRenderWindow_drawVertexArray(w, v, NULL);
    return (0);
}
