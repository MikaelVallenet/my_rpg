/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** destroy list object
*/

#include "rpg.h"

object_t *create_object_inv(object_data_t data, object_t **object)
{
    object_t *new_object = malloc(sizeof(object_t));

    new_object->texture = sfTexture_createFromFile(data.path, NULL);
    new_object->sprite = sfSprite_create();
    new_object->scale = data.scale;
    sfSprite_setPosition(new_object->sprite, data.pos);
    sfSprite_setTexture(new_object->sprite, new_object->texture, sfTrue);
    sfSprite_setScale(new_object->sprite, data.scale);
    new_object->next = NULL;
    return (new_object);
}

void destroy_one_object(object_t *object)
{
    sfTexture_destroy(object->texture);
    sfSprite_destroy(object->sprite);
    free(object);
}

void destroy_object(object_t *object)
{
    object_t *temp;

    while (object != NULL) {
        temp = object->next;
        sfTexture_destroy(object->texture);
        sfSprite_destroy(object->sprite);
        free(object);
        object = temp;
    }
}