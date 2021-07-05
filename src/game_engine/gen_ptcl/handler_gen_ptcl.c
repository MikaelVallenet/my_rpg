/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** handle gen ptcl
*/

#include "rpg.h"

void animation_gen_ptcl(gen_ptcl_t *list_gen_ptcl)
{
    while (list_gen_ptcl != NULL) {
        list_gen_ptcl->gen_ptcl_event(list_gen_ptcl);
        list_gen_ptcl = list_gen_ptcl->next;
    }
}

static void modify_one_ptcl(gen_ptcl_t *gen_ptcl, int i)
{
    int x = gen_ptcl->particles[i].step_x;
    int y = gen_ptcl->particles[i].step_y;
    int slow = gen_ptcl->slow;

    gen_ptcl->particles[i].position.x += x;
    gen_ptcl->particles[i].position.y += y;
    gen_ptcl->particles[i].step_x -= (x > 0) ? slow : -slow;
    gen_ptcl->particles[i].step_y -= (y > 0) ? slow : -slow;
    gen_ptcl->particles[i].age -= 1;
    if (gen_ptcl->particles[i].opacity - gen_ptcl->opacity >= 0) {
        gen_ptcl->particles[i].opacity -= gen_ptcl->opacity;
    }
}

static void handle_one_ptcl(gen_ptcl_t *gen_ptcl, int i)
{
    if (gen_ptcl->particles[i].age == 0 && gen_ptcl->particles[i].spawn == 1) {
        gen_ptcl->particles[i].age = gen_ptcl->age_max;
        gen_ptcl->particles[i].position = gen_ptcl->position;
        gen_ptcl->particles[i].opacity = 255;
        direction_gen_ptcl(gen_ptcl, i);
    }
    else if (gen_ptcl->particles[i].age <= 0 &&
    gen_ptcl->particles[i].spawn == 0)
        gen_ptcl->particles[i].spawn = 2;
    else {
        modify_one_ptcl(gen_ptcl, i);
    }
    sfSprite_setPosition(gen_ptcl->particles[i].particle,
    gen_ptcl->particles[i].position);
    sfSprite_setColor(gen_ptcl->particles[i].particle, (sfColor){255, 255, 255,
    gen_ptcl->particles[i].opacity});
}

static void check_spawn_ptcl(gen_ptcl_t *gen_ptcl)
{
    for (int i = 0; i < gen_ptcl->nb_ptcl; i += 1)
        if (gen_ptcl->particles[i].spawn == 1)
            gen_ptcl->particles[i].spawn = 0;
}

void handler_gen_ptcl(gen_ptcl_t *gen_ptcl)
{
    if (gen_ptcl->start == 1) {
        gen_ptcl->time = gen_ptcl->time_base;
        gen_ptcl->time += get_time_gen(gen_ptcl);
        if (gen_ptcl->max_time != -1 && gen_ptcl->time > gen_ptcl->max_time)
            check_spawn_ptcl(gen_ptcl);
        if (gen_ptcl->max_time != -1 &&
        gen_ptcl->time > gen_ptcl->max_time + 10.0) {
            gen_ptcl->start = 2;
        }
        if (gen_ptcl->time > gen_ptcl-> last_move + gen_ptcl->gen_speed) {
            for (int i = 0; i < gen_ptcl->nb_ptcl; i += 1) {
                handle_one_ptcl(gen_ptcl, i);
            }
            gen_ptcl->last_move = gen_ptcl->time;
        }
    }
    return;
}