/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create text
*/

#include "rpg.h"

float get_time_text_scrolling(text_scrolling_t* text)
{
    return (sfClock_getElapsedTime(text->clock).microseconds / 1000000.0);
}

text_scrolling_t *find_text(char *title, text_scrolling_t *text)
{
    while (text != NULL && my_strcmp(title, text->title) != 0) {
        text = text->next;
    }
    return (text);
}

void start_text_scrolling(char *title, text_scrolling_t *text)
{
    text_scrolling_t *my_text = find_text(title, text);

    if (my_text->start == 0) {
        my_text->start = 1;
        if (my_text->speed != 1)
            sfSound_play(my_text->sound);
    }
}

void stop_text_scrolling(char *title, text_scrolling_t *text)
{
    text_scrolling_t *my_text = find_text(title, text);

    if (my_text->start == 1) {
        my_text->start = 0;
        if (my_text->speed != 1)
            sfSound_stop(my_text->sound);
    }
}

void reset_text_scrolling(char *title, text_scrolling_t *text, char *new_str)
{
    text_scrolling_t *my_text = find_text(title, text);

    if (new_str != NULL) {
        free(my_text->str);
        my_text->str = malloc(sizeof(char) * (my_strlen(new_str) + 1));
        my_text->str_display = malloc(sizeof(char) * (my_strlen(new_str) + 1));
        my_strcpy(my_text->str, new_str);
    }
    my_text->str_display[0] = '\0';
    my_text->i = 0;
    my_text->start = 1;
    my_text->time = 0;
    my_text->time_base = 0;
    my_text->last_move = 0;
    sfSound_play(my_text->sound);
}