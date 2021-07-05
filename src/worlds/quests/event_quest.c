/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** event_quest
*/

#include "rpg.h"
#include "../world.h"

static const char *CHEST[] = {"CHEST_1", "CHEST_2", "CHEST_3",
"CHEST_4", "StartFight", "CHEST_5", NULL};

int verify_quest_event(head_t *head, quest_t *quest, char *name)
{
    for (int i = 0; (char *) CHEST[i]; i += 1) {
        if (my_strcmp(name, (char *) CHEST[i]) == 0 &&
        head->scenes->in_game->opened_chest[i] == 1) {
            return (0);
        }
    }
    if (!quest)
        return (-1);
    for (int i = 0; quest->step[quest->current_step]->event[i]; i += 1) {
        if (my_strcmp(quest->step[quest->current_step]->event[i]->name,
            name) == 0) {
            return (quest->step[quest->current_step]->event[i]->activated);
        }
    }
    return (-1);
}