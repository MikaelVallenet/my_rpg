/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** load_save
*/

#include "rpg.h"

void load_save(head_t *head, char *path)
{
    if (file_size(path) <= 0)
        start_fade_animation(head, NULL, STATE_SELECT_PLAYER);
    else
        start_fade_animation(head, NULL, STATE_INGAME);
}