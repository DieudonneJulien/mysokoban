/*
** EPITECH PROJECT, 2021
** get_nbr_of_box.c
** File description:
** Calc the number of box present on the map.
*/

#include "../include/my.h"
#include <stdlib.h>

static void add_a_box(buffer_t *map, int i, int j)
{
    if (map->arr[i][j] == 'X')
        map->box = map->box + 1;
}

void get_number_of_box(buffer_t *map)
{
    int i = 0;
    int j = 0;

    while (i < map->lines) {
        while (j < map->cols) {
            add_a_box(map, i, j);
            j++;
        }
        j = 0;
        i++;
    }
    if (map->box == 0)
        exit(0);
}
