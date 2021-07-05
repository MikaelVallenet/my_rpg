/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** init_state_button_skill_tree
*/

#include "rpg.h"

void set_state_armor_button(head_t *head, skill_tree_scenes_t *menu)
{
    sfColor color = {25, 25, 25, 200};
    sfColor color2 = {57, 255, 20, 255};

    if (head->scenes->in_game->player->skill_tree.armor_1 == 0) {
        sfSprite_setColor(menu->armor_2->sprite, color);
        sfSprite_setColor(menu->armor_3->sprite, color);
        return;
    }
    if (head->scenes->in_game->player->skill_tree.armor_2 == 0) {
        sfSprite_setColor(menu->armor_1->sprite, color2);
        sfSprite_setColor(menu->armor_3->sprite, color);
        return;
    }
    if (head->scenes->in_game->player->skill_tree.armor_3 == 0) {
        sfSprite_setColor(menu->armor_1->sprite, color2);
        sfSprite_setColor(menu->armor_2->sprite, color2);
        return;
    }
    sfSprite_setColor(menu->armor_1->sprite, color2);
    sfSprite_setColor(menu->armor_2->sprite, color2);
    sfSprite_setColor(menu->armor_3->sprite, color2);
}

void set_state_damage_button(head_t *head, skill_tree_scenes_t *menu)
{
    sfColor color = {25, 25, 25, 200};
    sfColor color2 = {57, 255, 20, 255};

    if (head->scenes->in_game->player->skill_tree.damage_1 == 0) {
        sfSprite_setColor(menu->damage_2->sprite, color);
        sfSprite_setColor(menu->damage_3->sprite, color);
        return;
    }
    if (head->scenes->in_game->player->skill_tree.damage_2 == 0) {
        sfSprite_setColor(menu->damage_1->sprite, color2);
        sfSprite_setColor(menu->damage_3->sprite, color);
        return;
    }
    if (head->scenes->in_game->player->skill_tree.damage_3 == 0) {
        sfSprite_setColor(menu->damage_1->sprite, color2);
        sfSprite_setColor(menu->damage_2->sprite, color2);
        return;
    }
    sfSprite_setColor(menu->damage_1->sprite, color2);
    sfSprite_setColor(menu->damage_2->sprite, color2);
    sfSprite_setColor(menu->damage_3->sprite, color2);
}

void set_state_speed_button(head_t *head, skill_tree_scenes_t *menu)
{
    sfColor color = {25, 25, 25, 200};
    sfColor color2 = {57, 255, 20, 255};

    if (head->scenes->in_game->player->skill_tree.speed_1 == 0) {
        sfSprite_setColor(menu->speed_2->sprite, color);
        sfSprite_setColor(menu->speed_3->sprite, color);
        return;
    }
    if (head->scenes->in_game->player->skill_tree.speed_2 == 0) {
        sfSprite_setColor(menu->speed_1->sprite, color2);
        sfSprite_setColor(menu->speed_3->sprite, color);
        return;
    }
    if (head->scenes->in_game->player->skill_tree.speed_3 == 0) {
        sfSprite_setColor(menu->speed_1->sprite, color2);
        sfSprite_setColor(menu->speed_2->sprite, color2);
        return;
    }
    sfSprite_setColor(menu->speed_1->sprite, color2);
    sfSprite_setColor(menu->speed_2->sprite, color2);
    sfSprite_setColor(menu->speed_3->sprite, color2);
}

void init_state_button(head_t *head, skill_tree_scenes_t *menu)
{
    set_state_speed_button(head, menu);
    set_state_armor_button(head, menu);
    set_state_damage_button(head, menu);
}