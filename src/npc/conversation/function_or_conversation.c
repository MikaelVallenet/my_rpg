/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** function_or_conversation
*/

#include "rpg.h"

void launch_function_conversation(head_t *head, player_t *player, npc_t *npc)
{
    pars_data_t *data;

    if (npc->current_conversation_data == NULL)
        load_conversation(npc);
    data = json_search(npc->current_conversation_data->data, "function");
    if (data)
        if (data->values.kint == 1)
            launch_npc_function(head, player, npc);
    if (npc->current_conversation_data != NULL)
        launch_first_conversation(head, player, npc);
}

void continue_function_conversation(head_t *head, player_t *player, npc_t *npc)
{
    pars_data_t *data = json_search(npc->current_conversation_data->data,
    "function");

    if (data)
        if (data->values.kint == 1)
            launch_npc_function(head, player, npc);
    if (npc->current_conversation_data != NULL)
        continue_conversation(head, player, npc);
}