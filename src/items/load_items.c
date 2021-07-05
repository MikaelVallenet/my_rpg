/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** load_items
*/

#include "rpg.h"

void load_strings_items(pars_data_t *data, items_t *new_items)
{
    (*new_items).name = malloc(sizeof(char) *
    my_strlen(json_search(data->values.kobj, "name")->values.kstr) + 1);
    my_strcpy((*new_items).name,
    json_search(data->values.kobj, "name")->values.kstr);
    (*new_items).description = malloc(sizeof(char) *
    my_strlen(json_search(data->values.kobj, "description")->values.kstr) + 1);
    my_strcpy((*new_items).description,
    json_search(data->values.kobj, "description")->values.kstr);
}

void load_sprite_items(pars_data_t *data, items_t *new_items)
{
    new_items->texture =
    sfTexture_createFromFile(json_search(data->values.kobj,
    "sprite")->values.kstr, NULL);
    (*new_items).sprite = sfSprite_create();
    sfSprite_setTexture(new_items->sprite, new_items->texture, sfTrue);
}

items_t load_items(int id_items)
{
    pars_obj_t *obj = parser_json(ITEMS_PATH);
    pars_data_t *data = obj->data->values.kobj;
    items_t new_items;

    while (data->values.kobj->values.kint != id_items) {
        data = data->next;
    }
    load_strings_items(data, &new_items);
    load_sprite_items(data, &new_items);
    new_items.stackable = json_search(data->values.kobj,
    "stackable")->values.kint;
    new_items.id = id_items;
    new_items.id_function = json_search(data->values.kobj,
    "id_function")->values.kint;
    new_items.damage = json_search(data->values.kobj, "damage")->values.kint;
    new_items.rarete = json_search(data->values.kobj, "rarete")->values.kint;
    new_items.armor = json_search(data->values.kobj, "armor")->values.kint;
    new_items.nbr = 1;
    pars_obj_destroy(obj);
    return (new_items);
}