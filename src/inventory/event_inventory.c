/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** event inventory
*/

#include "rpg.h"

static void display_on_inventory_text(head_t *head)
{
    display_on_text_scrolling("inv_name",
    head->scenes->in_game->text_scrolling);
    display_on_text_scrolling("inv_lvl",
    head->scenes->in_game->text_scrolling);
    display_on_text_scrolling("inv_health",
    head->scenes->in_game->text_scrolling);
    display_on_text_scrolling("inv_xp",
    head->scenes->in_game->text_scrolling);
    display_on_text_scrolling("inv_damage",
    head->scenes->in_game->text_scrolling);
    display_on_text_scrolling("inv_armor",
    head->scenes->in_game->text_scrolling);
}

static void display_off_inventory_text(head_t *head)
{
    display_off_text_scrolling("inv_name",
    head->scenes->in_game->text_scrolling);
    display_off_text_scrolling("inv_lvl",
    head->scenes->in_game->text_scrolling);
    display_off_text_scrolling("inv_health",
    head->scenes->in_game->text_scrolling);
    display_off_text_scrolling("inv_xp",
    head->scenes->in_game->text_scrolling);
    display_off_text_scrolling("inv_damage",
    head->scenes->in_game->text_scrolling);
    display_off_text_scrolling("inv_armor",
    head->scenes->in_game->text_scrolling);
    display_off_text_scrolling("item_name",
    head->scenes->in_game->text_scrolling);
    display_off_text_scrolling("item_quantity",
    head->scenes->in_game->text_scrolling);
    display_off_text_scrolling("item_desc",
    head->scenes->in_game->text_scrolling);
}

void event_drag_and_drop(head_t *head, sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased &&
    head->scenes->in_game->inventory->open == 1 &&
    event.mouseButton.button == sfMouseLeft &&
    head->scenes->in_game->inventory->mouse.mouse == PRESS) {
        release_drag_and_drop(head, head->scenes->in_game->inventory);
    }
    if (event.type == sfEvtMouseButtonPressed && event.type != sfEvtClosed &&
    head->scenes->in_game->inventory->open == 1 &&
    event.mouseButton.button == sfMouseLeft)
        drag_and_drop_on(head->scenes->in_game->inventory, head);
}

void event_inventory(head_t *head, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF &&
    head->scenes->in_game->inventory->open == 1 &&
    head->scenes->in_game->inventory->mouse.mouse == UNPRESS) {
        display_off_inventory_text(head);
        head->scenes->in_game->inventory->open = 0;
        head->scenes->in_game->inventory->item_window->open = 0;
        return;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF &&
    head->scenes->in_game->inventory->open == 0) {
        display_on_inventory_text(head);
        head->scenes->in_game->inventory->open = 1;
    }
    event_drag_and_drop(head, event);
}