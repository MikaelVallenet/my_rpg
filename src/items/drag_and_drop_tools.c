/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** drag and drop tools
*/

#include "rpg.h"

int drag_and_drop_on_inv(head_t *head, inventory_t *inventory,
sfVector2f position)
{
    for (int i = 0; i < 27; i += 1) {
        if (inventory->items[i].id == 0)
            continue;
        if (position.y > inventory->list_position[i].y &&
        position.y < inventory->list_position[i].y + 72.5 &&
        position.x > inventory->list_position[i].x &&
        position.x < inventory->list_position[i].x + 72.5) {
            inventory->mouse.mouse = PRESS;
            inventory->mouse.id = i;
            inventory->mouse.position = inventory->list_position[i];
            display_on_item_text(head);
            inventory->item_window->id = i;
            double_click(head, inventory, i);
            return (0);
        }
    }
    return (1);
}

int drag_and_drop_on_slots(head_t *head, inventory_t *inventory,
sfVector2f position)
{
    for (int i = 0; i < 5; i += 1) {
        if (inventory->slots[i].id == 0)
            continue;
        if (position.y > inventory->slots_position[i].y &&
        position.y < inventory->slots_position[i].y + 50 &&
        position.x > inventory->slots_position[i].x &&
        position.x < inventory->slots_position[i].x + 50) {
            inventory->mouse.mouse = PRESS;
            inventory->mouse.id = i + 27;
            inventory->mouse.position = inventory->slots_position[i];
            display_on_item_text(head);
            inventory->item_window->id = i + 27;
            return (0);
        }
    }
    return (1);
}