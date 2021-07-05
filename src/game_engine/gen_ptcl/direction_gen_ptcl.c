/*
** EPITECH PROJECT, 2021
** my rpg
** File description:
** direction gen ptcl
*/

#include "rpg.h"

static void direction_gen_ptcl_north_south(gen_ptcl_t *gen_ptcl, int i)
{
    if (gen_ptcl->direction.north == 1&& gen_ptcl->direction.south == 1) {
        gen_ptcl->particles[i].step_y = mrand() % gen_ptcl->speed_max;
        if (mrand() % 2 == 0)
            gen_ptcl->particles[i].step_y *= - 1;
    }
    if (gen_ptcl->direction.north == 1 && gen_ptcl->direction.south != 1) {
        gen_ptcl->particles[i].step_y = (mrand() % gen_ptcl->speed_max) * -1;
    }
    if (gen_ptcl->direction.north != 1 && gen_ptcl->direction.south == 1) {
        gen_ptcl->particles[i].step_y = mrand() % gen_ptcl->speed_max;
    }
}

void direction_gen_ptcl(gen_ptcl_t *gen_ptcl, int i)
{
    if (gen_ptcl->direction.est == 1 && gen_ptcl->direction.west == 1) {
        gen_ptcl->particles[i].step_x = mrand() % gen_ptcl->speed_max;
        if (mrand() % 2 == 0)
            gen_ptcl->particles[i].step_x *= - 1;
    }
    if (gen_ptcl->direction.est == 1 && gen_ptcl->direction.west != 1) {
        gen_ptcl->particles[i].step_x = mrand() % gen_ptcl->speed_max;
    }
    if (gen_ptcl->direction.est != 1 && gen_ptcl->direction.west == 1) {
        gen_ptcl->particles[i].step_x = (mrand() % gen_ptcl->speed_max) * -1;
    }
    direction_gen_ptcl_north_south(gen_ptcl, i);
}