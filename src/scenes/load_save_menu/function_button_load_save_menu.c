/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function for pause button
*/

#include "rpg.h"

void launch_save(head_t *head, button_t *button)
{
    char *path_save_file;

    if (button == head->scenes->load_save_menu->first_save_button) {
        path_save_file = "saves/save_1.json";
        head->technical->index_save = 1;
    }
    else if (button == head->scenes->load_save_menu->second_save_button) {
        path_save_file = "saves/save_2.json";
        head->technical->index_save = 2;
    }
    else {
        path_save_file = "saves/save_3.json";
        head->technical->index_save = 3;
    }
    load_save(head, path_save_file);
}

void delete_save_button(head_t *head, button_t *button)
{
    char *path_save_file;

    if (button == head->scenes->load_save_menu->delete_first_save)
        path_save_file = "saves/save_1.json";
    if (button == head->scenes->load_save_menu->delete_second_save)
        path_save_file = "saves/save_2.json";
    if (button == head->scenes->load_save_menu->delete_third_save)
        path_save_file = "saves/save_3.json";
    delete_save(path_save_file);
    update_load_save_menu(head);
}