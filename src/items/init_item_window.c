/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init item window
*/

#include "rpg.h"

static void create_item_text(head_t *head)
{
    create_text_scrolling(head,
    ITEM_NAME, &head->scenes->in_game->text_scrolling);
    create_text_scrolling(head,
    ITEM_QUANTITY, &head->scenes->in_game->text_scrolling);
    create_text_scrolling(head,
    ITEM_DESC, &head->scenes->in_game->text_scrolling);
}

static void start_item_text(head_t *head)
{
    start_text_scrolling("item_name", head->scenes->in_game->text_scrolling);
    start_text_scrolling("item_quantity",
    head->scenes->in_game->text_scrolling);
    start_text_scrolling("item_desc", head->scenes->in_game->text_scrolling);
}

void init_item_window(head_t *head, inventory_t *inventory)
{
    inventory->item_window = malloc(sizeof(item_window_t));
    inventory->item_window->open = 0;
    inventory->item_window->texture =
    sfTexture_createFromFile(ITEM_WINDOW_PATH, NULL);
    inventory->item_window->sprite = sfSprite_create();
    sfSprite_setTexture(inventory->item_window->sprite,
    inventory->item_window->texture, sfTrue);
    inventory->item_window->p = (sfVector2f){70, 100};
    inventory->item_window->p_sprite = (sfVector2f){170, 215};
    sfSprite_setPosition(inventory->item_window->sprite,
    inventory->item_window->p);
    create_item_text(head);
    start_item_text(head);
}