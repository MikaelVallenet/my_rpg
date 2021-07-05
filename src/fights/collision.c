/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** collision
*/

#include "rpg.h"

void update_god_mod(fight_t *fight, float time)
{
    if (fight->defense->god != 0 && time - 0.1 > fight->defense->timer)
        fight->defense->god = 1;
    if (fight->defense->god != 0 && time - 0.2 > fight->defense->timer)
        fight->defense->god = 2;
    if (fight->defense->god != 0 && time - 0.3 > fight->defense->timer)
        fight->defense->god = 1;
    if (fight->defense->god != 0 && time - 0.4 > fight->defense->timer)
        fight->defense->god = 2;
    if (fight->defense->god != 0 && time - 0.5 > fight->defense->timer)
        fight->defense->god = 1;
    if (fight->defense->god != 0 && time - 0.6 > fight->defense->timer)
        fight->defense->god = 2;
    if (fight->defense->god != 0 && time - 0.7 > fight->defense->timer)
        fight->defense->god = 1;
    if (fight->defense->god != 0 && time - 0.8 > fight->defense->timer)
        fight->defense->god = 0;
}

void check_impact2(head_t *head, ptcl_t particle, fight_t *fight, float time)
{
    sfVector2f player_pos =
    sfSprite_getPosition(fight->defense->my_ptcl->sprite);
    sfVector2f ptcl_pos = particle.position;

    if (!((player_pos.x >= ptcl_pos.x + 32) ||
    (player_pos.x + 32 <= ptcl_pos.x) ||
    (player_pos.y >= ptcl_pos.y + 32) ||
    (player_pos.y + 32 <= ptcl_pos.y))) {
        sfSound_play(head->res->sfx->defend_sound);
        fight->player->health -= (fight->ennemy->damage -
        fight->player->armor / 10);
        fight->defense->god = 2;
        fight->defense->timer = time;
    }
}

void handle_collision(head_t *head, fight_t *fight, gen_ptcl_t *lis, float tim)
{
    gen_ptcl_t *gen = lis;

    update_god_mod(fight, tim);
    update_bar(fight->player->health_bar,
    (fight->player->health * 100) / fight->player->health_max);
    while (gen != NULL) {
        for (int i = 0; i < gen->nb_ptcl; i += 1) {
            if (fight->defense->god != 0)
                return;
            check_impact2(head, gen->particles[i], fight, tim);
        }
        gen = gen->next;
    }
}