/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** main
*/

#include "rpg.h"

static int show_opt(char *str)
{
    char *buff;
    char usages[30];
    int size;

    switch (str[1]) {
    case ('h'):
        my_strcpy(usages, "./usages/help.txt");
        break;
    default:
        return (UNKNOWN_OPTION_ERROR);
    }
    size = file_size(usages);
    buff = malloc(sizeof(char) * (size + 1));
    read(open(usages, O_RDONLY), buff, size);
    my_putstr(buff);
    free(buff);
    return (2);
}

int error_handling(char *argument)
{
    if (open(argument, O_RDONLY) == -1) {
        return (READ_ERROR);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac > 1 && av[1][0] == '-')
        return (show_opt(av[1]));
    if (ac == 2 && error_handling(av[1]))
        return (84);
    if (manage_windows(head_initialize(ac, av)))
        return (84);
    return (0);
}