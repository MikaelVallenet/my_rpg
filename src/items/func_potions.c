/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** func potions
*/

#include "rpg.h"

void health_potion(int i, inventory_t *inventory, head_t *head)
{
    if (head->scenes->in_game->player->p_stat.health_max -
    head->scenes->in_game->player->p_stat.health == 0)
        return;
    if (head->scenes->in_game->player->p_stat.health_max -
    head->scenes->in_game->player->p_stat.health <= 50) {
        head->scenes->in_game->player->p_stat.health =
        head->scenes->in_game->player->p_stat.health_max;
    } else {
        head->scenes->in_game->player->p_stat.health += 50;
    }
    inventory->items[i].nbr -= 1;
}

void experience_potion(int i, inventory_t *inventory, head_t *head)
{
    head->scenes->in_game->player->p_stat.xp += 75;
    lvl_up(head->scenes->in_game->player);
    inventory->items[i].nbr -= 1;
}