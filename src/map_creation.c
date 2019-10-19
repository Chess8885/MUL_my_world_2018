/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** map
*/

#include "my.h"

char *get_buffer(int size)
{
    FILE *map = fopen("map", "r");
    char *buffer = malloc(sizeof(char) * (size + 1));

    fread(buffer, size, 1, map);
    buffer[size] = 0;
    fclose(map);
    return (buffer);
}

int malloc_object(int i, int **object, t_game game)
{
    while (i < game.height) {
        object[i] = malloc(sizeof(int) * game.width);
        if (object[i] == NULL)
            return (0);
        i++;
    }
    return (1);
}

int **get_object(char *buffer, t_game game)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int **object = malloc(sizeof(int *) * game.height);

    if (malloc_object(i, object, game) == 0)
        return (NULL);
    while (j != game.height) {
        i = 0;
        k = 1;
        while (i != game.width) {
            object[j][i] = buffer[k] - 48;
            i++;
            k = k + 1;
        }
        j++;
        k++;
    }
    return (object);
}

int malloc_map(t_game game, int **map, int i)
{
    while (i != game.height) {
        map[i] = malloc(sizeof(int) * game.width);
        if (map[i] == NULL)
            return (1);
        i++;
    }
    return (0);
}

int **get_map(char *buffer, t_game game)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int **map = malloc(sizeof(int *) * game.height);

    if (malloc_map(game, map, i) == 1) {
        return (NULL);
    }
    while (j != game.height) {
        i = 0;
        while (i != game.width) {
            map[j][i] = buffer[k] - 48;
            i++;
            k = k + 3;
        }
        j++;
        k++;
    }
    return (map);
}
