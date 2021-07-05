/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** set_volume
*/

#include "rpg.h"

void set_volume(head_t *head, float volume)
{
    sfSound_setVolume(head->res->sfx->click_sound, volume);
    sfSound_setVolume(head->res->sfx->attack_sound, volume);
    sfSound_setVolume(head->res->sfx->defend_sound, volume);
}