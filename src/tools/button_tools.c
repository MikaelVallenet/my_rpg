/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** animation button
*/

#include "rpg.h"

static sfBool is_in_button_aux(sfVector2f pos, sfVector2f clic, sfVector2f siz)
{
    if (clic.x <= pos.x + siz.x && clic.x >= pos.x)
        if (clic.y <= pos.y + siz.y && clic.y >= pos.y)
            return (sfTrue);
    return (sfFalse);
}

sfBool is_in_button(button_t *button, sfVector2f clic)
{
    sfVector2f pos = sfSprite_getPosition(button->sprite);
    sfFloatRect bounds = sfSprite_getGlobalBounds(button->sprite);
    sfVector2f size = (sfVector2f){bounds.width, bounds.height};
    float x = (clic.x - (pos.x + (size.x / 2)));
    float y = (clic.y - (pos.y + (size.y / 2)));

    if (button->type == SQUARE) {
        if (is_in_button_aux(pos, clic, size) == sfTrue)
            return sfTrue;
    }
    else if (button->type == CIRCLE) {
        if ((x * x) + (y * y) <= (size.x / 2) * (size.y / 2))
            return sfTrue;
    }
    return sfFalse;
}