/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** buttons_manager
*/

#include "rpg.h"

void destroy_button(button_t *button)
{
    button_t *temp;

    while (button != NULL) {
        temp = button->next;
        sfTexture_destroy(button->texture);
        sfSprite_destroy(button->sprite);
        sfText_destroy(button->text);
        sfText_destroy(button->hover_text);
        sfClock_destroy(button->clock);
        free(button);
        button = temp;
    }
}