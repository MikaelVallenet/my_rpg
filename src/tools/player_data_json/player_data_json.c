/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** player_data_json
*/

#include "rpg.h"

static char *EMPTY_DATA_PLAYER[14] = {"character", "health",
"health_max", "damage", "armor", "level", "xp", "xp_next_level",
"time_played", "progression", "pos_x", "pos_y", "nb_star", "speed"};

static const int EMPTY_STAT_PLAYER[13] = {100, 100, 10, 11, 1, 0,
100, 0, 0, 600, 500, 0, 5};

static pars_data_t *quest_data_init(pars_data_t *data)
{
    data->next = malloc(sizeof(pars_data_t));
    data = data->next;
    data->data_name = my_strdup("quests");
    data->type = kobj;
    data->next = NULL;
    data->values.kobj = save_quests_progress(NULL);
    return (data);
}

pars_data_t *init_map_path(pars_data_t *data_player)
{
    data_player->next = malloc(sizeof(pars_data_t));
    data_player = data_player->next;
    data_player->data_name = "map";
    data_player->type = kstr;
    data_player->values.kstr = "./resources/maps/house_4.json";
    data_player->next = NULL;
    return (data_player);
}

pars_data_t *init_player_data_json(char *name)
{
    pars_data_t *data_player = malloc(sizeof(pars_data_t));
    pars_data_t *first = data_player;

    data_player->type = kstr;
    data_player->values.kstr = name;
    data_player->data_name = "character";
    for (int i = 1; i < 14; i++) {
        data_player->next = malloc(sizeof(pars_data_t));
        data_player = data_player->next;
        data_player->type = kint;
        data_player->values.kint = EMPTY_STAT_PLAYER[i - 1];
        data_player->data_name = EMPTY_DATA_PLAYER[i];
    }
    data_player = init_map_path(data_player);
    data_player = quest_data_init(data_player);
    data_player->next = malloc(sizeof(pars_data_t));
    init_empty_save_inventory(data_player);
    data_player->next->next = malloc(sizeof(pars_data_t));
    data_player = data_player->next->next;
    init_empty_save_skill_tree(data_player);
    return (first);
}