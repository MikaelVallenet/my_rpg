/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** destroy list object
*/

#include "rpg.h"

void destroy_text(text_t *object)
{
    text_t *temp;

    while (object != NULL) {
        temp = object->next;
        sfFont_destroy(object->font);
        sfText_destroy(object->text);
        free(object);
        object = temp;
    }
}