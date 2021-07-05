/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** function_npc
*/

#include "rpg.h"

static const void (*CONVERSATION_EVENT[])(head_t *head) =
{test_npc_function, give_sword};

void launch_npc_function(head_t *head, player_t *player, npc_t *npc)
{
    pars_obj_t *temp = npc->current_conversation_data->next;
    int id;

    id = json_search(npc->current_conversation_data->data,
    "function_id")->values.kint;
    CONVERSATION_EVENT[id](head);
    pars_data_destroy(npc->current_conversation_data->data);
    npc->current_conversation_data = temp;
}