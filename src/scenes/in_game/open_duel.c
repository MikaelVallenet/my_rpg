/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** duel
*/

#include "rpg.h"

void open_duel_menu(head_t *head, char *filepath)
{
    head->scenes->in_game->player->last_move = 0;
    init_duel_scene(head, filepath);
    head->state_2 = STATE_DUEL;
    head->scenes->in_game->player->key.key_up = UNPRESS;
    head->scenes->in_game->player->key.key_down = UNPRESS;
    head->scenes->in_game->player->key.key_left = UNPRESS;
    head->scenes->in_game->player->key.key_right = UNPRESS;
}