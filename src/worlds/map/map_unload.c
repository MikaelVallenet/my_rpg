/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** map_unload
*/

#include "rpg.h"
#include "../world.h"

static void destroy_layer(sfSprite ***sprite)
{
    for (int i = 0; sprite[i]; i += 1) {
        for (int j = 0; sprite[i][j]; j += 1) {
            sfSprite_destroy(sprite[i][j]);
        }
    }
}

void unload_map_t(map_t *map)
{
    game_event_t *next;

    for (int i = 0; map->res[i]; i += 1)
        sfTexture_destroy(map->res[i]);
    for (; map->event; map->event = next) {
        next = map->event->next;
        free(map->event);
    }
    destroy_layer(map->top);
    for (int i = 0; map->map[i]; i += 1)
        destroy_layer(map->map[i]);
    free(map);
}