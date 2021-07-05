/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** check_button_enable
*/

#include "rpg.h"

static sfBool is_in_armor_button(head_t *head, button_t *button)
{
    skill_tree_scenes_t *menu = head->scenes->skill_tree;
    in_game_t *menu_2 = head->scenes->in_game;

    if (menu->armor_1 == button)
        if (menu_2->player->skill_tree.armor_1 == 0)
            return (sfTrue);
    if (menu->armor_2 == button) {
        if (menu_2->player->skill_tree.armor_2 == 1)
            return (sfFalse);
        if (menu_2->player->skill_tree.armor_1 == 1)
            return (sfTrue);
    }
    if (menu->armor_3 == button) {
        if (menu_2->player->skill_tree.armor_3 == 1)
            return (sfFalse);
        if (menu_2->player->skill_tree.armor_2 == 1)
            return (sfTrue);
    }
    return (sfFalse);
}

static sfBool is_in_damage_button(head_t *head, button_t *button)
{
    skill_tree_scenes_t *menu = head->scenes->skill_tree;
    in_game_t *menu_2 = head->scenes->in_game;

    if (menu->damage_1 == button)
        if (menu_2->player->skill_tree.damage_1 == 0)
            return (sfTrue);
    if (menu->damage_2 == button) {
        if (menu_2->player->skill_tree.damage_2 == 1)
            return (sfFalse);
        if (menu_2->player->skill_tree.damage_1 == 1)
            return (sfTrue);
    }
    if (menu->damage_3 == button) {
        if (menu_2->player->skill_tree.damage_3 == 1)
            return (sfFalse);
        if (menu_2->player->skill_tree.damage_2 == 1)
            return (sfTrue);
    }
    return (sfFalse);
}

static sfBool is_in_speed_button(head_t *head, button_t *button)
{
    skill_tree_scenes_t *menu = head->scenes->skill_tree;
    in_game_t *menu_2 = head->scenes->in_game;

    if (menu->speed_1 == button)
        if (menu_2->player->skill_tree.speed_1 == 0)
            return (sfTrue);
    if (menu->speed_2 == button) {
        if (menu_2->player->skill_tree.speed_2 == 1)
            return (sfFalse);
        if (menu_2->player->skill_tree.speed_1 == 1)
            return (sfTrue);
    }
    if (menu->speed_3 == button) {
        if (menu_2->player->skill_tree.speed_3 == 1)
            return (sfFalse);
        if (menu_2->player->skill_tree.speed_2 == 1)
            return (sfTrue);
    }
    return (sfFalse);
}

sfBool is_button_skill(head_t *head, button_t *button)
{
    skill_tree_scenes_t *menu = head->scenes->skill_tree;

    if (menu->speed_1 == button)
        return (sfTrue);
    if (menu->speed_2 == button)
        return (sfTrue);
    if (menu->speed_3 == button)
        return (sfTrue);
    if (menu->armor_1 == button)
        return (sfTrue);
    if (menu->armor_2 == button)
        return (sfTrue);
    if (menu->armor_3 == button)
        return (sfTrue);
    if (menu->damage_1 == button)
        return (sfTrue);
    if (menu->damage_2 == button)
        return (sfTrue);
    if (menu->damage_3 == button)
        return (sfTrue);
    return (sfFalse);
}

sfBool is_button_activate(head_t *head, button_t *button)
{
    if (is_button_skill(head, button) == sfFalse)
        return (sfTrue);
    if (is_in_armor_button(head, button) == sfTrue)
        return (sfTrue);
    if (is_in_damage_button(head, button) == sfTrue)
        return (sfTrue);
    if (is_in_speed_button(head, button) == sfTrue)
        return (sfTrue);
    return (sfFalse);
}