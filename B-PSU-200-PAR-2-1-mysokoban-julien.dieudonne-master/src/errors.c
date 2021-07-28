/*
** EPITECH PROJECT, 2021
** errors.c
** File description:
** Error managment of sokoban.
*/

#include <stdlib.h>

static void are_characters_valid(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != '\n' && str[i] != '#' && str[i] != 'X'
            && str[i] != 'O' && str[i] != 'P' && str[i] != ' ')
            exit(84);
        i++;
    }
}

void errors(char const *str)
{
    are_characters_valid(str);
}
