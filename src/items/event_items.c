/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** event items
*/

#include "rpg.h"

void display_on_item_text(head_t *head)
{
    head->scenes->in_game->inventory->item_window->open = 1;
    display_on_text_scrolling("item_name",
    head->scenes->in_game->text_scrolling);
    display_on_text_scrolling("item_desc",
    head->scenes->in_game->text_scrolling);
    display_on_text_scrolling("item_quantity",
    head->scenes->in_game->text_scrolling);
}

void display_off_item_text(scenes_t *scenes)
{
    scenes->in_game->inventory->item_window->open = 0;
    display_off_text_scrolling("item_name",
    scenes->in_game->text_scrolling);
    display_off_text_scrolling("item_desc",
    scenes->in_game->text_scrolling);
    display_off_text_scrolling("item_quantity",
    scenes->in_game->text_scrolling);
}