/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** load_conversation
*/

#include "rpg.h"

void launch_first_conversation(head_t *head, player_t *player, npc_t *npc)
{
    pars_data_t *data_2 = npc->current_conversation_data->data;
    pars_obj_t *temp;
    char *setence = json_search(data_2, "string")->values.kstr;
    text_data_scrolling_t data = NPC_CONVERSATION;

    data.origin_str = setence;
    create_text_scrolling(head, data,
    &head->scenes->in_game->current_conversation);
    start_text_scrolling("npc_conversation",
    head->scenes->in_game->current_conversation);
    head->scenes->in_game->bubble = NULL;
    create_object(BUBBLE, &head->scenes->in_game->bubble);
    load_face_conversation(head, npc, player);
    player->continue_conversation = 0;
    temp = npc->current_conversation_data->next;
    pars_data_destroy(npc->current_conversation_data->data);
    npc->current_conversation_data = temp;
}

void continue_conversation(head_t *head, player_t *player, npc_t *npc)
{
    char *setence;
    text_data_scrolling_t data = NPC_CONVERSATION;
    pars_obj_t *temp;

    setence =
    json_search(npc->current_conversation_data->data, "string")->values.kstr;
    data.origin_str = setence;
    reset_text_scrolling("npc_conversation",
    head->scenes->in_game->current_conversation, data.origin_str);
    start_text_scrolling("npc_conversation",
    head->scenes->in_game->current_conversation);
    load_face_conversation(head, npc, player);
    player->continue_conversation = 0;
    temp = npc->current_conversation_data->next;
    pars_data_destroy(npc->current_conversation_data->data);
    npc->current_conversation_data = temp;
}