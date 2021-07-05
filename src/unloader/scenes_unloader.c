/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** scenes_unloader
*/

#include "rpg.h"

void scenes_unloader(head_t *head, scenes_t *scene)
{
    if (head->window != NULL)
        sfRenderWindow_clear(head->window, sfBlack);
    for (int i = 0; i < DESTROY_PTR_NB; i++)
        DESTROY_PTR[i](scene);
}