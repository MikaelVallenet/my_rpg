/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** player_data_json_aux
*/

#include "rpg.h"

static pars_data_t *init_id_item(pars_data_t *data_player)
{
    data_player->data_name = "id\0";
    data_player->type = kint;
    data_player->values.kint = 0;
    data_player->next = malloc(sizeof(pars_data_t));
    data_player = data_player->next;
    return (data_player);
}

static pars_data_t *init_nb_item(pars_data_t *data_player)
{
    data_player->data_name = "nb\0";
    data_player->type = kint;
    data_player->values.kint = 0;
    data_player->next = malloc(sizeof(pars_data_t));
    data_player = data_player->next;
    return (data_player);
}

static pars_data_t *init_idx_item(pars_data_t *data_player, int i)
{
    data_player->data_name = "idx\0";
    data_player->type = kint;
    data_player->values.kint = i;
    data_player->next = NULL;
    return (data_player);
}

static pars_data_t *init_new_object(pars_data_t *start_array)
{
    start_array->type = kobj;
    start_array->values.kobj = malloc(sizeof(pars_data_t));
    start_array->data_name = NULL;
    return (start_array);
}

void init_empty_save_inventory(pars_data_t *data_player)
{
    pars_data_t *start_array;

    data_player = data_player->next;
    data_player->data_name = "inventory\0";
    data_player->next = NULL;
    data_player->type = kobj;
    data_player->values.kobj = malloc(sizeof(pars_data_t));
    data_player = data_player->values.kobj;
    start_array = data_player;
    for (int i = 0; i < 32; i++) {
        start_array = init_new_object(start_array);
        data_player = start_array->values.kobj;
        data_player = init_id_item(data_player);
        data_player = init_nb_item(data_player);
        data_player = init_idx_item(data_player, i);
        if (i < 31) {
            start_array->next = malloc(sizeof(pars_data_t));
            start_array = start_array->next;
        }
    }
    start_array->next = NULL;
}