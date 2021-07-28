/*
** EPITECH PROJECT, 2021
** move_box.c
** File description:
** Functions called when mooving a box.
*/

#include "../include/my.h"

int is_box_placed(buffer_t *map, coord_t *pos, int i, int j)
{
    int k = 0;

    while (k < pos[0].nb) {
        if (i == pos[k].y && j == pos[k].x) {
            pos[k].box = 1;
            map->box = map->box - 1;
            return (1);
        }
        k++;
    }
    return (0);
}

static int simple_stuck_case(buffer_t *map, coord_t *pos, int i, int j)
{
    if (is_box_placed(map, pos, i, j) == 1)
        return (0);
    if (map->arr[i - 1][j] == '#' && map->arr[i][j - 1] == '#') {
        map->box = map->box - 1;
        return (1);
    }
    if (map->arr[i - 1][j] == '#' && map->arr[i][j + 1] == '#') {
        map->box = map->box - 1;
        return (1);
    }
    if (map->arr[i + 1][j] == '#' && map->arr[i][j - 1] == '#') {
        map->box = map->box - 1;
        return (1);
    }
    if (map->arr[i + 1][j] == '#' && map->arr[i][j + 1] == '#') {
        map->box = map->box - 1;
        return (1);
    }
    return (0);
}

int is_box_stuck(buffer_t *map, coord_t *pos, int i, int j)
{
    if (simple_stuck_case(map, pos, i, j) == 1)
        return (1);
    return (0);
}

void was_there_a_o(buffer_t *map, coord_t *pos)
{
    int k = 0;

    while (k < pos[0].nb) {
        if (map->P_y == pos[k].y && map->P_x == pos[k].x) {
            map->arr[map->P_y][map->P_x] = 'O';
            return;
        }
        k++;
    }
    map->arr[map->P_y][map->P_x] = ' ';
}

void was_box_on_a_o(buffer_t *map, coord_t *pos, int i, int j)
{
    int k = 0;

    while (k < pos[0].nb) {
        if (i == pos[k].y && j == pos[k].x) {
            pos[k].box = 0;
            map->box = map->box + 1;
            return;
        }
        k++;
    }
}
