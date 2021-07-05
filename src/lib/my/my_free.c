/*
** EPITECH PROJECT, 2020
** my_free.c
** File description:
** free all the stuff
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void my_free(int nb_elements, ...)
{
    va_list ap;
    void *stuff;

    va_start(ap, nb_elements);
    for (int i = 0; i < nb_elements; i += 1) {
        stuff = va_arg(ap, void *);
        free(stuff);
    }
    va_end(ap);
}