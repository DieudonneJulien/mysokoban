/*
** EPITECH PROJECT, 2021
** move_down.c
** File description:
** Move player down.
*/

#include "../include/my.h"

static int box_case(buffer_t *map, coord_t *pos)
{
    int a = 0;

    if (map->arr[map->P_y + 2][map->P_x] == '#')
        return (-1);
    if (map->arr[map->P_y + 2][map->P_x] == 'X')
        return (-1);
    was_there_a_o(map, pos);
    was_box_on_a_o(map, pos, map->P_y + 1, map->P_x);
    a = is_box_placed(map, pos, map->P_y + 2, map->P_x);
    map->arr[map->P_y + 1][map->P_x] = 'P';
    map->arr[map->P_y + 2][map->P_x] = 'X';
    map->P_y = map->P_y + 1;
    if (is_game_won(pos) == 0)
        return (0);
    if (a == 0)
        is_box_stuck(map, pos, map->P_y + 1, map->P_x);
    return (-1);
}

int down_key(buffer_t *map, coord_t *pos)
{
    if (map->P_y == map->lines - 1)
        return (-1);
    switch(map->arr[map->P_y + 1][map->P_x])
    {
    case '#':
        return (-1);
    case 'X':
        return (box_case(map, pos));
    case 'O':
        was_there_a_o(map, pos);
        map->arr[map->P_y + 1][map->P_x] = 'P';
        map->P_y = map->P_y + 1;
        return (-1);
    case ' ':
        was_there_a_o(map, pos);
        map->arr[map->P_y + 1][map->P_x] = 'P';
        map->P_y = map->P_y + 1;
        return (-1);
    }
}
