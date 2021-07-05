/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** display_conversation
*/

#include "rpg.h"

void display_conversation(head_t *head, player_t *player)
{
    if (player->is_in_conversation == 1) {
        sfRenderWindow_drawSprite(head->window,
        head->scenes->in_game->bubble->sprite, NULL);
        sfRenderWindow_drawSprite(head->window,
        head->scenes->in_game->face->sprite, NULL);
    }
}