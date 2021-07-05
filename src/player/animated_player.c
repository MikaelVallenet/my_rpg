/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** animated_player
*/

#include "rpg.h"

void animate_player(player_t *player)
{
    sfIntRect rect = player->rect;

    rect.left = rect.left + rect.width + player->x_offset;
    if (rect.left >= player->size_texture.x) {
        rect.left = 0;
    }
    player->rect = rect;
    sfSprite_setTextureRect(player->sprite, rect);
}