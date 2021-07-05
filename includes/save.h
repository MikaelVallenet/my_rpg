/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** save
*/

#ifndef SAVE_H_
#define SAVE_H_

#include "rpg.h"

// FUNCTION //
void save_stat_player(head_t *head);
void init_empty_save_inventory(pars_data_t *data_player);
pars_data_t *init_empty_save_skill_tree(pars_data_t *data_player);


#endif /* !SAVE_H_ */