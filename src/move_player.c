/*
** EPITECH PROJECT, 2021
** move_character.c
** File description:
** Functions of movement of character.
*/

#include "../include/my.h"
#include <ncurses.h>

int move_player(int key, buffer_t *map, coord_t *pos)
{
    int ret_value;

    switch(key) {
    case KEY_UP:
        ret_value = up_key(map, pos);
        break;
    case KEY_RIGHT:
        ret_value = right_key(map, pos);
        break;
    case KEY_DOWN:
        ret_value = down_key(map, pos);
        break;
    case KEY_LEFT:
        ret_value = left_key(map, pos);
        break;
    }
    if (ret_value == 0)
        return (0);
    if (map->box <= 0)
        return (1);
    return (-1);
}
