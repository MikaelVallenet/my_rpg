/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** hover button
*/

#include "rpg.h"

void is_hover_button(button_t *button, sfVector2f clic)
{
    while (button != NULL) {
        if (is_in_button(button, clic)) {
            sfSprite_setColor(button->sprite, sfYellow);
            sfText_setFillColor(button->hover_text, sfWhite);
        }
        else {
            sfSprite_setColor(button->sprite, sfWhite);
            sfText_setFillColor(button->hover_text, sfTransparent);
        }
        button = button->next;
    }
}

void is_clic_button(head_t *head, button_t *button, sfVector2f clic)
{
    while (button != NULL) {
        if (is_in_button(button, clic)) {
            sfSound_play(head->res->sfx->click_sound);
            button->call_func(head, button);
            animation_button_clic(button);
        }
        button = button->next;
    }
}