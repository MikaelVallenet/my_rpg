/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** function that concatenates two strings
*/

#include <stdlib.h>

int my_strlen(char const *src);

char *my_strcat_original(char *dest, char *src)
{
    int i;

    for (i = 0; dest[i] != '\0'; i += 1);
    for (int j = 0; src[j] != '\0'; i += 1, j += 1)
        dest[i] = src[j];
    dest[i] = '\0';
    return (dest);
}

char *my_strncat(char *src1, char *to_add, int index)
{
    char *buffer = malloc(sizeof(char) * (my_strlen(src1) +
    my_strlen(to_add) + 2));
    int i;
    int k;

    if (index >= my_strlen(src1))
        return (NULL);
    for (i = 0; i < index || (src1[i] != ' ' && src1[i] != '\0'); i += 1)
        buffer[i] = src1[i];
    k = i;
    for (int j = 0; to_add[j] != '\0'; i += 1, j += 1)
        buffer[i] = to_add[j];
    for (;src1[k] != '\0'; k += 1, i += 1)
        buffer[i] = src1[k];
    buffer[i] = '\0';
    free(src1);
    return (buffer);
}

char *my_strcat(char const *src1, char const *src2)
{
    int len = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(src1) + my_strlen(src2) + 1));

    for (int i = 0; src1[i]; i += 1)
        dest[len++] = src1[i];
    for (int i = 0; src2[i]; i += 1)
        dest[len++] = src2[i];
    dest[len] = '\0';
    return (dest);
}