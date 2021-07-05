/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** drag and drop
*/

#include "rpg.h"

static void handle_change_inventory_slots(head_t *head, inventory_t *inventory,
sfVector2f position)
{
    for (int i = 0; i < 27; i += 1) {
        if (position.y > inventory->list_position[i].y &&
        position.y < inventory->list_position[i].y + 72.5 &&
        position.x > inventory->list_position[i].x &&
        position.x < inventory->list_position[i].x + 72.5 &&
        inventory->items[i].id == 0) {
            inventory->items[i] =
            load_items(inventory->items[inventory->mouse.id].id);
            destroy_items(inventory->mouse.id, inventory, head->scenes);
            inventory->items[inventory->mouse.id].id = 0;
            return;
        }
    }
}

static void handle_equip_armor(head_t *head, inventory_t *inventory,
sfVector2f position)
{
    for (int i = 0; i < 5; i += 1) {
        if (position.y > inventory->slots_position[i].y &&
        position.y < inventory->slots_position[i].y + 50 &&
        position.x > inventory->slots_position[i].x &&
        position.x < inventory->slots_position[i].x + 50 &&
        inventory->slots[i].id == 0) {
            ITEMS_PTR[inventory->items[inventory->mouse.id].id_function](i,
            inventory, head);
        }
    }
}

void release_drag_and_drop(head_t *head, inventory_t *inventory)
{
    const sfView *view = sfRenderWindow_getView(head->window);
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(head->window);
    sfVector2f position =
    sfRenderWindow_mapPixelToCoords(head->window, p_mouse, view);

    inventory->mouse.mouse = UNPRESS;
    sfSprite_setPosition(inventory->items[inventory->mouse.id].sprite,
    inventory->mouse.position);
    inventory->mouse.position = (sfVector2f){0, 0};
    if (position.x < inventory->position.x ||
    position.x > inventory->p_position.x + 707 ||
    position.y < inventory->p_position.y ||
    position.y > inventory->p_position.y + 570) {
        destroy_items(inventory->mouse.id, inventory, head->scenes);
        inventory->items[inventory->mouse.id].id = 0;
    } else {
        handle_change_inventory_slots(head, inventory, position);
        handle_equip_armor(head, inventory, position);
    }
    inventory->mouse.id = -1;
}

void handler_drag_and_drop(head_t *head, inventory_t *inventory)
{
    const sfView *view = sfRenderWindow_getView(head->window);
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(head->window);
    sfVector2f position =
    sfRenderWindow_mapPixelToCoords(head->window, p_mouse, view);

    position.x -= 35;
    position.y -= 35;
    if (inventory->mouse.mouse == PRESS) {
        sfSprite_setPosition(inventory->items[inventory->mouse.id].sprite,
        position);
    }
}

void drag_and_drop_on(inventory_t *inventory, head_t *head)
{
    const sfView *view = sfRenderWindow_getView(head->window);
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(head->window);
    sfVector2f position =
    sfRenderWindow_mapPixelToCoords(head->window, p_mouse, view);

    if (drag_and_drop_on_inv(head, inventory, position) &&
    drag_and_drop_on_slots(head, inventory, position))
        display_off_item_text(head->scenes);
}