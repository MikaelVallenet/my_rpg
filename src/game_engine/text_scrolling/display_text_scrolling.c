/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** display text
*/

#include "rpg.h"

void display_text_scrolling(head_t *head, text_scrolling_t *list_text)
{
    while (list_text != NULL) {
        if (list_text->display == 1) {
            update_text_scrolling(list_text, list_text->str_display);
            sfRenderWindow_drawText(head->window, list_text->text, NULL);
        }
        list_text = list_text->next;
    }
}

void display_on_text_scrolling(char *title, text_scrolling_t *text)
{
    text_scrolling_t *my_text = find_text(title, text);

    if (my_text->display == 0) {
        my_text->display = 1;
    }
}

void display_off_text_scrolling(char *title, text_scrolling_t *text)
{
    text_scrolling_t *my_text = find_text(title, text);

    if (my_text->display == 1) {
        my_text->display = 0;
    }
}