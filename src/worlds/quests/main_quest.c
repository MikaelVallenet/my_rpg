/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** main_quest
*/

#include "rpg.h"
#include "../world.h"

static void quest_awards(in_game_t *game, quest_t *quest)
{
    for (int i = 0; quest->awards[i]; i += 1) {
        for (int j = 0; j < quest->awards[i]->quantity; j += 1)
            add_items(quest->awards[i]->id, game->inventory);
    }
}

static void reset_npc(npc_t *npc)
{
    for (; npc; npc = npc->next) {
        npc->is_in_event = sfFalse;
        npc->filepath_conversation = NULL;
    }
}

static void verify_quest(head_t *head, in_game_t *game, quest_t *quest)
{
    quest_step_t *step = quest->step[quest->current_step];
    quest_t *next = game->quests->next;
    int i = 0;

    for (; step->objective[i] &&
    step->objective[i]->nb <= step->objective[i]->cur_nb; i += 1);
    if (!step->objective[i]) {
        quest->current_step += 1;
        if (!quest->step[quest->current_step]) {
            reset_npc(game->npc);
            quest_awards(game, quest);
            destroy_quest(quest);
            game->quests = next;
        }
    }
}

int add_to_quest(quest_t *quest,
char *quest_name, char *objective_name, int nb)
{
    quest_t *cur = quest;
    int i = 0;

    while (cur && my_strcmp(cur->name, quest_name))
        cur = cur->next;
    if (!cur)
        return (0);
    for (; cur->step[cur->current_step]
    ->objective[i] && my_strcmp(cur->step[cur->current_step]
    ->objective[i]->obj_name, objective_name); i += 1);
    cur->step[cur->current_step]->objective[i]->cur_nb += nb;
    return (0);
}

void main_quest(head_t *head, in_game_t *game, quest_t *quest)
{
    quest_t *cur = quest;

    for (; cur; cur = cur->next) {
        set_npc_conversation(head, cur);
        verify_quest(head, game, cur);
    }
}