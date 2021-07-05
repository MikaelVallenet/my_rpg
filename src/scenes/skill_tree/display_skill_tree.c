/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** display_skill_tree
*/

#include "rpg.h"

void display_cost_star(head_t *head)
{
    sfRenderWindow_drawSprite(head->window,
    head->scenes->skill_tree->cost_armor_1->sprite, NULL);
    sfRenderWindow_drawSprite(head->window,
    head->scenes->skill_tree->cost_armor_2->sprite, NULL);
    sfRenderWindow_drawSprite(head->window,
    head->scenes->skill_tree->cost_armor_3->sprite, NULL);
    sfRenderWindow_drawSprite(head->window,
    head->scenes->skill_tree->cost_speed_1->sprite, NULL);
    sfRenderWindow_drawSprite(head->window,
    head->scenes->skill_tree->cost_speed_2->sprite, NULL);
    sfRenderWindow_drawSprite(head->window,
    head->scenes->skill_tree->cost_speed_3->sprite, NULL);
    sfRenderWindow_drawSprite(head->window,
    head->scenes->skill_tree->cost_damage_1->sprite, NULL);
    sfRenderWindow_drawSprite(head->window,
    head->scenes->skill_tree->cost_damage_2->sprite, NULL);
    sfRenderWindow_drawSprite(head->window,
    head->scenes->skill_tree->cost_damage_3->sprite, NULL);
}