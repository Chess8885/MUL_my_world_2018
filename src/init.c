/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** functions
*/

#include "my.h"

int init_animation(t_game *game, sfClock *clock, sfRenderWindow *window)
{
    game->scale_x = game->scale_x + 1;
    game->scale_y = game->scale_y + 1;
    game->scale_z = game->scale_x / 4;
    sfClock_restart(clock);
    display_map(window, *game);
    return (0);
}

int launch_animation(sfRenderWindow *window, t_game *game)
{
    sfEvent event;
    sfClock *clock = sfClock_create();
    sfTime time;

    while (game->scale_x != 64) {
        if (sfRenderWindow_pollEvent(window, &event) == sfTrue &&
            event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (0);
        }
        time = sfClock_getElapsedTime(clock);
        if (time.microseconds >= 2500) {
            init_animation(game, clock, window);
        }
    }
    return (0);
}

int init_struct(t_game *game)
{
    game->scale_x = 0;
    game->scale_y = 0;
    game->scale_z = 0;
    game->cos = 45;
    game->sin = 34.8;
    game->button[3] = 0;
    game->scroll_x = 0;
    game->scroll_y = 0;
    game->height = 0;
    game->width = 0;
    game->m3 = 0;
    game->object = 0;
    game->sprite = 0;
    game->music = 0;
    return (0);
}

int loop_game(sfRenderWindow *window, t_game game)
{
    int i = 0;

    while (sfRenderWindow_isOpen(window) != 0) {
        i = handle_event(window, &game);
        if (i == -1) {
            return (-1);
        }
        else if (i == 1) {
            i = display_map(window, game);
        }
        i = 0;
    }
    return (0);
}

int init_world(sfRenderWindow *window)
{
    t_game game;

    init_struct(&game);
    if (load_sprite(&game) != 0 ||
        load_map(&game) == -1 ||
        load_music(&game) != 0 ||
        launch_animation(window, &game) != 0) {
        return (-1);
    }
    if (loop_game(window, game) == -1) {
        return (-1);
    }
    destroy_all(&game);
    return (0);
}
