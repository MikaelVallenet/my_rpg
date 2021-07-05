/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** map_event_manager
*/

#include "rpg.h"
#include "../world.h"

void game_event_manager(head_t *head)
{
    char *event;

    event = game_event_detector(head->scenes->in_game->player,
    head->scenes->in_game->map);
    if (event && !head->scenes->global->fade_clock) {
        event_launch(head, event_finder(head->scenes->in_game->map->event,
        event));
    } else
        head->scenes->in_game->event_text_display = 0;
}