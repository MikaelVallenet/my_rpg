/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** init_skill_tree_player
*/

#include "rpg.h"

void init_skill_tree_player(head_t *head, player_t *player)
{
    pars_data_t *obj;

    obj = json_search(player->stat_json->data, "skill_tree");
    player->skill_tree.armor_1 =
    json_search(obj->values.kobj->values.kobj, "armor_1\0")->values.kint;
    player->skill_tree.armor_2 =
    json_search(obj->values.kobj->values.kobj, "armor_2\0")->values.kint;
    player->skill_tree.armor_3 =
    json_search(obj->values.kobj->values.kobj, "armor_3\0")->values.kint;
    player->skill_tree.damage_1 =
    json_search(obj->values.kobj->values.kobj, "damage_1\0")->values.kint;
    player->skill_tree.damage_2 =
    json_search(obj->values.kobj->values.kobj, "damage_2\0")->values.kint;
    player->skill_tree.damage_3 =
    json_search(obj->values.kobj->values.kobj, "damage_3\0")->values.kint;
    player->skill_tree.speed_1 =
    json_search(obj->values.kobj->values.kobj, "speed_1\0")->values.kint;
    player->skill_tree.speed_2 =
    json_search(obj->values.kobj->values.kobj, "speed_2\0")->values.kint;
    player->skill_tree.speed_3 =
    json_search(obj->values.kobj->values.kobj, "speed_3\0")->values.kint;
}