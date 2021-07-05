/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** init_quest
*/

#include "rpg.h"
#include "../world.h"
static const char *QUESTS_FILEPATH[] = {"quest.json", "quest.json"};

static quest_npc_t **init_quest_npc(pars_data_t *data)
{
    int len = pars_obj_len(data) - 1;
    quest_npc_t **quest = malloc(sizeof(quest_npc_t *) * (len + 1));
    pars_data_t *cur;
    pars_data_t *tmp;

    for (int i = 0; i < len; i += 1) {
        cur = data->values.kobj;
        quest[i] = malloc(sizeof(quest_npc_t));
        quest[i]->npc_name = json_search(cur, "name")->values.kstr;
        quest[i]->conversation = NULL;
        tmp = json_search(cur, "conversation");
        if (tmp)
            quest[i]->conversation = tmp->values.kstr;
        data = data->next;
    }
    quest[len] = NULL;
    return (quest);
}

static quest_step_t **init_step(pars_data_t *data)
{
    int len = pars_obj_len(data) - 1;
    quest_step_t **step = malloc(sizeof(quest_step_t *) * (len + 1));
    pars_data_t *cur;

    for (int i = 0; i < len; i += 1) {
        cur = data->values.kobj;
        step[i] = malloc(sizeof(quest_step_t));
        step[i]->description = json_search(cur, "description")->values.kstr;
        step[i]->id = json_search(cur, "id")->values.kint;
        step[i]->npc = init_quest_npc(json_search(cur, "npc")->values.kobj);
        step[i]->event = init_event(json_search(cur, "event")->values.kobj);
        step[i]->objective =
        init_objective(json_search(cur, "objective")->values.kobj);
        data = data->next;
    }
    step[len] = NULL;
    return (step);
}

static quest_t *init_quest(pars_data_t *data, int quest_id)
{
    quest_t *quest = malloc(sizeof(quest_t));

    quest->quest_id = quest_id;
    quest->awards_desc = json_search(data, "awards_desc")->values.kstr;
    quest->description = json_search(data, "description")->values.kstr;
    quest->name = json_search(data, "name")->values.kstr;
    quest->value = !(my_strcmp(json_search(data, "value")->values.kstr,
    "main_quest") == 0);
    quest->awards = init_awards(json_search(data, "awards")->values.kobj);
    quest->step = init_step(json_search(data, "step")->values.kobj);
    quest->next = NULL;
    quest->current_step = 0;
    return (quest);
}

quest_t *load_quest(in_game_t *game, int quest_id)
{
    char *filepath = my_strcat(QUEST_FILEPATH, QUESTS_FILEPATH[quest_id]);
    pars_obj_t *obj = parser_json(filepath);
    quest_t *quest = init_quest(obj->data, quest_id);
    quest_t *tmp;

    quest->obj = obj;
    quest->next = NULL;
    if (game->quests == NULL)
        game->quests = quest;
    else {
        for (tmp = game->quests; tmp->next; tmp = tmp->next);
        tmp->next = quest;
    }
    free(filepath);
    return (quest);
}

void load_quest_from_save(head_t *head, in_game_t *game, pars_data_t *data)
{
    quest_t *quest;
    pars_data_t *cur;
    pars_data_t *tmp;

    data = data->values.kobj;
    if (data->data_name != NULL) {
        game->quests = NULL;
        return;
    }
    for (; data; data = data->next) {
        cur = data->values.kobj;
        quest = load_quest(game, json_search(cur, "id")->values.kint);
        quest->current_step = json_search(cur, "step")->values.kint;
        tmp = json_search(cur, "objective")->values.kobj;
        for (int i = 0; tmp; tmp = tmp->next, i += 1)
            quest->step[quest->current_step]->objective[i]->cur_nb =
            tmp->values.kint;
    }
}