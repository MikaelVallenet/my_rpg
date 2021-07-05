/*
** EPITECH PROJECT, 2020
** MyLib
** File description:
** my_putnbr
*/

#include "my_lib.h"
#include <stdlib.h>

void my_putnbr(long long arg)
{
    char *nbr = "";
    int negative = 0;

    if (arg == 0)
        my_putchar('0');
    if (arg < 0) {
        arg *= -1;
        negative = 1;
    }
    while (arg > 0) {
        nbr = my_addchar(nbr, arg % 10 + 48, 1);
        arg = arg / 10;
    }
    if (negative)
        nbr = my_addchar(nbr, '-', 1);
    my_putstr(nbr);
    if (my_strcmp(nbr, "") != 0)
        free(nbr);
}