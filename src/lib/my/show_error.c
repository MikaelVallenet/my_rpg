/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myworld-david.gozlan
** File description:
** show_error
*/

#include <unistd.h>
int my_strlen(char *str);

int show_error(char *message)
{
    write(2, message, my_strlen(message));
    write(2, "\n", 1);
    return (1);
}