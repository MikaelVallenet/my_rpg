/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** event_npc
*/

#include "rpg.h"

void manage_event_npc(head_t *head, player_t *player, npc_t *npc)
{
    char *event_type = json_search(npc->data, "event_type")->values.kstr;

    if (my_strcmp(event_type, "conversation") == 0) {
        manage_conversation(head, player, npc);
    }
}

void check_interaction_npc_aux(head_t *head, player_t *player, npc_t *npc)
{
    if (player->is_in_conversation == 0) {
        head->scenes->in_game->event_text_display = 1;
    }
    if (head->scenes->in_game->event_text_display) {
        if (head->event->key_input == sfKeyE) {
            head->scenes->in_game->event_text_display = 0;
            manage_event_npc(head, player, npc);
        }
    }
    if (player->is_in_conversation == 1)
        manage_event_npc(head, player, npc);
}

void check_interaction_npc(head_t *head, npc_t *npc)
{
    player_t *player = head->scenes->in_game->player;

    while (npc != NULL) {
        if (is_in_event_zone(player, npc)) {
            check_interaction_npc_aux(head, player, npc);
        }
        npc = npc->next;
    }
}