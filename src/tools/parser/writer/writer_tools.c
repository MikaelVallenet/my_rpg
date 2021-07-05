/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** writer_tools
*/

#include "../parser.h"

void write_str(int fd, char *str)
{
    write(fd, str, my_strlen(str));
}

void write_tab(int fd, char *str, int nb_tab)
{
    for (int i = 0; i < nb_tab; i++)
        write(fd, "  ", 2);
    write_str(fd, str);
}