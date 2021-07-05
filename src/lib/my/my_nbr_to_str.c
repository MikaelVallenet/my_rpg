/*
** EPITECH PROJECT, 2020
** my_nbr_to_str
** File description:
** transform any number into str
*/

#include <stdlib.h>
#include "my_lib.h"

int my_strlen(char *str);

char *my_revstr(char *str)
{
    int total_letter;
    int i;
    int j;
    int swap;

    total_letter = my_strlen(str) - 1;
    j = total_letter;
    for (i = 0; i <= total_letter / 2; i += 1) {
        swap = str[i];
        str[i] = str[j];
        str[j] = swap;
        j -= 1;
    }
    return (str);
}

char *my_nbr_to_str(int nb)
{
    char *result = malloc(sizeof(char) * 12);
    int i = 0;
    int negative = 0;

    if (nb < 0) {
        negative += 1;
        nb *= -1;
    }
    if (nb == 0) {
        my_strcpy(result, "0\0");
        return (result);
    }
    for (; nb > 0; i += 1) {
        result[i] = (nb % 10) + '0';
        nb = nb / 10;
    }
    for (int j = 0; negative == 1 && j < 1; i += 1, j += 1)
        result[i] = '-';
    result[i] = '\0';
    return (my_revstr(result));
}