/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** animation button
*/

#include "rpg.h"

void display_button(head_t *head, button_t *first)
{
    while (first != NULL) {
        sfRenderWindow_drawSprite(head->window, first->sprite, NULL);
        sfRenderWindow_drawText(head->window, first->text, NULL);
        sfRenderWindow_drawText(head->window, first->hover_text, NULL);
        first = first->next;
    }
}

void animation_button_clic(button_t *but)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(but->sprite);
    sfVector2f size = (sfVector2f){bounds.width, bounds.height};
    sfVector2f pos = sfSprite_getPosition(but->sprite);
    sfVector2f offset_scale = {0.9, 0.9};
    sfVector2f scale_origin = sfSprite_getScale(but->sprite);
    sfVector2f new_scale;
    sfVector2f new_size;
    sfVector2f new_pos;

    new_scale.x = scale_origin.x * offset_scale.x;
    new_scale.y = scale_origin.y * offset_scale.y;
    new_size.x = size.x * offset_scale.x;
    new_size.y = size.y * offset_scale.y;
    new_pos.x = pos.x + ((size.x - new_size.x) / 2);
    new_pos.y = pos.y + ((size.y - new_size.y) / 2);
    sfSprite_setColor(but->sprite, (sfColor){85, 73, 90, 200});
    sfSprite_setScale(but->sprite, new_scale);
    sfSprite_setPosition(but->sprite, new_pos);
}

void animation_button_none(button_t *but)
{
    sfVector2f scale_2;

    while (but != NULL) {
        scale_2 = but->scale_original;
        if (sfSprite_getPosition(but->sprite).x != but->pos_original.x) {
            sfSprite_setScale(but->sprite, scale_2);
            sfSprite_setPosition(but->sprite, but->pos_original);
        }
        but = but->next;
    }
}