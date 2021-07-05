/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** quest_npc
*/

#include "rpg.h"
#include "../world.h"

static void apply_npc_conversation(npc_t *npc,
char *npc_name, char *conversation)
{
    for (; npc; npc = npc->next)
        if (my_strcmp(npc->name, npc_name) == 0)
            break;
    if (!npc || npc->is_in_event)
        return;
    npc->filepath_conversation = conversation;
    npc->is_in_event = sfTrue;
}

void set_npc_conversation(head_t *head, quest_t *cur)
{
    char *npc_name;
    char *conversation;
    int current_step = cur->current_step;

    for (int i = 0; cur->step[current_step]->npc[i]; i += 1) {
        npc_name = cur->step[current_step]->npc[i]->npc_name;
        conversation = cur->step[current_step]->npc[i]->conversation;
        apply_npc_conversation(head->scenes->in_game->npc,
        npc_name, conversation);
    }
}