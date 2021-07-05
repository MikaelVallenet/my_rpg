/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** open_pause
*/

#include "rpg.h"

void open_pause_menu(head_t *head, button_t *button)
{
    head->scenes->in_game->time = head->scenes->in_game->time_base;
    head->scenes->in_game->time += get_time(head);
    head->scenes->in_game->time_pause = head->scenes->in_game->time;
    init_pause_menu(head);
    head->state_2 = STATE_PAUSE_MENU;
    head->scenes->in_game->player->key.key_up = UNPRESS;
    head->scenes->in_game->player->key.key_down = UNPRESS;
    head->scenes->in_game->player->key.key_left = UNPRESS;
    head->scenes->in_game->player->key.key_right = UNPRESS;
}