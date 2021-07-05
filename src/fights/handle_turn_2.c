/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** handle_turn_2
*/

#include "rpg.h"

void check_duel_ennemy(head_t *head, fight_t *fight)
{
    quest_t *quest = head->scenes->in_game->quests;

    if (!quest || my_strcmp(quest->name, "Une mission impossible.") != 0)
        return;
    if (my_strcmp(fight->ennemy->name, "devil") == 0 &&
    quest->step[quest->current_step]->id == 3) {
        add_to_quest(head->scenes->in_game->quests,
        "Une mission impossible.",
        "Retrouvez et battez le demon des profondeurs.", 1);
        head->scenes->in_game->boss = 1;
        head->scenes->in_game->opened_chest[4] = 1;
    }
    if (my_strcmp(fight->ennemy->name, "wolf") == 0 &&
    quest->step[quest->current_step]->id == 1) 
        add_to_quest(head->scenes->in_game->quests, "Une mission impossible.",
        "Tuer 5 loups", 1);
    if (my_strcmp(fight->ennemy->name, "spirit") == 0 &&
    quest->step[quest->current_step]->id == 2)
        add_to_quest(head->scenes->in_game->quests, "Une mission impossible.",
        "Tuer 5 esprits", 1);
}