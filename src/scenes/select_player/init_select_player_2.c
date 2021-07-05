/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** init_select_player_2
*/

#include "rpg.h"

void create_button_face(head_t *head, select_player_t *menu)
{
    create_button(head, ALEX_BUTTON, &menu->button);
    menu->alex_button = get_last_button(menu->button);
    sfSprite_setTextureRect(menu->alex_button->sprite, ALEX_FACE_RECT);
    create_button(head, ELLIOT_BUTTON, &menu->button);
    menu->elliot_button = get_last_button(menu->button);
    sfSprite_setTextureRect(menu->elliot_button->sprite, ELLIOT_FACE_RECT);
    create_button(head, HALEY_BUTTON, &menu->button);
    menu->haley_button = get_last_button(menu->button);
    sfSprite_setTextureRect(menu->haley_button->sprite, HALEY_FACE_RECT);
    create_button(head, MARU_BUTTON, &menu->button);
    menu->maru_button = get_last_button(menu->button);
    sfSprite_setTextureRect(menu->maru_button->sprite, MARU_FACE_RECT);
}

void create_object_appearance(head_t *head, select_player_t *menu)
{
    object_t *object;

    create_object(ALEX_APPEARANCE, &menu->object);
    object = get_last_object(menu->object);
    sfSprite_setTextureRect(object->sprite, ALEX_APPEARANCE_RECT);
    create_object(ELLIOT_APPEARANCE, &menu->object);
    object = get_last_object(menu->object);
    sfSprite_setTextureRect(object->sprite, ELLIOT_APPEARANCE_RECT);
    create_object(HALEY_APPEARANCE, &menu->object);
    object = get_last_object(menu->object);
    sfSprite_setTextureRect(object->sprite, HALEY_APPEARANCE_RECT);
    create_object(MARU_APPEARANCE, &menu->object);
    object = get_last_object(menu->object);
    sfSprite_setTextureRect(object->sprite, MARU_APPEARANCE_RECT);
}

void create_object_name(head_t *head, select_player_t *menu)
{
    object_t *object;

    create_object(ALEX_NAME, &menu->object);
    object = get_last_object(menu->object);
    sfSprite_setTextureRect(object->sprite, ALEX_NAME_RECT);
    create_object(ELLIOT_NAME, &menu->object);
    object = get_last_object(menu->object);
    sfSprite_setTextureRect(object->sprite, ELLIOT_NAME_RECT);
    create_object(HALEY_NAME, &menu->object);
    object = get_last_object(menu->object);
    sfSprite_setTextureRect(object->sprite, HALEY_NAME_RECT);
    create_object(MARU_NAME, &menu->object);
    object = get_last_object(menu->object);
    sfSprite_setTextureRect(object->sprite, MARU_NAME_RECT);
}