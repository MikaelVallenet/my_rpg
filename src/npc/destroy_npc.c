/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** destroy_npc
*/

#include "rpg.h"

void destroy_conversation_data(pars_obj_t *data)
{
    pars_obj_t *temp;

    while (data != NULL) {
        temp = data->next;
        pars_data_destroy(data->data);
        data = temp;
    }
}

void test_npc_function(head_t *head)
{
    return;
}

void destroy_npc(npc_t *npc)
{
    while (npc != NULL) {
        sfSprite_destroy(npc->sprite);
        sfTexture_destroy(npc->texture);
        if (npc->current_conversation_data != NULL)
            destroy_conversation_data(npc->current_conversation_data);
        npc = npc->next;
    }
    npc = NULL;
}