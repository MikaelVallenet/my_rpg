/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create object
*/

#include "rpg.h"

object_t *get_last_object(object_t *object)
{
    while (object->next != NULL) {
        object = object->next;
    }
    return (object);
}

void create_object(object_data_t data, object_t **object)
{
    object_t *new_object = malloc(sizeof(object_t));

    new_object->texture = sfTexture_createFromFile(data.path, NULL);
    new_object->sprite = sfSprite_create();
    new_object->scale = data.scale;
    sfSprite_setPosition(new_object->sprite, data.pos);
    sfSprite_setTexture(new_object->sprite, new_object->texture, sfTrue);
    sfSprite_setScale(new_object->sprite, data.scale);
    new_object->next = NULL;
    if (*object != NULL)
        get_last_object(*object)->next = new_object;
    else
        *object = new_object;
}