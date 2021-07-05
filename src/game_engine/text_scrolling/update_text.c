/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** update text
*/

#include "rpg.h"

void update_text_scrolling(text_scrolling_t *text, char *new_str)
{
    if (text->speed == 1)
        sfText_setString(text->text, new_str);
    return;
}