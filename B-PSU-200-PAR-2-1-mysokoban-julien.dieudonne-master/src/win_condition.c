/*
** EPITECH PROJECT, 2021
** win_condition.c
** File description:
** Check if game is win.
*/

#include "../include/my.h"

int is_game_won(coord_t *pos)
{
    int k = 0;

    while (k < pos[0].nb) {
        if (pos[k].box == 0)
            return (-1);
        k++;
    }
    return (0);
}
