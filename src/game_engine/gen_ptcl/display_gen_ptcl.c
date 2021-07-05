/*
** EPITECH PROJECT, 2021
** my rpg
** File description:
** display gen ptcl
*/

#include "rpg.h"

void display_one_ptcl(head_t *head, gen_ptcl_t *gen_ptcl)
{
    sfVector2f gen_pos;

    for (int i = 0; i < gen_ptcl->nb_ptcl; i += 1) {
        gen_pos = sfSprite_getPosition(gen_ptcl->particles[i].particle);
        if (gen_ptcl->particles[i].spawn == 2) {
            continue;
        }
        if (gen_pos.x > 388 && gen_pos.x < 1435 &&
        gen_pos.y > 705 && gen_pos.y < 990) {
            if (gen_ptcl->particles[i].passage == 0)
                gen_ptcl->particles[i].passage = 1;
            sfRenderWindow_drawSprite(head->window,
            gen_ptcl->particles[i].particle, NULL);
        } else if (gen_ptcl->particles[i].passage == 1) {
            gen_ptcl->particles[i].age = gen_ptcl->age_max;
            gen_ptcl->particles[i].position = gen_ptcl->position;
            gen_ptcl->particles[i].opacity = 255;
            gen_ptcl->particles[i].passage = 0;
            direction_gen_ptcl(gen_ptcl, i);
        }
    }
}

void display_gen_ptcl(head_t *head, gen_ptcl_t *gen_ptcl)
{
    while (gen_ptcl != NULL) {
        if (gen_ptcl->start == 1) {
            display_one_ptcl(head, gen_ptcl);
        }
        gen_ptcl = gen_ptcl->next;
    }
}