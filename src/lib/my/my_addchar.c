/*
** EPITECH PROJECT, 2020
** MyLib
** File description:
** my_addchar
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_addchar(char *str, char c, int position)
{
    char *result = malloc(sizeof(char) * (my_strlen(str) + 2));
    int i = 0;

    if (position) {
        result[0] = c;
        for (; str[i] != '\0'; i++)
            result[i + 1] = str[i];
    } else {
        result[my_strlen(str)] = c;
        for (; str[i] != '\0'; i++)
            result[i] = str[i];
        i += 1;
    }
    result[i + 1] = '\0';
    return (result);
}
