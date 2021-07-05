/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** parser_tiles
*/

#include "rpg.h"
#include "../world.h"

pars_res_info_t *load_tileset(pars_data_t *obj)
{
    pars_res_info_t *res = malloc(sizeof(pars_res_info_t));

    res->column = json_search(obj, "columns")->values.kint;
    res->file_path = json_search(obj, "image")->values.kstr;
    res->file_path = my_strcat(TILED_MAP_FILE, res->file_path);
    res->image_height = json_search(obj, "imageheight")->values.kint;
    res->image_width = json_search(obj, "imagewidth")->values.kint;
    res->tile_height = json_search(obj, "tileheight")->values.kint;
    res->tile_width = json_search(obj, "tilewidth")->values.kint;
    res->tile_count = json_search(obj, "tilecount")->values.kint;
    res->data = obj;
    return (res);
}

void destroy_tileset(pars_res_info_t *info)
{
    free(info->file_path);
    free(info);
}

pars_res_info_t *load_pars_res(pars_data_t *obj)
{
    pars_data_t *data;
    pars_res_info_t *source;
    char *filepath;

    if (json_search(obj->values.kobj, "source")) {
        filepath = json_search(obj->values.kobj, "source")->values.kstr;
        filepath = my_strcat(TILED_MAP_FILE, filepath);
        data = parser_json(filepath)->data;
        free(filepath);
    } else
        data = obj->values.kobj;
    source = load_tileset(data);
    return (source);
}