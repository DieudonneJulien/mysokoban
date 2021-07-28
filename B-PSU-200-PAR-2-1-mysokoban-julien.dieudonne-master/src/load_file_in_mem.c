/*
** EPITECH PROJECT, 2020
** load_file_in_mem.c
** File description:
** Load content of a file in memory, returns a string buffer.
*/

#include "../include/my.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

static int get_nb_lines(char const *buf)
{
    int i = 0;
    int res = 0;

    while (buf[i] != '\0') {
        if (buf[i] == '\n') {
            res = res + 1;
        }
        i++;
    }
    return (res);
}

static int get_nb_cols(char const *buf)
{
    int i = 0;

    while (buf[i] != '\n')
        i++;
    return (i);
}

static char *load_file_in_mem(char const *filepath)
{
    struct stat sb;
    int fd;
    char *buff;
    int size;

    if ((fd = open(filepath, O_RDONLY)) == -1) {
        return ("ERROR");
    }
    stat(filepath, &sb);
    size = sb.st_size;
    buff = malloc(sizeof(char) * (size + 1));
    if (read(fd, buff, size) == -1)
        return ("ERROR");
    buff[size] = '\0';
    return (buff);
}

static char **get_map(char const *buff, int nb_lines, int nb_cols)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **arr = malloc(sizeof(char *) * (nb_lines + 1));

    while (i < nb_lines) {
        arr[i] = malloc(sizeof(char) * (nb_cols + 1));
        while (j < nb_cols) {
            arr[i][j] = buff[k];
            j++;
            k++;
        }
        j = 0;
        k++;
        i++;
    }
    arr[i] = NULL;
    return (arr);
}

buffer_t get_buffer(char const *filepath)
{
    buffer_t map;
    char *buf;

    buf = load_file_in_mem(filepath);
    errors(buf);
    map.lines = get_nb_lines(buf);
    map.cols = get_nb_cols(buf);
    map.arr = get_map(buf, map.lines, map.cols);
    map.box = 0;
    free(buf);
    return (map);
}
