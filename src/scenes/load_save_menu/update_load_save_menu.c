/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** update_load_save_menu
*/

#include "rpg.h"

void update_load_save_menu(head_t *head)
{
    destroy_text(head->scenes->load_save_menu->text);
    head->scenes->load_save_menu->text = malloc(sizeof(text_t));
    head->scenes->load_save_menu->text = NULL;
    init_text_load_save_menu(head, head->scenes->load_save_menu);
}