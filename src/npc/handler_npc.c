/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** hanler_npc
*/

#include "rpg.h"

void npc_event(head_t *head, sfEvent event, npc_t *npc)
{

}

void display_npc(head_t *head, npc_t *npc)
{
    while (npc != NULL) {
        sfRenderWindow_drawSprite(head->window, npc->sprite, NULL);
        npc = npc->next;
    }
}

void handler_npc(head_t *head)
{
    npc_t *npc = head->scenes->in_game->npc;
    player_t *player = head->scenes->in_game->player;
    state_npc_t state;

    while (npc != NULL) {
        state = npc->state_move;
        if (is_in_event_zone(player, npc) == sfFalse && state == MOVE) {
            manage_patern(head, npc);
            manage_animated_npc(npc, head);
            move_event_zone(npc);
        }
        if (is_in_event_zone(player, npc) == sfTrue && npc->state_move == MOVE)
            init_first_rect_npc(npc);
        npc = npc->next;
    }
}