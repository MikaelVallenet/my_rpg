/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function for pause button
*/

#include "rpg.h"

void clic_skill_button(head_t *head, button_t *button)
{
    skill_tree_scenes_t *menu = head->scenes->skill_tree;

    if (button == menu->speed_1 || button == menu->speed_2 ||
    button == menu->speed_3) {
        manage_clic_speed(head, button);
    }
    if (button == menu->damage_1 || button == menu->damage_2 ||
    button == menu->damage_3) {
        manage_clic_damage(head, button);
    }
    if (button == menu->armor_1 || button == menu->armor_2 ||
    button == menu->armor_3) {
        manage_clic_armor(head, button);
    }
}

void quit_skill_tree(head_t *head, button_t * button)
{
    head->technical->state_2_ex = STATE_SKILL_TREE;
    head->state_2 = 0;
}