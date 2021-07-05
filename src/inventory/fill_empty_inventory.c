/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** file_empty_inventory
*/

#include "rpg.h"

void fill_empty_inventory(inventory_t *inventory)
{
    for (int i = 0; i < 27; i += 1) {
        inventory->items[i].id = 0;
        inventory->items[i].nbr = 0;
    }
    for (int i = 0; i < 5; i += 1) {
        inventory->slots[i].id = 0;
        inventory->slots[i].nbr = 0;
    }
}