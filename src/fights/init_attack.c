/*
** EPITECH PROJECT, 2021
** rp
** File description:
** init attack
*/

#include "rpg.h"

void init_attack(fight_t *fight)
{
    fight->attack = malloc(sizeof(duel_attack_t));
    fight->attack->timer = 0;
    fight->attack->attack_bar = create_object_inv(BAR_ATTACK, NULL);
    fight->attack->cursor = create_object_inv(WHITE_CURSOR, NULL);
    fight->attack->run = 1;
    fight->attack->direction = -1;
    fight->attack->activate = 1;
    fight->attack->end = 0;
}