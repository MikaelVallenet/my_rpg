/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** event_zone
*/

#include "rpg.h"

void move_event_zone(npc_t *npc)
{
    npc->event_zone.top = npc->pos.y -
    ((npc->event_zone.height / 2) - (npc->rect.height / 2));
    npc->event_zone.left = npc->pos.x -
    ((npc->event_zone.width / 2) - (npc->rect.width / 2));
}

sfBool is_in_event_zone(player_t *player, npc_t *npc)
{
    sfVector2f pos_player = player->pos;
    sfIntRect rect_player = player->rect;
    sfIntRect rect_npc = npc->event_zone;

    pos_player.x = pos_player.x + rect_player.width / 2;
    if (sfIntRect_contains(&rect_npc, pos_player.x, pos_player.y)) {
        return (sfTrue);
    }
    return (sfFalse);
}

void init_event_zone(pars_data_t *data, npc_t *npc)
{
    pars_data_t *zone = json_search(data, "event_zone");
    int height = json_search(zone->values.kobj, "height")->values.kint;
    int width = json_search(zone->values.kobj, "width")->values.kint;

    npc->event_zone.height = height;
    npc->event_zone.width = width;
    npc->event_zone.top = npc->pos.y -
    ((height / 2) - (npc->rect.height / 2));
    npc->event_zone.left = npc->pos.x -
    ((width / 2) - (npc->rect.width / 2));
}