/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function for menu button
*/

#include "rpg.h"

void launch_game_function(head_t *head, button_t *button)
{
    start_fade_animation(head, NULL, STATE_LOAD_SAVE_MENU);
}