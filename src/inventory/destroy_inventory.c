/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** destroy inventory
*/

#include "rpg.h"

void destroy_inventory(inventory_t *inventory, scenes_t *scenes)
{
    sfSprite_destroy(inventory->sprite);
    sfTexture_destroy(inventory->texture);
    destroy_one_object(inventory->healh_bg_bar);
    destroy_one_object(inventory->health_bar);
    destroy_one_object(inventory->experience_bar);
    destroy_one_object(inventory->experience_bg_bar);
    for (int i = 0; i < 32; i += 1) {
        if (inventory->items[i].id != 0) {
            destroy_items(i, inventory, scenes);
        }
    }
    destroy_item_window(inventory);
    free(inventory);
}