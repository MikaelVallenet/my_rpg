/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function for menu button
*/

#include "rpg.h"

void open_quest_menu(head_t *head, button_t *button)
{
    init_quest_menu(head);
    head->state_2 = STATE_QUEST_MENU;
    head->scenes->in_game->player->key = (list_key_t){0, 0, 0, 0};
}

void quit_quest_menu(head_t *head, button_t *button)
{
    player_t *player = head->scenes->in_game->player;

    head->technical->state_2_ex = STATE_QUEST_MENU;
    head->state_2 = 0;
    player->key.key_down = UNPRESS;
    player->key.key_up = UNPRESS;
    player->key.key_left = UNPRESS;
    player->key.key_right = UNPRESS;
}