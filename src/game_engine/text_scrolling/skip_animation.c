/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** skip_animation
*/

#include "rpg.h"

void skip_animation_text_scrolling(char *name, text_scrolling_t *list)
{
    text_scrolling_t *current = find_text(name, list);
    int len = my_strlen(current->str) + 1;

    current->start = 2;
    for (int i = 0; i < len; i++) {
        current->str_display[i] = current->str[i];
    }
    sfText_setString(current->text, current->str_display);
    sfSound_stop(current->sound);
}