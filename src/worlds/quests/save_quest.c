/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** save_quest
*/

#include "rpg.h"
#include "../world.h"

static void fill_content(pars_data_t *obj, char *data_name, int value)
{
    obj->data_name = my_strdup(data_name);
    obj->type = kint;
    obj->values.kint = value;
    obj->next = NULL;
}

static void fill_array(pars_data_t *data, quest_t *quest)
{
    quest_step_t *step = quest->step[quest->current_step];
    pars_data_t *cur;

    for (int i = 0; step->objective[i]; i += 1) {
        data->values.kint = step->objective[i]->cur_nb;
        data->data_name = NULL;
        data->type = kint;
        data->next = malloc(sizeof(pars_data_t));
        cur = data;
        data = data->next;
    }
    free(data);
    cur->next = NULL;
}

static void save_content(quest_t *quest, pars_data_t *obj)
{
    fill_content(obj, "id", quest->quest_id);
    obj->next = malloc(sizeof(pars_data_t));
    obj = obj->next;
    fill_content(obj, "step", quest->current_step);
    obj->next = malloc(sizeof(pars_data_t));
    obj = obj->next;
    obj->data_name = my_strdup("objective");
    obj->values.kobj = malloc(sizeof(pars_data_t));
    obj->type = kobj;
    fill_array(obj->values.kobj, quest);
    obj->next = NULL;
}

static pars_data_t *null_quest(pars_data_t *data)
{
    data->data_name = my_strdup("NO_QUEST");
    data->next = NULL;
    data->type = kint;
    data->values.kint = 0;
    return (data);
}

pars_data_t *save_quests_progress(quest_t *quest)
{
    pars_data_t *data = malloc(sizeof(pars_data_t));
    pars_data_t *first = data;

    if (quest == NULL) {
        return (null_quest(data));
    }
    for (; quest; quest = quest->next) {
        data->type = kobj;
        data->data_name = NULL;
        data->values.kobj = malloc(sizeof(pars_data_t));
        save_content(quest, data->values.kobj);
        if (!quest->next)
            data->next = NULL;
        else {
            data->next = malloc(sizeof(pars_data_t));
            data = data->next;
        }
    }
    return (first);
}