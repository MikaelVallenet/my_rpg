/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init gen mobs
*/

#include "rpg.h"

void init_gen_mobs(head_t *head, fight_t *fight)
{
    if (my_strcmp("wolf", fight->ennemy->name) == 0) {
        create_gen_ptcl(GEN_UP, &head->scenes->duel_scene->gen_ptcl);
        create_gen_ptcl(GEN_LEFT, &head->scenes->duel_scene->gen_ptcl);
        create_gen_ptcl(GEN_RIGHT, &head->scenes->duel_scene->gen_ptcl);
        create_gen_ptcl(GEN_DOWN, &head->scenes->duel_scene->gen_ptcl);
    }
    if (my_strcmp("spirit", fight->ennemy->name) == 0) {
        create_gen_ptcl(GEN_UP_SPIRIT, &head->scenes->duel_scene->gen_ptcl);
        create_gen_ptcl(GEN_LEFT_SPIRIT, &head->scenes->duel_scene->gen_ptcl);
        create_gen_ptcl(GEN_RIGHT_SPIRIT, &head->scenes->duel_scene->gen_ptcl);
        create_gen_ptcl(GEN_DOWN_SPIRIT, &head->scenes->duel_scene->gen_ptcl);
    }
    if (my_strcmp("devil", fight->ennemy->name) == 0 ||
    my_strcmp("mimic", fight->ennemy->name) == 0) {
        create_gen_ptcl(GEN_UP_BOSS, &head->scenes->duel_scene->gen_ptcl);
        create_gen_ptcl(GEN_LEFT_BOSS, &head->scenes->duel_scene->gen_ptcl);
        create_gen_ptcl(GEN_RIGHT_BOSS, &head->scenes->duel_scene->gen_ptcl);
        create_gen_ptcl(GEN_DOWN_BOSS, &head->scenes->duel_scene->gen_ptcl);
    }
}