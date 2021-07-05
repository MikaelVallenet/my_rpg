/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** init_empty_skill_tree
*/

#include "rpg.h"

static char *EMPTY_SKILL_TREE[9] = {"armor_1", "armor_2",
"armor_3", "damage_1", "damage_2", "damage_3", "speed_1", "speed_2",
"speed_3"};

static pars_data_t *init_obj_skill_tree(pars_data_t *data_player, int i)
{
    data_player->type = kint;
    data_player->values.kint = 0;
    data_player->data_name = EMPTY_SKILL_TREE[i];
    return (data_player);
}

pars_data_t *init_empty_save_skill_tree(pars_data_t *data_player)
{
    data_player->data_name = "skill_tree\0";
    data_player->next = NULL;
    data_player->type = kobj;
    data_player->values.kobj = malloc(sizeof(pars_data_t));
    data_player = data_player->values.kobj;
    data_player->type = kobj;
    data_player->next = NULL;
    data_player->data_name = NULL;
    data_player->values.kobj = malloc(sizeof(pars_data_t));
    data_player = data_player->values.kobj;
    for (int i = 0; i < 9; i++) {
        data_player = init_obj_skill_tree(data_player, i);
        if (i < 8) {
            data_player->next = malloc(sizeof(pars_data_t));
            data_player = data_player->next;
        }
    }
    data_player->next = NULL;
    return (data_player);
}