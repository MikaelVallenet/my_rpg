/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** init_npc
*/

#include "rpg.h"

npc_t *get_last_npc(npc_t *list)
{
    while (list->next != NULL)
        list = list->next;
    return (list);
}

void init_first_rect_npc(npc_t *npc)
{
    sfIntRect rect = {0, 0, 16, 32};

    sfSprite_setTextureRect(npc->sprite, rect);
    npc->rect = rect;
    npc->orientation = DOWN;
}

void init_position_npc(head_t *head, npc_t *npc, pars_data_t *data)
{
    sfVector2f pos_spaw;

    pos_spaw.x = json_search(data, "pos_x")->values.kint;
    pos_spaw.y = json_search(data, "pos_y")->values.kint;
    npc->pos = pos_spaw;
    sfSprite_setPosition(npc->sprite, pos_spaw);
}

void init_npc_aux(pars_data_t *data, npc_t *npc)
{
    sfIntRect aera = {0, 0, 64, 128};

    aera.top = json_search(data, "top_rect")->values.kint;
    aera.left = json_search(data, "left_rect")->values.kint;
    npc->texture = sfTexture_createFromFile(
    json_search(data, "image")->values.kstr, &aera);
    sfSprite_setTexture(npc->sprite, npc->texture, sfFalse);
    sfSprite_setScale(npc->sprite, (sfVector2f){3.5, 3.5});
    npc->size_texture = sfTexture_getSize(npc->texture);
    npc->name = json_search(data, "name")->values.kstr;
    npc->filepath_conversation = NULL;
}

void init_npc(head_t *head, npc_t **list, char *path_files)
{
    npc_t *npc = malloc(sizeof(npc_t));
    pars_data_t *data = parser_json(path_files)->data;
    char *file = json_search(data, "file_conversation")->values.kstr;

    npc->data = data;
    npc->sprite = sfSprite_create();
    init_npc_aux(data, npc);
    init_position_npc(head, npc, data);
    init_first_rect_npc(npc);
    init_event_zone(data, npc);
    init_movement_npc(data, npc);
    npc->last_move = 0;
    npc->scale = 3.5;
    npc->speed = json_search(data, "speed")->values.kint;
    npc->current_conversation_data = parser_json(file);
    npc->is_in_event = sfFalse;
    npc->next = NULL;
    if (*list != NULL)
        get_last_npc(*list)->next = npc;
    else
        *list = npc;
}