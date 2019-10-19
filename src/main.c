/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** main
*/

#include "my.h"

int launch_program(int argc, char **argv)
{
    sfVideoMode mode;
    sfRenderWindow *window;

    if (check_help(argc, argv) == -1) {
        return (0);
    }
    mode.width = 1920;
    mode.height = 1080;
    mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(mode, "world_of_dirt", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    if (init_world(window) == -1)
        return (84);
    return (0);
}

int main(int argc, char **argv)
{
    if (launch_program(argc, argv) == 84) {
        return (84);
    }
    return (0);
}
