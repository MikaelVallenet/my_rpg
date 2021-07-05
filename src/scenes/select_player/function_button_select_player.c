/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function_button_in_game
*/

#include "rpg.h"

void quit_select_player(head_t *head, button_t *button)
{
    start_fade_animation(head, NULL, STATE_LOAD_SAVE_MENU);
}

void launch_game(head_t *head, button_t *button)
{
    pars_data_t *obj;

    if (button == head->scenes->select_player->alex_button) {
        obj = init_player_data_json("Alex");
        writer_json(get_path_save(head), NULL, obj);
    }
    if (button == head->scenes->select_player->elliot_button) {
        obj = init_player_data_json("Elliot");
        writer_json(get_path_save(head), NULL, obj);
    }
    if (button == head->scenes->select_player->haley_button) {
        obj = init_player_data_json("Haley");
        writer_json(get_path_save(head), NULL, obj);
    }
    if (button == head->scenes->select_player->maru_button) {
        obj = init_player_data_json("Maru");
        writer_json(get_path_save(head), NULL, obj);
    }
    start_fade_animation(head, NULL, STATE_INGAME);
}