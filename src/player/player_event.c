/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** manage event for player
*/

#include "rpg.h"

void manage_key_press_player(player_t *player, sfEvent event, head_t *head)
{
    if (event.key.code == sfKeyUp)
        player->key.key_up = PRESS;
    if (event.key.code == sfKeyDown)
        player->key.key_down = PRESS;
    if (event.key.code == sfKeyLeft)
        player->key.key_left = PRESS;
    if (event.key.code == sfKeyRight)
        player->key.key_right = PRESS;
}

void manage_key_unpress_player(player_t *player, sfEvent event, head_t *head)
{
    if (event.key.code == sfKeyUp)
        player->key.key_up = UNPRESS;
    if (event.key.code == sfKeyDown)
        player->key.key_down = UNPRESS;
    if (event.key.code == sfKeyLeft)
        player->key.key_left = UNPRESS;
    if (event.key.code == sfKeyRight)
        player->key.key_right = UNPRESS;
}