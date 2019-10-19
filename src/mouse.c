/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** mouse
*/

#include "my.h"

int check_mouse_button(int mouse[3], sfEvent event)
{
    if (event.mouseButton.button == 0) {
        return (1);
    }
    if (event.mouseButton.button == 1) {
        return (-1);
    }
    return (0);
}

int mouse_button(sfRenderWindow *window, sfEvent event, t_game *game, int a)
{
    int mouse[3] = {event.mouseButton.x, event.mouseButton.y, 0};
    int ret = 0;

    if (check_mouse_button(mouse, event) == 1) {
        mouse[2] = 1;
    }
    if (check_mouse_button(mouse, event) == -1) {
        mouse[2] = -1;
    }
    if ((ret = check_tool(mouse, game, a)) != 0)
        return (ret);
    if (check_point(mouse, game) == 1)
        return (1);
    ret = check_tile(mouse, game);
    return (ret);
}

int mouse_wheel(sfRenderWindow *window, sfEvent event, t_game *game)
{
    if (event.mouseWheel.delta > 0 && game->scale_x != 0) {
        game->scale_x = game->scale_x + event.mouseWheel.delta * 4;
        game->scale_y = game->scale_y + event.mouseWheel.delta * 4;
    } else {
        return (0);
    }
    game->scale_z = game->scale_x / 4;
    return (1);
}
