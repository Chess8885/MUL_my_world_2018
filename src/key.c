/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** key
*/

#include "my.h"

int is_rotate(sfEvent event, t_game *game)
{
    if (event.key.code == 18 || event.key.code == 25) {
        return (1);
    }
    return (0);
}

int is_scroll(sfEvent event, t_game *game)
{
    if (event.key.code >= 71 &&
        event.key.code <= 74) {
        return (1);
    }
    return (0);
}

int key_press(sfEvent event, t_game *game)
{
    if (is_rotate(event, game) != 0) {
        return (rotate_animation(event.key.code, game));
    }
    if (is_scroll(event, game) != 0) {
        return (scroll_animation(event.key.code, game));
    }
    return (0);
}
