/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** open_skill_tree
*/

#include "rpg.h"

void open_skill_tree(head_t *head)
{
    head->scenes->in_game->player->last_move = 0;
    init_skill_tree(head);
    head->state_2 = STATE_SKILL_TREE;
    head->scenes->in_game->player->key.key_up = UNPRESS;
    head->scenes->in_game->player->key.key_down = UNPRESS;
    head->scenes->in_game->player->key.key_left = UNPRESS;
    head->scenes->in_game->player->key.key_right = UNPRESS;
}