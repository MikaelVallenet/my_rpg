/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** turn player
*/

#include "rpg.h"

void turn_player_up(player_t *player)
{
    sfIntRect rect = player->rect;

    rect.top = (rect.height + player->y_offset) * 2;
    player->rect = rect;
    player->state_move = MOVE_UP;
    sfSprite_setTextureRect(player->sprite, rect);
}

void turn_player_down(player_t *player)
{
    sfIntRect rect = player->rect;

    rect.top = 0;
    player->rect = rect;
    player->state_move = MOVE_DOWN;
    sfSprite_setTextureRect(player->sprite, rect);
}

void turn_player_left(player_t *player)
{
    sfIntRect rect = player->rect;

    rect.top = (rect.height + player->y_offset) * 3;
    player->rect = rect;
    player->state_move = MOVE_LEFT;
    sfSprite_setTextureRect(player->sprite, rect);
}

void turn_player_right(player_t *player)
{
    sfIntRect rect = player->rect;

    rect.top = rect.height + player->y_offset;
    player->rect = rect;
    player->state_move = MOVE_RIGHT;
    sfSprite_setTextureRect(player->sprite, rect);
}