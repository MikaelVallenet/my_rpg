/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** main_2_loader
*/

#include "rpg.h"

event_t *event_initialize(void)
{
    event_t *event = malloc(sizeof(event_t));

    event->key_input = 0;
    event->mouse_coords = (sfVector2f){0, 0};
    return (event);
}