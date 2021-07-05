/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** init_skill_tree_aux
*/

#include "rpg.h"

void init_armor_skill_tree(head_t *head, skill_tree_scenes_t *menu)
{
    create_object(BACK_ARMOR, &menu->object);
    create_button(head, ARMOR_3, &menu->button);
    menu->armor_3 = get_last_button(menu->button);
    create_object(COST_ARMOR_3, &menu->object);
    menu->cost_armor_3 = get_last_object(menu->object);
    create_button(head, ARMOR_2, &menu->button);
    menu->armor_2 = get_last_button(menu->button);
    create_object(COST_ARMOR_2, &menu->object);
    menu->cost_armor_2 = get_last_object(menu->object);
    create_button(head, ARMOR_1, &menu->button);
    menu->armor_1 = get_last_button(menu->button);
    create_object(COST_ARMOR_1, &menu->object);
    menu->cost_armor_1 = get_last_object(menu->object);
    create_text(TEXT_ARMOR, &menu->text);
}

void init_damage_skill_tree(head_t *head, skill_tree_scenes_t *menu)
{
    create_object(BACK_DAMAGE, &menu->object);
    create_button(head, DAMAGE_3, &menu->button);
    menu->damage_3 = get_last_button(menu->button);
    create_object(COST_DAMAGE_3, &menu->object);
    menu->cost_damage_3 = get_last_object(menu->object);
    create_button(head, DAMAGE_2, &menu->button);
    menu->damage_2 = get_last_button(menu->button);
    create_object(COST_DAMAGE_2, &menu->object);
    menu->cost_damage_2 = get_last_object(menu->object);
    create_button(head, DAMAGE_1, &menu->button);
    menu->damage_1 = get_last_button(menu->button);
    create_object(COST_DAMAGE_1, &menu->object);
    menu->cost_damage_1 = get_last_object(menu->object);
    create_text(TEXT_DAMAGE, &menu->text);
}

void init_speed_skill_tree(head_t *head, skill_tree_scenes_t *menu)
{
    create_object(BACK_SPEED, &menu->object);
    create_button(head, SPEED_3, &menu->button);
    menu->speed_3 = get_last_button(menu->button);
    create_object(COST_SPEED_3, &menu->object);
    menu->cost_speed_3 = get_last_object(menu->object);
    create_button(head, SPEED_2, &menu->button);
    menu->speed_2 = get_last_button(menu->button);
    create_object(COST_SPEED_2, &menu->object);
    menu->cost_speed_2 = get_last_object(menu->object);
    create_button(head, SPEED_1, &menu->button);
    menu->speed_1 = get_last_button(menu->button);
    create_object(COST_SPEED_1, &menu->object);
    menu->cost_speed_1 = get_last_object(menu->object);
    create_text(TEXT_SPEED, &menu->text);
}

void init_skill_tree_aux(head_t *head, skill_tree_scenes_t *menu)
{
    init_armor_skill_tree(head, menu);
    init_damage_skill_tree(head, menu);
    init_speed_skill_tree(head, menu);
    init_text_skill_tree(head, menu);
    init_state_button(head, menu);
    set_pos_text_skill_tree(head, menu);
}