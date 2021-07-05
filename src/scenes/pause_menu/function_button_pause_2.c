/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function for button
*/

#include "rpg.h"

void resume_game(head_t *head, button_t *button)
{
    float time_base = head->scenes->in_game->time_base;

    time_base += get_time(head);
    if (head->state_2 == STATE_PAUSE_MENU)
        head->technical->state_2_ex = STATE_PAUSE_MENU;
    if (head->state_2 == STATE_SETTING_MENU)
        head->technical->state_2_ex = STATE_SETTING_MENU;
    head->state_2 = 0;
    head->scenes->in_game->time_base -=
    time_base - head->scenes->in_game->time_pause;
    head->scenes->in_game->time_pause = 0.0;
}

void button_save_game(head_t *head, button_t *button)
{
    save_stat_player(head);
}