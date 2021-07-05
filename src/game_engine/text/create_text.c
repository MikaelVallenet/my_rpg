/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create object
*/

#include "rpg.h"

void set_pos_hover_text(button_t *button)
{
    sfVector2f pos = sfSprite_getPosition(button->sprite);
    sfFloatRect rect_sprite = sfSprite_getGlobalBounds(button->sprite);
    sfFloatRect rect_text = sfText_getGlobalBounds(button->hover_text);

    pos.y += rect_sprite.height;
    pos.x += rect_sprite.width / 2
    - rect_text.width / 2;
    sfText_setPosition(button->hover_text, pos);
}

text_t *get_last_text(text_t *object)
{
    while (object->next != NULL) {
        object = object->next;
    }
    return (object);
}

void create_text(text_data_t data, text_t **object)
{
    text_t *new_object = malloc(sizeof(text_t));

    new_object->font = sfFont_createFromFile(data.path);
    new_object->text = sfText_create();
    sfText_setFont(new_object->text, new_object->font);
    sfText_setPosition(new_object->text, data.pos);
    sfText_setColor(new_object->text, data.color_text);
    sfText_setCharacterSize(new_object->text, data.size_text);
    sfText_setString(new_object->text, data.text_str);
    new_object->next = NULL;
    if (*object != NULL)
        get_last_text(*object)->next = new_object;
    else
        *object = new_object;
}