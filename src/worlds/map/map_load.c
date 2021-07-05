/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** parser_resources
*/

#include "rpg.h"
#include "../world.h"

static pars_map_t *pars_map_load(pars_obj_t *obj)
{
    pars_map_t *map = malloc(sizeof(pars_map_t));
    pars_data_t *data = obj->data;

    map->obj = obj;
    map->data = obj->data;
    map->height = json_search(data, "height")->values.kint;
    map->layers = json_search(data, "layers")->values.kobj;
    map->tile_height = json_search(data, "tileheight")->values.kint;
    map->tile_width = json_search(data, "tilewidth")->values.kint;
    map->tilesets = json_search(data, "tilesets")->values.kobj;
    map->width = json_search(data, "width")->values.kint;
    return (map);
}

static void load_tile_res(pars_res_info_t *info, sfTexture **text, int *i)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));
    sfTexture *main_texture = sfTexture_createFromFile(info->file_path, NULL);
    sfImage *main_image = sfTexture_copyToImage(main_texture);

    *rect = (sfIntRect){0, 0, info->tile_width, info->tile_height};
    for (int j = 0; j < info->tile_count; j += 1) {
        text[*i] = sfTexture_createFromImage(main_image, rect);
        if (rect->left + info->tile_width >= info->image_width) {
            rect->left = 0;
            rect->top += info->tile_height;
        } else {
            rect->left += info->tile_width;
        }
        *i += 1;
    }
    sfImage_destroy(main_image);
    sfTexture_destroy(main_texture);
    free(rect);
}

static sfTexture **load_map_res(pars_map_t *map)
{
    pars_data_t *tilesets = map->tilesets;
    int len = tileset_len(tilesets);
    sfTexture **textures = malloc(sizeof(sfTexture *) * len);
    pars_res_info_t *info;

    for (int i = 1; tilesets;) {
        info = load_pars_res(tilesets);
        load_tile_res(info, textures, &i);
        destroy_tileset(info);
        tilesets = tilesets->next;
    }
    return (textures);
}

map_t *load_map(head_t *head, char *name)
{
    pars_obj_t *global_obj = parser_json(name);
    pars_map_t *pmap = pars_map_load(global_obj);
    sfTexture **textures = load_map_res(pmap);
    map_t *map = pars_map_sprite_init(textures, pmap);

    for (int i = 0; GLOBAL_NPC[i].map_name; i += 1)
        if (my_strcmp(GLOBAL_NPC[i].map_name, name) == 0)
            init_npc(head, &head->scenes->in_game->npc,
            GLOBAL_NPC[i].npc_json);
    for (int i = 0; GLOBAL_MUSIC[i].map_name; i += 1)
        if (my_strcmp(GLOBAL_MUSIC[i].map_name, name) == 0) {
            sfMusic_destroy(head->res->music->music);
            head->res->music->music = create_music(head,
            GLOBAL_MUSIC[i].filepath);
            break;
        }
    head->technical->size_map = (sfVector2f){map->len.x * 64, map->len.y * 64};
    map->name = my_strdup(name);
    pars_obj_destroy(global_obj);
    free(pmap);
    return (map);
}