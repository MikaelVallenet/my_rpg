/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** destroy list object
*/

#include "rpg.h"

void destroy_text_scrolling(text_scrolling_t *list_text)
{
    text_scrolling_t *text;

    while (list_text != NULL) {
        free(list_text->str_display);
        free(list_text->str);
        sfText_destroy(list_text->text);
        sfSound_destroy(list_text->sound);
        sfSoundBuffer_destroy(list_text->soundbuffer);
        sfClock_destroy(list_text->clock);
        text = list_text;
        list_text = text->next;
        free(text);
    }
}