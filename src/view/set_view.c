/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** set_view
*/

#include "rpg.h"

void follow_player(head_t *head)
{
    sfVector2f pos = head->scenes->in_game->player->pos;
    sfVector2f center = sfView_getCenter(head->scenes->in_game->view);
    sfFloatRect rect_p;

    rect_p = sfSprite_getGlobalBounds(head->scenes->in_game->player->sprite);
    pos.x = pos.x + rect_p.width / 2;
    pos.y = pos.y + rect_p.height / 2;
    if (pos.x - 960 <= 0)
        pos.x = 960;
    else if (pos.x + 960 >= head->technical->size_map.x)
        pos.x = head->technical->size_map.x - 960;
    if (pos.y - 540 <= 0)
        pos.y = 540;
    else if (pos.y + 540 >= head->technical->size_map.y)
        pos.y = head->technical->size_map.y - 540;
    if (head->technical->size_map.x <= 1920)
        pos.x = 0 + (head->technical->size_map.x / 2);
    if (head->technical->size_map.y <= 1080)
        pos.y = 0 + (head->technical->size_map.y / 2);
    if (center.x != pos.x || center.y != pos.y)
        sfView_setCenter(head->scenes->in_game->view, pos);
}