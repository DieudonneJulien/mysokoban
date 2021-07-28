/*
** EPITECH PROJECT, 2021
** sokoban.c
** File description:
** Main function of sokoban.
*/

#include "../include/my.h"
#include <ncurses.h>

static int get_p_position(buffer_t *map, int i)
{
    int j = 0;

    while (j < map->cols) {
        if (map->arr[i][j] == 'P') {
            map->P_x = j;
            map->P_y = i;
            return (1);
        }
        j++;
    }
    return (0);
}

static void create_p_position(buffer_t *map)
{
    int i = 0;

    while (i < map->lines) {
        if (get_p_position(map, i) == 1)
            return;
        i++;
    }
}

static void print_map(buffer_t *map)
{
    int i = 0;
    int lines = LINES / 2 - map->lines / 2;

    if (LINES - 2 < map->lines || COLS - 2 < map->cols)
        mvprintw(LINES / 2, COLS / 2 - 10, "Resize to print map");
    else {
        while (i < map->lines) {
            mvprintw(lines, COLS / 2 - map->cols / 2, map->arr[i]);
            lines = lines + 1;
            i = i + 1;
        }
    }
}

static int game_loop(buffer_t *map, coord_t *pos)
{
    int key = -1;
    int ret_value;

    while (key != '\n') {
        clear();
        print_map(map);
        refresh();
        key = getch();
        ret_value = move_player(key, map, pos);
        if (key == ' ')
            return (32);
        if (ret_value != -1) {
            print_map(map);
            refresh();
            endwin();
            return (ret_value);
        }
    }
    endwin();
    return (0);
}

int sokoban(buffer_t *map, coord_t *pos)
{
    get_number_of_box(map);
    create_p_position(map);
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    return (game_loop(map, pos));
}
