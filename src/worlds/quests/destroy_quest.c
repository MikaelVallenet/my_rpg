/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** destroy_quest
*/

#include "rpg.h"
#include "../world.h"

static void destroy_inside(quest_step_t **step, int i)
{
    free(step[i]->description);
    for (int j = 0; step[i]->event[j]; j += 1) {
        free(step[i]->event[j]->name);
        free(step[i]->event[j]);
    }
    for (int j = 0; step[i]->npc[j]; j += 1) {
        free(step[i]->npc[j]->conversation);
        free(step[i]->npc[j]->npc_name);
        free(step[i]->npc[j]);
    }
    for (int j = 0; step[i]->objective[j]; j += 1) {
        free(step[i]->objective[j]->obj_name);
        free(step[i]->objective[j]);
    }
    free(step[i]);
}

void destroy_quest(quest_t *quest)
{
    quest_step_t **step = quest->step;

    for (int i = 0; quest->awards[i]; i += 1)
        free(quest->awards[i]);
    for (int i = 0; step[i]; i += 1) {
        destroy_inside(step, i);
    }
    free(quest->step);
    free(quest->awards);
}