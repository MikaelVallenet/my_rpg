/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create button
*/

#include "rpg.h"

button_t *get_last_button(button_t *first_button)
{
    while ((first_button)->next != NULL)
        first_button = (first_button)->next;
    return (first_button);
}

static void create_text_button(head_t *head, button_data_t data,
button_t *new)
{
    sfVector2f pos = data.pos;
    sfFloatRect rect_sprite;
    sfFloatRect rect_text;

    new->text = sftext_create(head->res->fonts->basic,
    data.color_text, data.size_text, data.text_str);
    rect_sprite = sfSprite_getGlobalBounds(new->sprite);
    rect_text = sfText_getGlobalBounds(new->text);
    pos.y += rect_sprite.height / 2
    - rect_text.height / 2 - 10;
    pos.x += rect_sprite.width / 2
    - rect_text.width / 2;
    sfText_setPosition(new->text, pos);
    sfText_setFillColor(new->text, (sfColor){255, 255, 255, 255});
}

static void create_hover_text_button(head_t *head, button_data_t data,
button_t *new)
{
    sfVector2f pos = data.pos;
    sfFloatRect rect_sprite;
    sfFloatRect rect_text;

    new->hover_text = sftext_create(head->res->fonts->basic,
    data.color_hover_text, data.size_hover_text, data.hover_text_str);
    rect_sprite = sfSprite_getGlobalBounds(new->sprite);
    rect_text = sfText_getGlobalBounds(new->hover_text);
    pos.y += rect_sprite.height;
    pos.x += rect_sprite.width / 2
    - rect_text.width / 2;
    sfText_setPosition(new->hover_text, pos);
    sfText_setFillColor(new->hover_text, (sfColor){255, 255, 255, 0});
}

static void sprite_config(button_t *new_button, button_data_t data)
{
    sfSprite_setPosition(new_button->sprite, data.pos);
    sfSprite_setScale(new_button->sprite, data.scale);
}

void create_button(head_t *head, button_data_t data, button_t **list_button)
{
    button_t *new_button = malloc(sizeof(button_t));

    new_button->sprite = sfSprite_create();
    sprite_config(new_button, data);
    new_button->texture = sfTexture_createFromFile(data.path, NULL);
    sfSprite_setTexture(new_button->sprite, new_button->texture, sfTrue);
    create_text_button(head, data, new_button);
    create_hover_text_button(head, data, new_button);
    new_button->pos_original = data.pos;
    new_button->scale_original = data.scale;
    new_button->type = data.type;
    new_button->clock = NULL;
    new_button->call_func = data.call_func;
    new_button->next = NULL;
    if (*list_button != NULL)
        get_last_button(*list_button)->next = new_button;
    else
        *list_button = new_button;
}