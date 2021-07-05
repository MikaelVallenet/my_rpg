/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** turn_npc
*/

#include "rpg.h"

void turn_npc_up(npc_t *npc)
{
    sfIntRect rect = npc->rect;

    rect.top = rect.height * 2;
    npc->rect = rect;
    npc->orientation = UP;
    sfSprite_setTextureRect(npc->sprite, rect);
}

void turn_npc_down(npc_t *npc)
{
    sfIntRect rect = npc->rect;

    rect.top = 0;
    npc->rect = rect;
    npc->orientation = DOWN;
    sfSprite_setTextureRect(npc->sprite, rect);
}

void turn_npc_left(npc_t *npc)
{
    sfIntRect rect = npc->rect;

    rect.top = rect.height * 3;
    npc->rect = rect;
    npc->orientation = LEFT;
    sfSprite_setTextureRect(npc->sprite, rect);
}

void turn_npc_right(npc_t *npc)
{
    sfIntRect rect = npc->rect;

    rect.top = rect.height;
    npc->rect = rect;
    npc->orientation = RIGHT;
    sfSprite_setTextureRect(npc->sprite, rect);
}