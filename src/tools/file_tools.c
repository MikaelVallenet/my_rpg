/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** file_tools
*/

#include "rpg.h"

int file_size(char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    char buff;
    int size = 0;

    if (fd < 0)
        return (-1);
    for (; read(fd, &buff, 1); size++);
    return (size);
}

int read_file(char *file_path, char **buffer)
{
    int file_desc = open(file_path, O_RDONLY);
    int size = file_size(file_path);
    char *buff;

    if (file_desc < 0)
        return (OPEN_ERROR);
    buff = malloc(sizeof(char) * (size + 1));
    if (buff == NULL)
        return (ALLOC_ERROR);
    buff[size] = '\0';
    if (read(file_desc, buff, size) != size)
        return (READ_ERROR);
    *buffer = buff;
    return (0);
}