/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** methods text for all
*/

#include "rpg.h"

void start_text_all_scrolling(text_scrolling_t *text)
{
    while (text != NULL) {
        if (text->start == 0) {
            text->start = 1;
            sfSound_play(text->sound);
        }
        text = text->next;
    }
}

void stop_text_all_scrolling(text_scrolling_t *text)
{
    while (text != NULL) {
        if (text->start == 1) {
            text->start = 0;
            sfSound_stop(text->sound);
        }
        text = text->next;
    }
}

void reset_text_all_scrolling(text_scrolling_t *text)
{
    while (text != NULL) {
        text->str_display[0] = '\0';
        text->i = 0;
        text->start = 0;
        text->time = 0;
        text->time_base = 0;
        text->last_move = 0;
        sfSound_stop(text->sound);
        text = text->next;
    }
}