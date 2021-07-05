/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** global_handler
*/

#include "rpg.h"

void global_event(head_t *head, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(head->window);
    if (event.type == sfEvtKeyPressed)
        head->event->key_input = event.key.code;
}

void global_handler(head_t *head)
{
    return;
}

void global_display(head_t *head)
{
    return;
}