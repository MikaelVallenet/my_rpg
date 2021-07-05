/*
** EPITECH PROJECT, 2021
** my rpg
** File description:
** methods gen ptcl
*/

#include "rpg.h"

float get_time_gen(gen_ptcl_t *gen_ptcl)
{
    return (sfClock_getElapsedTime(gen_ptcl->clock).microseconds / 1000000.0);
}

gen_ptcl_t *find_gen_ptcl(char *title, gen_ptcl_t *gen_ptcl)
{
    while (gen_ptcl != NULL && my_strcmp(title, gen_ptcl->title) != 0) {
        gen_ptcl = gen_ptcl->next;
    }
    return (gen_ptcl);
}

void start_gen_ptcl(char *title, gen_ptcl_t *gen_ptcl)
{
    gen_ptcl_t *my_gen_ptcl = find_gen_ptcl(title, gen_ptcl);

    if (my_gen_ptcl->start == 0) {
        my_gen_ptcl->start = 1;
        sfClock_destroy(gen_ptcl->clock);
        gen_ptcl->clock = sfClock_create();
    }
}

void stop_gen_ptcl(char *title, gen_ptcl_t *gen_ptcl)
{
    gen_ptcl_t *my_gen_ptcl = find_gen_ptcl(title, gen_ptcl);

    if (my_gen_ptcl->start == 1) {
        my_gen_ptcl->start = 0;
    }
}

void reset_gen_ptcl(char *title, gen_ptcl_t *gen_ptcl)
{
    gen_ptcl_t *my_gen_ptcl = find_gen_ptcl(title, gen_ptcl);

    my_gen_ptcl->time = 0;
    my_gen_ptcl->time_base = 0;
    my_gen_ptcl->start = 1;
    my_gen_ptcl->last_move = 0;
    for (int i = 0; i < my_gen_ptcl->nb_ptcl; i += 1) {
        my_gen_ptcl->particles[i].spawn = 1;
        my_gen_ptcl->particles[i].opacity = 255;
        direction_gen_ptcl(gen_ptcl, i);
        my_gen_ptcl->particles[i].age = my_gen_ptcl->age_max;
        my_gen_ptcl->particles[i].position = my_gen_ptcl->position;
    }
}