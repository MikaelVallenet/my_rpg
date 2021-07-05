/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** init_item
*/

#include "rpg.h"

void init_item_inventory(head_t *head, inventory_t *inventory)
{
    pars_data_t *obj;
    pars_data_t *stat;
    int id_item = 0;

    obj =
    json_search(head->scenes->in_game->player->stat_json->data, "inventory");
    obj = obj->values.kobj;
    for (int i = 0; i < 32; i++) {
        stat = obj->values.kobj;
        id_item = stat->values.kint;
        if (id_item != 0)
            inventory->items[i] = load_items(id_item);
        stat = stat->next;
        if (id_item != 0)
            inventory->items[i].nbr = stat->values.kint;
        obj = obj->next;
    }
}