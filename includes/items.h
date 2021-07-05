/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** items
*/

#ifndef ITEMS
#define ITEMS

#include "rpg.h"

#define ITEM_WINDOW_PATH "./assets/item_descriptor.png"
typedef struct inventory_s inventory_t;

typedef struct items_s {
    int id;
    char *name;
    char *description;
    int stackable;
    int nbr;
    int id_function;
    int damage;
    int armor;
    int rarete;
    sfSprite *sprite;
    sfTexture *texture;
} items_t;

typedef struct drag_and_drop_s {
    state_key_t mouse;
    int id;
    sfVector2f position;
} drag_and_drop_t;

typedef struct item_window_s {
    int open;
    int id;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f p;
    sfVector2f p_sprite;
} item_window_t;

//PROTOTYPES

items_t load_items(int id_items);
void drag_and_drop_on(inventory_t *inventory, head_t *head);
void display_items_inventory(head_t *head, inventory_t *inventory);
void handle_items_over_effect(head_t *head, inventory_t *inventory);
void release_drag_and_drop(head_t *head, inventory_t *inventory);
void handler_drag_and_drop(head_t *head, inventory_t *inventory);
void destroy_items(int i, inventory_t *inventory, scenes_t *scenes);
void add_items(int id, inventory_t *inventory);
void init_item_window(head_t *head, inventory_t *inventory);
void destroy_item_window(inventory_t *inventory);
void destroy_item_window(inventory_t *inventory);
void display_item_window(head_t *head, inventory_t *inventory);
void display_on_item_text(head_t *head);
void display_off_item_text(scenes_t *scenes);
void update_item_text(inventory_t *inventory, text_scrolling_t *text);
void destroy_slots_inv(int i, inventory_t *inventory, scenes_t *scenes);
void equip_helmet(int i, inventory_t *inventory, head_t *head);
void equip_chestplate(int i, inventory_t *inventory, head_t *head);
void equip_leggings(int i, inventory_t *inventory, head_t *head);
void equip_boots(int i, inventory_t *inventory, head_t *head);
void equip_sword(int i, inventory_t *inventory, head_t *head);
void health_potion(int i, inventory_t *inventory, head_t *head);
void experience_potion(int i, inventory_t *inventory, head_t *head);
int drag_and_drop_on_inv(head_t *head, inventory_t *inventory,
sfVector2f position);
int drag_and_drop_on_slots(head_t *head, inventory_t *inventory,
sfVector2f position);
void update_timer(head_t *head, inventory_t *inventory);
void double_click(head_t *head, inventory_t *inventory, int i);
void destroy_stacked_item(head_t *head, inventory_t *inventory);
void launch_rdm_fight(head_t *head);

static void (*const ITEMS_PTR[])
(int, inventory_t *, head_t *) = {health_potion, experience_potion,
equip_boots, equip_leggings, equip_chestplate, equip_helmet, equip_sword};

#endif /* !ITEMS */
