/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** parser_map_tools
*/

#include "rpg.h"
#include "../world.h"

int tileset_len(pars_data_t *obj)
{
    pars_res_info_t *source;
    int tile_count;

    for (; obj->next; obj = obj->next);
    source = load_pars_res(obj);
    tile_count = source->tile_count + json_search(obj->values.kobj,
    "firstgid")->values.kint;
    destroy_tileset(source);
    return (tile_count);
}

int pars_obj_len(pars_data_t *obj)
{
    int len = 0;

    for (; obj; obj = obj->next)
        len += 1;
    return (len);
}