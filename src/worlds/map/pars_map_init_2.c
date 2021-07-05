/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** pars_map_init_2
*/

#include "rpg.h"
#include "../world.h"

map_t *map_t_init(sfTexture **textures, pars_map_t *pmap)
{
    map_t *map = malloc(sizeof(map_t));

    map->res = textures;
    map->len = (sfVector2f){pmap->width, pmap->height};
    map->tile_len = pmap->tile_width;
    map->top = NULL;
    map->collision = NULL;
    map->event = NULL;
    return (map);
}