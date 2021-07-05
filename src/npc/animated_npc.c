/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** animated_player
*/

#include "rpg.h"

void animate_npc(npc_t *npc)
{
    sfIntRect rect = npc->rect;

    rect.left = rect.left + rect.width;
    if (rect.left >= npc->size_texture.x) {
        rect.left = 0;
    }
    npc->rect = rect;
    sfSprite_setTextureRect(npc->sprite, rect);
}

void manage_animated_npc(npc_t *npc, head_t *head)
{
    if (head->scenes->in_game->time > npc->last_move + (1.0/9.0)) {
        npc->last_move = head->scenes->in_game->time;
        animate_npc(npc);
    }
}