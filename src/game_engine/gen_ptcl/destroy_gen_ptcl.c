/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** destroy gen ptcl
*/

#include "rpg.h"

void destroy_gen_ptcl(gen_ptcl_t *list_gen_ptcl)
{
    gen_ptcl_t* gen_ptcl;

    while (list_gen_ptcl != NULL) {
        if (list_gen_ptcl->audio != 0) {
            sfSound_destroy(list_gen_ptcl->sound);
            sfSoundBuffer_destroy(list_gen_ptcl->soundbuffer);
        }
        for (int i = 0; i < list_gen_ptcl->nb_ptcl; i += 1)
            sfSprite_destroy(list_gen_ptcl->particles[i].particle);
        free(list_gen_ptcl->particles);
        sfTexture_destroy(list_gen_ptcl->texture);
        sfClock_destroy(list_gen_ptcl->clock);
        gen_ptcl = list_gen_ptcl;
        list_gen_ptcl = gen_ptcl->next;
        free(gen_ptcl);
    }
    list_gen_ptcl = NULL;
}