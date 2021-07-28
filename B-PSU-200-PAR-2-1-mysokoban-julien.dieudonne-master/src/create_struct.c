/*
** EPITECH PROJECT, 2021
** create_struct.c
** File description:
** Create struct.
*/

#include "../include/my.h"
#include <stdlib.h>

static int calc_nbr_of_o(buffer_t *map, int nb_o, int i, int j)
{
    if (map->arr[i][j] == 'O') {
        nb_o = nb_o + 1;
    }
    return (nb_o);
}

static int get_nbr_of_o(buffer_t *map)
{
    int i = 0;
    int j = 0;
    int nb_o = 0;

    while (i < map->lines) {
        while (j < map->cols) {
            nb_o = calc_nbr_of_o(map, nb_o, i, j);
            j++;
        }
        j = 0;
        i++;
    }
    return (nb_o);
}

static int get_o_pos(buffer_t *map, int i, int k, coord_t *pos)
{
    int j = 0;

    while (j < map->cols) {
        if (map->arr[i][j] == 'O') {
            pos[k].x = j;
            pos[k].y = i;
            pos[k].nb = pos[0].nb;
            pos[k].box = 0;
            k = k + 1;
        }
        j++;
    }
    return (k);
}

coord_t *create_o_position(buffer_t *map)
{
    int i = 0;
    int k = 0;
    int nb_o = get_nbr_of_o(map);
    coord_t *pos;

    if (nb_o == 0)
        exit (0);
    pos = malloc(sizeof(coord_t) * nb_o);
    if (nb_o > 0)
        pos[0].nb = nb_o;
    while (i < map->lines) {
        k = get_o_pos(map, i, k, pos);
        i++;
    }
    return (pos);
}
