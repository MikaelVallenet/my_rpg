/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init inventory
*/

#include "rpg.h"

static void create_inventory_text(head_t *head)
{
    create_text_scrolling(head,
    INV_HEALTH, &head->scenes->in_game->text_scrolling);
    create_text_scrolling(head,
    INV_NAME, &head->scenes->in_game->text_scrolling);
    create_text_scrolling(head,
    INV_XP, &head->scenes->in_game->text_scrolling);
    create_text_scrolling(head,
    INV_LVL, &head->scenes->in_game->text_scrolling);
    create_text_scrolling(head,
    INV_DAMAGE, &head->scenes->in_game->text_scrolling);
    create_text_scrolling(head,
    INV_ARMOR, &head->scenes->in_game->text_scrolling);
}

static void start_inventory_text(head_t *head)
{
    start_text_scrolling("inv_name", head->scenes->in_game->text_scrolling);
    start_text_scrolling("inv_lvl", head->scenes->in_game->text_scrolling);
    start_text_scrolling("inv_health", head->scenes->in_game->text_scrolling);
    start_text_scrolling("inv_xp", head->scenes->in_game->text_scrolling);
    start_text_scrolling("inv_damage", head->scenes->in_game->text_scrolling);
    start_text_scrolling("inv_armor", head->scenes->in_game->text_scrolling);
}

static void create_inventory_bar(in_game_t *menu, inventory_t *inventory)
{
    inventory->healh_bg_bar =
    create_object_inv(BAR_HEALTH_BG_INVENTORY, &menu->object);
    inventory->health_bar =
    create_object_inv(BAR_HEALTH_INVENTORY, &menu->object);
    inventory->experience_bg_bar =
    create_object_inv(BAR_EXPERIENCE_BG_INVENTORY, &menu->object);
    inventory->experience_bar =
    create_object_inv(BAR_EXPERIENCE_INVENTORY, &menu->object);
    inventory->armor =
    create_object_inv(ARMOR_ICONE, &menu->object);
    inventory->damage =
    create_object_inv(DAMAGE_ICONE, &menu->object);
}

static void init_pos_inventory(inventory_t *inventory)
{
    inventory->open = 0;
    for (int i = 0; i < 27; i += 1) {
        inventory->list_position[i] = (sfVector2f){639 + 72.5 * (i % 9),
        544 + 72.5 * (i / 9)};
    }
    for (int i = 0; i < 4; i += 1) {
        inventory->slots_position[i] = (sfVector2f){649, 405 - (i * 57)};
    }
    inventory->slots_position[4] = (sfVector2f){862, 314};
}

void init_inventory(head_t *head, inventory_data_t data)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    create_inventory_text(head);
    start_inventory_text(head);
    inventory->sprite = sfSprite_create();
    inventory->texture = sfTexture_createFromFile(data.path, NULL);
    inventory->position = data.position;
    inventory->scale = data.scale;
    inventory->p_position = data.p_position;
    sfSprite_setTexture(inventory->sprite, inventory->texture, sfTrue);
    sfSprite_setPosition(inventory->sprite, inventory->position);
    sfSprite_setScale(inventory->sprite, inventory->scale);
    create_inventory_bar(head->scenes->in_game, inventory);
    head->scenes->in_game->inventory = inventory;
    fill_empty_inventory(inventory);
    init_pos_inventory(inventory);
    init_item_window(head, inventory);
    inventory->time = 0;
    inventory->mouse = (drag_and_drop_t){UNPRESS, -1, (sfVector2f){0, 0}};
    init_item_inventory(head, inventory);
    inventory->item_window->id = -1;
}