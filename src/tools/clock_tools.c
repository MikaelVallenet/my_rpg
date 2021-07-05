/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** clock tools
*/

#include "rpg.h"

float get_time(head_t *head)
{
    sfClock *clock = head->scenes->in_game->clock;

    return (sfClock_getElapsedTime(clock).microseconds / 1000000.0);
}