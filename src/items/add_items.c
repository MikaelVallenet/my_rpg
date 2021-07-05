/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** add items
*/

#include "rpg.h"

void add_items(int id, inventory_t *inventory)
{
    for (int i = 0; i < 27; i += 1) {
        if (id != 1 && id != 2)
            break;
        if (inventory->items[i].id == id) {
            inventory->items[i].nbr += 1;
            return;
        }
    }
    for (int i = 0; i < 27; i += 1) {
        if (inventory->items[i].id == 0) {
            inventory->items[i] = load_items(id);
            break;
        }
    }
}