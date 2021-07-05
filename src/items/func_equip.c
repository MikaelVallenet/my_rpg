/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** item functions
*/

#include "rpg.h"

void equip_sword(int i, inventory_t *inventory, head_t *head)
{
    if (i != 4)
        return;
    inventory->slots[i] = load_items(inventory->items[inventory->mouse.id].id);
    destroy_items(inventory->mouse.id, inventory, head->scenes);
    inventory->items[inventory->mouse.id].id = 0;
    head->scenes->in_game->player->p_stat.damage +=
    inventory->slots[i].damage;
}

void equip_helmet(int i, inventory_t *inventory, head_t *head)
{
    if (i != 3)
        return;
    inventory->slots[i] = load_items(inventory->items[inventory->mouse.id].id);
    destroy_items(inventory->mouse.id, inventory, head->scenes);
    inventory->items[inventory->mouse.id].id = 0;
    head->scenes->in_game->player->p_stat.armor +=
    inventory->slots[i].armor;
}

void equip_chestplate(int i, inventory_t *inventory, head_t *head)
{
    if (i != 2)
        return;
    inventory->slots[i] = load_items(inventory->items[inventory->mouse.id].id);
    destroy_items(inventory->mouse.id, inventory, head->scenes);
    inventory->items[inventory->mouse.id].id = 0;
    head->scenes->in_game->player->p_stat.armor +=
    inventory->slots[i].armor;
}

void equip_leggings(int i, inventory_t *inventory, head_t *head)
{
    if (i != 1)
        return;
    inventory->slots[i] = load_items(inventory->items[inventory->mouse.id].id);
    destroy_items(inventory->mouse.id, inventory, head->scenes);
    inventory->items[inventory->mouse.id].id = 0;
    head->scenes->in_game->player->p_stat.armor +=
    inventory->slots[i].armor;
}

void equip_boots(int i, inventory_t *inventory, head_t *head)
{
    if (i != 0)
        return;
    inventory->slots[i] = load_items(inventory->items[inventory->mouse.id].id);
    destroy_items(inventory->mouse.id, inventory, head->scenes);
    inventory->items[inventory->mouse.id].id = 0;
    head->scenes->in_game->player->p_stat.armor +=
    inventory->slots[i].armor;
}