/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** hitbox
*/

#include "rpg.h"

static sfBool is_hitbox_npc(head_t *head, sfVector2f pos)
{
    npc_t *npc = head->scenes->in_game->npc;
    sfIntRect rect = head->scenes->in_game->player->rect;

    while (npc != NULL) {
        if (pos.x <= npc->pos.x + ((npc->rect.width - 4) * 3.5) &&
        pos.x >= npc->pos.x &&
        pos.y <= npc->pos.y + ((npc->rect.height / 2) - 6) * 3.5 &&
        pos.y + (rect.height * 3.5) >= npc->pos.y) {
            return (0);
        }
        if (pos.x + (rect.width * 3.5) >= npc->pos.x &&
        pos.x <= npc->pos.x + ((npc->rect.width - 4) * 3.5) &&
        pos.y <= npc->pos.y + (((npc->rect.height / 2) - 6) * 3.5) &&
        pos.y + (rect.height * 3.5) >= npc->pos.y) {
            return (0);
        }
        npc = npc->next;
    }
    return (1);
}

sfBool is_hitbox(head_t *head, sfVector2f pos)
{
    player_t *player = head->scenes->in_game->player;

    if (pos.x < 0 || pos.y < 0)
        return (0);
    if (pos.x + (player->rect.width * 3.5) >= head->technical->size_map.x - 10)
        return (0);
    if (pos.y + (player->rect.height * 3.5) >= head->technical->size_map.y - 10)
        return (0);
    if (head->scenes->in_game->map->collision[(int)
        ((pos.y + 60) / 64)][(int) ((pos.x + 40) / 64)]
        || head->scenes->in_game->map->collision[(int)
        ((pos.y + 104) / 64)][(int) ((pos.x + 40) / 64)]
        || head->scenes->in_game->map->collision[(int)
        ((pos.y + 60) / 64)][(int) ((pos.x) / 64)]
        || head->scenes->in_game->map->collision[(int)
        ((pos.y + 104) / 64)][(int) ((pos.x) / 64)])
        return (0);
    if (is_hitbox_npc(head, pos) == 0)
        return (0);
    return (1);
}