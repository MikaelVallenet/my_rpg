/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** manage sound
*/

#include "rpg.h"

void update_bar_sound(head_t *head, object_t *object)
{
    sfVector2u size_texture = sfTexture_getSize(object->texture);
    sfIntRect rect;

    rect.height = size_texture.y * object->scale.y;
    rect.width = (int)sfSound_getVolume(head->res->sfx->click_sound)
    * size_texture.x / 100;
    rect.top = 0;
    rect.left = 0;
    sfSprite_setTextureRect(object->sprite, rect);
}

void update_button_on_off_sound(head_t *head, button_t *object)
{
    if (sfSound_getVolume(head->res->sfx->click_sound) > 0) {
        sfTexture_destroy(object->texture);
        object->texture =
        sfTexture_createFromFile("assets/buttons/button_on.png", NULL);
        sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    }
    else {
        sfTexture_destroy(object->texture);
        object->texture =
        sfTexture_createFromFile("assets/buttons/button_off.png", NULL);
        sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    }
}