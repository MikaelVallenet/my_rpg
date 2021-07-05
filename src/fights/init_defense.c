/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init defense
*/

#include "rpg.h"

void init_defense(fight_t *fight, head_t *head)
{
    fight->defense = malloc(sizeof(duel_defense_t));
    fight->defense->timer = 0;
    fight->defense->timer2 = 0;
    fight->defense->arena = create_object_inv(ARENA, NULL);
    fight->defense->my_ptcl = create_object_inv(PLAYER_PTCL, NULL);
    fight->defense->activate = 0;
    fight->defense->keys = (list_key_t){UNPRESS, UNPRESS, UNPRESS, UNPRESS};
    fight->defense->direction_left = 1;
    fight->defense->direction_up = -1;
    fight->defense->god = 0;
    fight->defense->end = 0;
}