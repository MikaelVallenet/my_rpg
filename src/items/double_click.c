/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** double click
*/

#include "rpg.h"

void update_timer(head_t *head, inventory_t *inventory)
{
    if (inventory->time < head->scenes->in_game->time - 0.5) {
        inventory->time = 0;
    }
}

void double_click(head_t *head, inventory_t *inventory, int i)
{
    float time;

    head->scenes->in_game->time = head->scenes->in_game->time_base;
    head->scenes->in_game->time += get_time(head);
    time = head->scenes->in_game->time;
    if (inventory->items[i].id != 1 && inventory->items[i].id != 2)
        return;
    if (inventory->time == 0) {
        inventory->time = time;
        return;
    }
    if (inventory->time > time - 0.5) {
        ITEMS_PTR[inventory->items[i].id_function](i, inventory, head);
    }
}