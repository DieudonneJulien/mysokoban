/*
** EPITECH PROJECT, 2021
** move_left.c
** File description:
** Move player to the left.
*/

#include "../include/my.h"

static int box_case(buffer_t *map, coord_t *pos)
{
    int a = 0;

    if (map->arr[map->P_y][map->P_x - 2] == '#')
        return (-1);
    if (map->arr[map->P_y][map->P_x - 2] == 'X')
        return (-1);
    was_there_a_o(map, pos);
    was_box_on_a_o(map, pos, map->P_y, map->P_x - 1);
    a = is_box_placed(map, pos, map->P_y, map->P_x - 2);
    map->arr[map->P_y][map->P_x - 1] = 'P';
    map->arr[map->P_y][map->P_x - 2] = 'X';
    map->P_x = map->P_x - 1;
    if (is_game_won(pos) == 0)
        return (0);
    if (a == 0)
        is_box_stuck(map, pos, map->P_y, map->P_x - 1);
    return (-1);
}

int left_key(buffer_t *map, coord_t *pos)
{
    if (map->P_x == 0)
        return (-1);
    switch(map->arr[map->P_y][map->P_x - 1])
    {
    case '#':
        return (-1);
    case 'X':
        return (box_case(map, pos));
    case 'O':
        was_there_a_o(map, pos);
        map->arr[map->P_y][map->P_x - 1] = 'P';
        map->P_x = map->P_x - 1;
        return (-1);
    case ' ':
        was_there_a_o(map, pos);
        map->arr[map->P_y][map->P_x - 1] = 'P';
        map->P_x = map->P_x - 1;
        return (-1);
    }
}
