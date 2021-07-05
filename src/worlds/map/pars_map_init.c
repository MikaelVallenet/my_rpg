/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** pars_map_init
*/

#include "rpg.h"
#include "../world.h"

static sfBool special_layers(map_t *map, sfSprite ***sprites, char *name)
{
    if (my_strcmp(name, COLLISION_LAYER) == 0) {
        map->collision = sprites;
        return (0);
    } else if (my_strcmp(name, TOP_LAYER) == 0) {
        map->top = sprites;
        return (1);
    }
    return (0);
}

static sfSprite **width_map_init(sfTexture **texture, pars_map_t *map,
pars_data_t **data, int y)
{
    sfSprite **width_sprite = malloc(sizeof(sfSprite *) * (map->width + 1));

    for (int x = 0; x < map->width; x += 1) {
        if ((*data)->values.kint) {
            width_sprite[x] = sfSprite_create();
            sfSprite_setTexture(width_sprite[x],
            texture[(*data)->values.kint], sfTrue);
            sfSprite_setPosition(width_sprite[x],
            (sfVector2f){x * 64, y * 64});
            sfSprite_setScale(width_sprite[x], (sfVector2f){4, 4});
        } else {
            texture[(*data)->values.kint] = NULL;
            width_sprite[x] = NULL;
        }
        *data = (*data)->next;
    }
    width_sprite[map->width] = NULL;
    return (width_sprite);
}

static sfSprite ***height_map_init(sfTexture **texture, pars_map_t *map)
{
    sfSprite ***height_sprite = malloc(sizeof(sfSprite **) *
    (map->height + 1));
    pars_data_t *data =
    json_search(map->layers->values.kobj, "data")->values.kobj;

    for (int y = 0; y < map->height; y += 1) {
        height_sprite[y] = width_map_init(texture, map, &data, y);
    }
    height_sprite[map->height] = NULL;
    return (height_sprite);
}

static void layer_analysis(pars_map_t *map, map_t *map_content,
sfSprite ****map_sprite, int *layers_len)
{
    sfSprite ***current_sprite;

    for (int i = 0; map->layers; map->layers = map->layers->next) {
        if (event_layers(map->layers->values.kobj, map_content)) {
            *layers_len -= 1;
            continue;
        }
        current_sprite = height_map_init(map_content->res, map);
        if (special_layers(map_content, current_sprite,
        json_search(map->layers->values.kobj, "name")->values.kstr) == 0) {
            map_sprite[i] = current_sprite;
            i += 1;
        } else
            *layers_len -= 1;
    }
}

map_t *pars_map_sprite_init(sfTexture **texture, pars_map_t *map)
{
    int layers_len = pars_obj_len(map->layers);
    sfSprite ****map_sprite = malloc(sizeof(sfSprite ***) * (layers_len + 1));
    map_t *map_content = map_t_init(texture, map);

    layer_analysis(map, map_content, map_sprite, &layers_len);
    map_sprite[layers_len] = NULL;
    map_content->layer_len = layers_len;
    map_content->map = map_sprite;
    return (map_content);
}