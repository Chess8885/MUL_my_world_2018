/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** vertex
*/

#include "my.h"

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = point1[0], .color = sfWhite};
    sfVertex vertex2 = {.position = point2[0], .color = sfWhite};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

sfVertexArray *is_create(sfVertexArray *va, sfVertex v, sfVertex w, sfVertex x)
{
    sfVertexArray_append(va, v);
    sfVertexArray_append(va, w);
    sfVertexArray_append(va, x);
    sfVertexArray_setPrimitiveType(va, sfTrianglesStrip);
    return (va);
}

sfVertexArray *create_dirt(sfVector2f *p, sfVector2f *p2, sfVector2f *p3, int l)
{
    sfColor c[3] = {{120, 165, 55, 255}, {155, 190, 95, 255},
                    {175, 215, 120, 255}};
    sfVertexArray *vertex_array = vertex_array = sfVertexArray_create();
    sfVertex vertex = {.position = p[0], .color = c[l]};
    sfVertex vertex1 = {.position = p2[0], .color = c[l]};
    sfVertex vertex2 = {.position = p3[0], .color = c[l]};

    is_create(vertex_array, vertex, vertex1, vertex2);
    return (vertex_array);
}

sfVertex get_vertex(int col[3], int nb, sfVector2f **mouse, t_game game)
{
    sfVertex v;
    sfColor color[2];
    sfVector2f point;

    init_color_point(color, point);
    if (col[1] == 0) {
        if (nb == 1)
            v.position = mouse[0][col[0]];
        else {
            v.position = mouse[col[0]][0];
            v.color = color[nb - 1];
        }
    }
    if (col[1] == 1) {
        if (nb == 1)
            point = get_point(col[2], 0, game);
        else {
            point = get_point(0, col[2], game);
            v.position = point;
            v.color = color[nb - 1];
        }
    }
    return (v);
}

sfVertexArray *get_base(int nb, int max, sfVector2f **mouse, t_game game)
{
    sfVertex v = {0};
    sfVertexArray *vrtx = sfVertexArray_create();
    int color[3];

    init_color_base(color);
    while (color[0] < max) {
        if (color != 0 && color[1] == 0) {
            v = get_vertex(color, nb, mouse, game);
            color[1] = 1;
        }
        if (color != 0 && color[1] == 1) {
            color[2] = color[0] * game.scale_x;
            v = get_vertex(color, nb, mouse, game);
            color[1] = 0;
            color[0] = color[0] + 1;
        }
        sfVertexArray_append(vrtx, v);
    }
    sfVertexArray_setPrimitiveType(vrtx, sfTrianglesStrip);
    return (vrtx);
}
