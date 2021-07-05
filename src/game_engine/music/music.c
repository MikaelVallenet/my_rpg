/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** manage music
*/

#include "rpg.h"

sfMusic *create_music(head_t *head, char *path)
{
    sfMusic *music;

    music = sfMusic_createFromFile(path);
    sfMusic_setVolume(music, head->option->music_volume);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return (music);
}

void update_bar_music(head_t *head, object_t *object)
{
    sfVector2u size_texture = sfTexture_getSize(object->texture);
    sfIntRect rect;

    rect.height = size_texture.y * object->scale.y;
    rect.width = (int)sfMusic_getVolume(head->res->music->music) *
    size_texture.x / 100;
    rect.top = 0;
    rect.left = 0;
    sfSprite_setTextureRect(object->sprite, rect);
}

void update_button_on_off_music(head_t *head, button_t *object)
{
    if (sfMusic_getVolume(head->res->music->music) > 0) {
        sfTexture_destroy(object->texture);
        object->texture =
        sfTexture_createFromFile("assets/buttons/button_on.png", NULL);
        sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    }
    else {
        sfTexture_destroy(object->texture);
        object->texture =
        sfTexture_createFromFile("assets/buttons/button_off.png", NULL);
        sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    }
}