/*
** EPITECH PROJECT, 2021
** inventory
** File description:
** inventory
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include "rpg.h"

#define ITEMS_PATH "resources/items/items.json"
#define DOUBLE_CLICK 1.0

typedef struct text_scrolling_s text_scrolling_t;
typedef struct object_data_s object_data_t;

typedef struct lvl_up_s {
    sfText *lvlup;
    float timer;
} lvl_up_t;

typedef struct inventory_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f p_position;
    sfVector2f scale;
    int open;
    object_t *healh_bg_bar;
    object_t *health_bar;
    object_t *experience_bg_bar;
    object_t *experience_bar;
    object_t *damage;
    object_t *armor;
    items_t items[27];
    items_t slots[5];
    sfVector2f list_position[27];
    sfVector2f slots_position[5];
    drag_and_drop_t mouse;
    item_window_t *item_window;
    float time;
} inventory_t;

typedef struct inventory_data_s {
    char *path;
    sfVector2f position;
    sfVector2f p_position;
    sfVector2f scale;
} inventory_data_t;

// CONST VARIABLE INVENTORY

static const text_data_scrolling_t ITEM_NAME = {"item_name",
NULL, "NAME : ANTICONSITUTIONELLEMENT", {230, 145}, (sfColor){0, 0, 0, 255},
35, T_FULL};

static const text_data_scrolling_t ITEM_QUANTITY = {"item_quantity",
NULL, "Quantity : 999", {240, 570}, (sfColor){0, 0, 0, 255},
35, T_FULL};

static const text_data_scrolling_t ITEM_DESC = {"item_desc",
NULL, "Ceci est une description", {140, 670}, (sfColor){0, 0, 0, 255},
25, T_FULL};

static const inventory_data_t INVENTORY = {"./assets/inventory.png",
(sfVector2f){607, 209}, (sfVector2f){730, 250}, (sfVector2f){0.5, 0.5}};

//SLIDE BAR INVENTORY

static const object_data_t BAR_HEALTH_BG_INVENTORY =
{"assets/images/bar_1/bg_bar.png",
{(1920 / 2) - (421 * 1.2) - 15 + 590,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 307 - 96},
{0.5, 0.5}
};

static const object_data_t BAR_HEALTH_INVENTORY =
{"assets/images/bar_1/bar_5.png",
{(1920 / 2) - (421 * 1.2) - 15 + 593,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 307 - 92},
{1.123 / 2, 0.97 / 2}
};

static const object_data_t BAR_EXPERIENCE_BG_INVENTORY =
{"assets/images/bar_1/bg_bar.png",
{(1920 / 2) - (421 * 1.2) - 15 + 590,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 307 - 46},
{0.5, 0.5}
};

static const object_data_t BAR_EXPERIENCE_INVENTORY =
{"assets/images/bar_1/bar_2.png",
{(1920 / 2) - (421 * 1.2) - 15 + 593,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 307 - 42},
{1.123 / 2, 0.97 / 2}
};

static const object_data_t DAMAGE_ICONE =
{"assets/images/picto/sword.png",
{1030, 330},
{0.1, 0.1}
};

static const object_data_t ARMOR_ICONE =
{"assets/images/picto/shield.png",
{1130, 333},
{0.10, 0.10}
};

void init_inventory(head_t *head, inventory_data_t data);
void display_inventory(head_t *head);
void event_inventory(head_t *head, sfEvent event);
void destroy_inventory(inventory_t *inventory, scenes_t *scenes);
void update_inventory_str(inventory_t *inventory, text_scrolling_t *text,
player_t *player);
object_t *create_object_inv(object_data_t data, object_t **object);
void init_item_inventory(head_t *head, inventory_t *inventory);
void fill_empty_inventory(inventory_t *inventory);

#endif /* !INVENTORY_H */
