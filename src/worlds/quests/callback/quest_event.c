/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** quest_event
*/

#include "rpg.h"
#include "../../world.h"

void trigger_cave(head_t *head)
{
    if (!head->scenes->in_game->quests || my_strcmp(head->scenes->in_game->
    quests->name, "Une mission impossible.") != 0)
        return;
    if (head->scenes->in_game->quests->step[head->scenes->
    in_game->quests->current_step]->id == 0)
        add_to_quest(head->scenes->in_game->quests, "Une mission impossible.",
        "Trouvez et entrez dans la mine.", 1);
}

void chest_five(head_t *head)
{
    in_game_t *game = head->scenes->in_game;

    add_items(4, game->inventory);
    game->opened_chest[5] = 1;
}