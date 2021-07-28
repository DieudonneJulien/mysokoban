/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** Main of sokoban.
*/

#include "../include/my.h"
#include <stdlib.h>
#include <unistd.h>

static char my_putchar(char c)
{
    write (1, &c, 1);
}

static int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

static void display_usage(void)
{
    my_putstr("USAGE\n\t./my_sokoban map\nDESCRIPTION\n");
    my_putstr("\tmap  File representing the warehouse map, cotaining '#' for");
    my_putstr(" walls,\n\t     'P' for the player, 'X' for boxes and 'O' for");
    my_putstr(" storage locations.\n\tUse arrow keys to move the player.\n");
    my_putstr("\tReturns 0 if you win, 1 if you lost.\n");
}

static void free_variables(buffer_t *map, coord_t *pos)
{
    int i = 0;

    while (i < map->lines) {
        free(map->arr[i]);
        i++;
    }
    free(map->arr);
    free(pos);
}

int main(int ac, char **av)
{
    buffer_t map;
    coord_t *pos;
    int win = 32;

    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        display_usage();
        return (0);
    }
    while (win == 32) {
        map = get_buffer(av[1]);
        pos = create_o_position(&map);
        win = sokoban(&map, pos);
        free_variables(&map, pos);
    }
    return (win);
}
