/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** handler text
*/

#include "rpg.h"

void animation_text_scrolling(text_scrolling_t *list_text)
{
    while (list_text != NULL) {
        list_text->text_event(list_text);
        list_text = list_text->next;
    }
}

void handler_text_scrolling(text_scrolling_t *text)
{
    if (text->start == 1) {
        text->time = text->time_base;
        text->time += get_time_text_scrolling(text);
        text->display = 1;
        if (text->str[text->i] == '\0') {
            text->start = 2;
            sfSound_stop(text->sound);
        }
        if (text->start == 1 && text->time > text->last_move + text->speed) {
            text->str_display[text->i] = text->str[text->i];
            text->i += 1;
            text->str_display[text->i] = '\0';
            text->last_move = text->time;
            sfText_setString(text->text, text->str_display);
        }
    }
    return;
}

void handler_text_scrolling_off(text_scrolling_t *text)
{
    if (text->start == 1) {
        sfText_setString(text->text, text->str_display);
    }
    return;
}