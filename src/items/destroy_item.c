/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** delete items
*/

#include "rpg.h"

void destroy_stacked_item(head_t *head, inventory_t *inventory)
{
    for (int i = 0; i < 27; i += 1) {
        if (inventory->items[i].id != 0 && inventory->items[i].nbr < 1) {
            destroy_items(i, inventory, head->scenes);
            inventory->items[i].id = 0;
            inventory->mouse.id = -1;
            inventory->mouse.mouse = UNPRESS;
        }
    }
}

void destroy_item_window(inventory_t *inventory)
{
    sfSprite_destroy(inventory->item_window->sprite);
    sfTexture_destroy(inventory->item_window->texture);
    free(inventory->item_window);
}

void destroy_slots_inv(int i, inventory_t *inventory, scenes_t *scenes)
{
    free(inventory->slots[i].name);
    free(inventory->slots[i].description);
    sfSprite_destroy(inventory->slots[i].sprite);
    sfTexture_destroy(inventory->slots[i].texture);
}

void destroy_items(int i, inventory_t *inventory, scenes_t *scenes)
{
    if (i > 26) {
        scenes->in_game->player->p_stat.damage -= inventory->items[i].damage;
        scenes->in_game->player->p_stat.armor -= inventory->items[i].armor;
    }
    free(inventory->items[i].name);
    free(inventory->items[i].description);
    sfSprite_destroy(inventory->items[i].sprite);
    sfTexture_destroy(inventory->items[i].texture);
    if (inventory->item_window->id == i) {
        display_off_item_text(scenes);
    }
}