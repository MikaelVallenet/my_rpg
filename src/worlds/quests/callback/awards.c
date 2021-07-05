/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** awards
*/

#include "rpg.h"
#include "../../world.h"

void end_of_main_quest(head_t *head)
{
    if (head->scenes->in_game->boss == 0)
        open_duel_menu(head, DEVIL);
}

void chest_one(head_t *head)
{
    in_game_t *game = head->scenes->in_game;

    add_items(16, game->inventory);
    game->opened_chest[0] = 1;
}

void chest_two(head_t *head)
{
    in_game_t *game = head->scenes->in_game;

    add_items(15, game->inventory);
    game->opened_chest[1] = 1;
}

void chest_three(head_t *head)
{
    in_game_t *game = head->scenes->in_game;

    open_duel_menu(head, "./resources/mobs/mimic.json");
    game->opened_chest[2] = 1;
    game->opened_chest[3] = 1;
}

void chest_four(head_t *head)
{
    in_game_t *game = head->scenes->in_game;

    add_items(14, game->inventory);
    add_items(17, game->inventory);
    game->opened_chest[2] = 1;
    game->opened_chest[3] = 1;
}