/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** function_npc
*/

#include "rpg.h"

void give_sword(head_t *head)
{
    add_items(3, head->scenes->in_game->inventory);
    load_quest(head->scenes->in_game, 0);
}