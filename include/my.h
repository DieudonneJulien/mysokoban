/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** Contains prototypes of sokoban.
*/

#ifndef MY_H_
#define MY_H_

typedef struct buffer_s
{
    char **arr;
    int lines;
    int cols;
    int P_x;
    int P_y;
    int box;
} buffer_t;

typedef struct coord_s
{
    int x;
    int y;
    int nb;
    int box;
} coord_t;

//errors.c
void errors(char const *str);

//load_file_in_mem.c
buffer_t get_buffer(char const *filepath);

//sokoban.c
int sokoban(buffer_t *map, coord_t *pos);

//get_nbr_of_box.c
void get_number_of_box(buffer_t *map);

//create_struct.c
coord_t *create_o_position(buffer_t *map);

//move_player.c
int move_player(int key, buffer_t *map, coord_t *pos);

//move_box.c
int is_box_placed(buffer_t *map, coord_t *pos, int i, int j);
int is_box_stuck(buffer_t *map, coord_t *pos, int i, int j);
void was_there_a_o(buffer_t *map, coord_t *pos);
void was_box_on_a_o(buffer_t *map, coord_t *pos, int i, int j);

//win_condition.c
int is_game_won(coord_t *pos);

//move_down.c
int down_key(buffer_t *map, coord_t *pos);

//move_left.c
int left_key(buffer_t *map, coord_t *pos);

//move_up.c
int up_key(buffer_t *map, coord_t *pos);

//move_right.c
int right_key(buffer_t *map, coord_t *pos);

#endif
