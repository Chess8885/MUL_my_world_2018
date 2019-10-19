/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define WIN_W (1920)
#define WIN_H (1080)
#define WIN_H_4 (WIN_H / 4)
#define WIN_W_2 (WIN_W / 2)

struct s_shadow {
    int p_1;
    int p_2;
    int p_3;
    int p_4;
};

typedef struct s_shadow t_shadow;

struct s_game {
    int scale_x;
    int scale_y;
    int scale_z;
    double cos;
    double sin;
    int button[3];
    int scroll_x;
    int scroll_y;
    int height;
    int width;
    int **m3;
    int **object;
    sfSprite **sprite;
    sfMusic *music;
    t_shadow shadow;
};

typedef struct s_game t_game;

sfVertexArray *get_base(int nb, int max, sfVector2f **m, t_game game);
sfVertexArray *create_line(sfVector2f *p1, sfVector2f *p2);
sfVertexArray *create_t(sfVector2f *, sfVector2f *, sfVector2f *, int);
sfVertexArray *create_dirt(sfVector2f *, sfVector2f *, sfVector2f *, int );

sfVector2f *get_square(int i, int j, t_game *game);
sfVector2f get_point(int x, int y, t_game game);
sfVector2f project_iso_point(int x, int y, int z, t_game game);
sfVector2f  **create_2d_map(t_game game);

char *get_buffer(int size);

int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
void my_putstr(const char *str, int filedes);
int check_help(int argc, char **argv);
int init_world(sfRenderWindow *window);
int load_map(t_game *game);
int save_map(t_game *game);
int reset_map(t_game *game);
int display_map(sfRenderWindow *window, t_game game);
int handle_event(sfRenderWindow *window, t_game *game);
int check_tile(int m[3], t_game *game);
int check_button(int mouse[3], int i, int j, t_game *game);
int check_button_2(int mouse[3], int i, int j, t_game *game);
int check_point(int m[3], t_game *game);
int rotate_animation(int key, t_game *game);
int scroll_animation(int key, t_game *game);
int get_shadow(int **m, int i, int j);
int **get_map(char *buf, t_game game);
int **get_object(char *buf, t_game game);
int check_tool(int m[3], t_game *game, int action);
int check_move(int x, int y, t_game *game);
int display_tool(sfRenderWindow *window, t_game game);
int get_map_size(t_game *game);
int error_save_map(int fd);
int destroy_all(t_game *game);
int key_press(sfEvent event, t_game *game);
int mouse_wheel(sfRenderWindow *window, sfEvent event, t_game *game);
int check_button(int mouse[3], int i, int j, t_game *game);
int load_music(t_game *game);
int change_value_pos(t_game game, sfVector2f pos, sfVector2f p1, sfVector2f p2);
int init_obj(sfVector2f pos, sfVector2f scale, t_game game);
int load_sprite(t_game *game);
int tile_event(sfRenderWindow *, sfVector2f **, int ev[3], sfVertexArray *);
int draw_tile_obj(sfRenderWindow *w, sfVector2f **map, int evt[3], t_game g);
int draw_map(sfRenderWindow *window, sfVector2f **map, t_game game);
int tool_draw(t_game game, sfVector2f **m, sfVertexArray *v, sfRenderWindow *w);
int init_color_base(int color[3]);
int init_color_point(sfColor color[2], sfVector2f point);
int is_move(int x, int y, t_game *game, sfColor c1);
int link_sprite(t_game *game);
int mouse_button(sfRenderWindow *, sfEvent event, t_game *, int);

void up_tile(t_game *game, int up, int i, int j);
void draw_obj(sfRenderWindow *window, t_game game, int i, int j);
void draw_tile(sfRenderWindow *window, sfVector2f **mouse, int event[3]);
void draw_base(sfRenderWindow *window, sfVector2f **m, t_game game);

#endif
