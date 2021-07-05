/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** lvl up
*/

#include "rpg.h"

void reset_text_lvl(void)
{
    return;
}

void handle_text_lvl(void)
{
    return;
}

void text_lvl(void)
{
    return;
}

void lvl_up(player_t *player)
{
    if (player->p_stat.xp >= player->p_stat.nxt_lvl) {
        player->p_stat.xp -= player->p_stat.nxt_lvl;
        player->p_stat.nxt_lvl *= player->p_stat.coef;
        player->p_stat.lvl += 1;
        player->p_stat.damage += 1;
        player->p_stat.armor += 1;
        player->p_stat.health += 15;
        player->p_stat.health_max += 15;
        player->p_stat.nb_star += 1;
    }
}