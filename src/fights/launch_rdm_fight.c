/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** launch rdm fight
*/

#include "rpg.h"

static void launch_rdm_fight_aux(head_t *head, int fight, int i)
{
    if (my_strcmp("./resources/maps/the_deep_cave.json",
    head->scenes->in_game->map->name) == 0 && fight == 0) {
        if (i == 0)
            open_duel_menu(head, SPIRITMAGE);
        else
            open_duel_menu(head, SPIRITATTACK);
    }
}

void launch_rdm_fight(head_t *head)
{
    int fight = mrand() % 387;
    int i = mrand() % 2;

    if (my_strcmp("./resources/maps/the_cave.json",
    head->scenes->in_game->map->name) == 0 && fight == 0) {
        if (i == 0) {
            open_duel_menu(head, WOLF);
        } else {
            open_duel_menu(head, WOLFTANK);
        }
    }
    launch_rdm_fight_aux(head, fight, i);
}