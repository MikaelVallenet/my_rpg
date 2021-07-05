/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** display items
*/

#include "rpg.h"

void display_item_w_inv(head_t *head, inventory_t *inventory,
sfVector2f position, sfVector2f scale)
{
    position = sfSprite_getPosition(
    inventory->items[inventory->item_window->id].sprite);
    sfRenderWindow_drawSprite(head->window,
    inventory->item_window->sprite, NULL);
    sfSprite_setPosition(
    inventory->items[inventory->item_window->id].sprite,
    inventory->item_window->p_sprite);
    scale = sfSprite_getScale(
    inventory->items[inventory->item_window->id].sprite);
    sfSprite_setScale(inventory->items[inventory->item_window->id].sprite,
    (sfVector2f){1.15, 1.15});
    sfRenderWindow_drawSprite(head->window,
    inventory->items[inventory->item_window->id].sprite, NULL);
    sfSprite_setScale(inventory->items[inventory->item_window->id].sprite,
    scale);
    sfSprite_setPosition(
    inventory->items[inventory->item_window->id].sprite, position);
}

void display_item_w_slots(head_t *head, inventory_t *inventory,
sfVector2f position, sfVector2f scale)
{
    position = sfSprite_getPosition(
    inventory->slots[inventory->item_window->id].sprite);
    sfRenderWindow_drawSprite(head->window,
    inventory->item_window->sprite, NULL);
    sfSprite_setPosition(
    inventory->slots[inventory->item_window->id].sprite,
    inventory->item_window->p_sprite);
    scale = sfSprite_getScale(
    inventory->slots[inventory->item_window->id].sprite);
    sfSprite_setScale(inventory->slots[inventory->item_window->id].sprite,
    (sfVector2f){1.15, 1.15});
    sfRenderWindow_drawSprite(head->window,
    inventory->slots[inventory->item_window->id].sprite, NULL);
    sfSprite_setScale(inventory->slots[inventory->item_window->id].sprite,
    scale);
    sfSprite_setPosition(
    inventory->slots[inventory->item_window->id].sprite, position);
}

void display_item_window(head_t *head, inventory_t *inventory)
{
    sfVector2f scale = (sfVector2f){0, 0};
    sfVector2f position = (sfVector2f){0, 0};

    if (inventory->open == 1 && inventory->item_window->open == 1) {
        if (inventory->item_window->id <= 26)
            display_item_w_inv(head, inventory, position, scale);
        if (inventory->item_window->id > 26) {
            inventory->item_window->id -= 27;
            display_item_w_slots(head, inventory, position, scale);
            inventory->item_window->id += 27;
        }
    }
}

void display_items_inventory(head_t *head, inventory_t *inventory)
{
    if (inventory->open == 0)
        return;
    for (int i = 0; i < 27; i += 1) {
        if (inventory->items[i].id != 0 && i != inventory->mouse.id) {
            sfRenderWindow_drawSprite(head->window,
            inventory->items[i].sprite, NULL);
        }
    }
    for (int i = 0; i < 5; i += 1) {
        if (inventory->slots[i].id != 0 && i + 27 != inventory->mouse.id) {
            sfRenderWindow_drawSprite(head->window,
            inventory->slots[i].sprite, NULL);
        }
    }
    if (inventory->mouse.mouse == PRESS) {
        sfRenderWindow_drawSprite(head->window,
        inventory->items[inventory->mouse.id].sprite, NULL);
    }
}
