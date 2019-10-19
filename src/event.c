/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** event
*/

#include "my.h"

int tile_event(sfRenderWindow *win, sfVector2f **m, int ev[3], sfVertexArray *v)
{
    if (ev[0] > 0) {
        v = create_line(&m[ev[1]][ev[0]], &m[ev[1]][ev[0] - 1]);
        sfRenderWindow_drawVertexArray(win, v, NULL);
    }
    if (ev[1] > 0) {
        v = create_line(&m[ev[1]][ev[0]], &m[ev[1] - 1][ev[0]]);
        sfRenderWindow_drawVertexArray(win, v, NULL);
    }
    return (0);
}

int all_events(sfRenderWindow *window, t_game *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed)
        return (key_press(event, game));
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed)
        return (mouse_button(window, event, game, 0));
    if (event.type == sfEvtMouseWheelMoved)
        return (mouse_wheel(window, event, game));
    if (event.type == sfEvtMouseButtonReleased)
        return (mouse_button(window, event, game, 1));
    if (event.type == sfEvtMouseMoved)
        return (check_move(event.mouseMove.x, event.mouseMove.y, game));
    return (0);
}

int handle_event(sfRenderWindow *window, t_game *game)
{
    sfEvent event;
    int ret = 0;

    if (sfRenderWindow_waitEvent(window, &event) == sfTrue) {
        ret = all_events(window, game, event);
        return (ret);
    }
    return (0);
}
