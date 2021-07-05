/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** init_quest_2
*/

#include "rpg.h"
#include "../world.h"

awards_t **init_awards(pars_data_t *data)
{
    int len = pars_obj_len(data) - 1;
    awards_t **awards = malloc(sizeof(awards_t *) * (len + 1));
    pars_data_t *cur;
    pars_data_t *tmp;

    for (int i = 0; i < len; i += 1) {
        cur = data->values.kobj;
        awards[i] = malloc(sizeof(awards_t));
        awards[i]->id = json_search(cur, "id")->values.kint;
        awards[i]->quantity = 1;
        tmp = json_search(cur, "nb");
        if (tmp)
            awards[i]->quantity = tmp->values.kint;
        data = data->next;
    }
    awards[len] = NULL;
    return (awards);
}

quest_event_t **init_event(pars_data_t *data)
{
    int len = pars_obj_len(data) - 1;
    quest_event_t **event = malloc(sizeof(quest_event_t *) * (len + 1));
    pars_data_t *cur;

    for (int i = 0; i < len; i += 1) {
        cur = data->values.kobj;
        event[i] = malloc(sizeof(quest_event_t));
        event[i]->activated = json_search(cur, "activate")->values.kint;
        event[i]->name = json_search(cur, "name")->values.kstr;
        data = data->next;
    }
    event[len] = NULL;
    return (event);
}

quest_objective_t **init_objective(pars_data_t *data)
{
    int len = pars_obj_len(data) - 1;
    quest_objective_t **event = malloc(sizeof(quest_objective_t *)
    * (len + 1));
    pars_data_t *cur;
    pars_data_t *tmp;

    for (int i = 0; i < len; i += 1) {
        cur = data->values.kobj;
        event[i] = malloc(sizeof(quest_objective_t));
        event[i]->nb = 1;
        event[i]->obj_name = json_search(cur, "name")->values.kstr;
        event[i]->cur_nb = 0;
        tmp = json_search(cur, "nb");
        if (tmp)
            event[i]->nb = tmp->values.kint;
        data = data->next;
    }
    event[len] = NULL;
    return (event);
}