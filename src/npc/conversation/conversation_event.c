/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** conversation_event
*/

#include "rpg.h"

void check_enter_conversation(head_t *head)
{
    if (head->scenes->in_game->current_conversation->start == 2)
        head->scenes->in_game->player->continue_conversation = 1;
    else
        skip_animation_text_scrolling("npc_conversation",
        head->scenes->in_game->current_conversation);
}

void manage_event_conversation(head_t *head, sfEvent event)
{
    if (head->scenes->in_game->player->is_in_conversation == 1)
        if (event.type == sfEvtKeyPressed && event.key.code == 58)
            check_enter_conversation(head);
}

void destroy_conversation(head_t *head, player_t *player)
{
    player->is_in_conversation = 0;
    destroy_object(head->scenes->in_game->face);
    destroy_object(head->scenes->in_game->bubble);
    head->scenes->in_game->bubble = NULL;
    head->scenes->in_game->face = NULL;
    destroy_text_scrolling(head->scenes->in_game->current_conversation);
    head->scenes->in_game->current_conversation = NULL;
    player->continue_conversation = 1;
}

void load_conversation(npc_t *npc)
{
    char *file;

    if (npc->is_in_event == sfTrue)
        file = npc->filepath_conversation;
    else
        file = json_search(npc->data, "file_conversation")->values.kstr;
    npc->current_conversation_data = parser_json(file);
}

void manage_conversation(head_t *head, player_t *player, npc_t *npc)
{
    int in_conversation = player->is_in_conversation;

    if (player->continue_conversation == 1) {
        if (in_conversation == 0) {
            player->is_in_conversation = 1;
            launch_function_conversation(head, player, npc);
        }
        else if (player->is_in_conversation == 1 &&
        npc->current_conversation_data != NULL &&
        head->scenes->in_game->current_conversation->start == 2) {
            continue_function_conversation(head, player, npc);
        }
        if (head->scenes->in_game->current_conversation != NULL &&
        head->scenes->in_game->current_conversation->start == 2 &&
        npc->current_conversation_data == NULL)
            destroy_conversation(head, player);
    }
}