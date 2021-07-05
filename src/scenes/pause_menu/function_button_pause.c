/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function for pause button
*/

#include "rpg.h"

void quit_setting_to_pause_2(head_t *head)
{
    head->state_2 = STATE_PAUSE_MENU;
    destroy_setting_menu(head->scenes);
    init_pause_menu(head);
}

void quit_setting_to_pause(head_t *head, button_t *button)
{
    start_fade_animation(head, quit_setting_to_pause_2, head->state);
}

void open_setting_pause_2(head_t *head)
{
    head->state_2 = STATE_SETTING_MENU;
    destroy_pause_menu(head->scenes);
    init_setting_menu(head);
    head->scenes->setting_menu->quit_setting->call_func =
    &quit_setting_to_pause;
}

void open_setting_pause(head_t *head, button_t *button)
{
    start_fade_animation(head, open_setting_pause_2, head->state);
}

void return_to_menu(head_t *head, button_t *button)
{
    head->technical->state_2_ex = STATE_PAUSE_MENU;
    head->state_2 = 0;
    start_fade_animation(head, NULL, STATE_MENU);
}