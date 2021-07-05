/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** handle over effect
*/

#include "rpg.h"

static void over_effect(head_t *head, inventory_t *inventory,
sfVector2f position, int i)
{
    if (inventory->mouse.mouse == PRESS)
        return;
    if (position.y > inventory->list_position[i].y &&
    position.y < inventory->list_position[i].y + 72.5 &&
    position.x > inventory->list_position[i].x &&
    position.x < inventory->list_position[i].x + 72.5) {
        sfSprite_setScale(inventory->items[i].sprite,
        (sfVector2f){0.30, 0.30});
        sfSprite_setPosition(inventory->items[i].sprite,
        (sfVector2f){inventory->list_position[i].x - 7,
        inventory->list_position[i].y - 7});
    } else {
        sfSprite_setScale(inventory->items[i].sprite,
        (sfVector2f){0.25, 0.25});
        sfSprite_setPosition(inventory->items[i].sprite,
        inventory->list_position[i]);
    }
}

static void over_effect_slots(head_t *head, inventory_t *inventory,
sfVector2f position, int i)
{
    if (inventory->mouse.mouse == PRESS)
        return;
    if (position.y > inventory->slots_position[i].y &&
    position.y < inventory->slots_position[i].y + 50 &&
    position.x > inventory->slots_position[i].x &&
    position.x < inventory->slots_position[i].x + 50) {
        sfSprite_setScale(inventory->slots[i].sprite,
        (sfVector2f){0.30, 0.30});
        sfSprite_setPosition(inventory->slots[i].sprite,
        (sfVector2f){inventory->slots_position[i].x - 15,
        inventory->slots_position[i].y - 15});
    } else {
        sfSprite_setScale(inventory->slots[i].sprite,
        (sfVector2f){0.18, 0.18});
        sfSprite_setPosition(inventory->slots[i].sprite,
        inventory->slots_position[i]);
    }
}

void handle_items_over_effect(head_t *head, inventory_t *inventory)
{
    const sfView *view = sfRenderWindow_getView(head->window);
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(head->window);
    sfVector2f position =
    sfRenderWindow_mapPixelToCoords(head->window, p_mouse, view);

    for (int i = 0; i < 27; i += 1) {
        if (inventory->items[i].id == 0)
            continue;
        over_effect(head, inventory, position, i);
    }
    for (int i = 0; i < 5; i += 1) {
        if (inventory->slots[i].id == 0)
            continue;
        over_effect_slots(head, inventory, position, i);
    }
}