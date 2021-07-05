/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** gen particle
*/

#include "rpg.h"

static gen_ptcl_t *get_last_gen_ptcl(gen_ptcl_t *first_gen_ptcl)
{
    while ((first_gen_ptcl)->next != NULL)
        first_gen_ptcl = (first_gen_ptcl)->next;
    return (first_gen_ptcl);
}

static void gen_all_particles(gen_ptcl_t *new_gen_ptcl)
{
    new_gen_ptcl->particles = malloc(sizeof(ptcl_t) * new_gen_ptcl->nb_ptcl);
    new_gen_ptcl->texture =
    sfTexture_createFromFile(new_gen_ptcl->path_texture, NULL);
    for (int i = 0; i < new_gen_ptcl->nb_ptcl; i += 1) {
        new_gen_ptcl->particles[i].particle = sfSprite_create();
        new_gen_ptcl->particles[i].position = new_gen_ptcl->position;
        new_gen_ptcl->particles[i].spawn = 1;
        new_gen_ptcl->particles[i].opacity = 255;
        direction_gen_ptcl(new_gen_ptcl, i);
        new_gen_ptcl->particles[i].age = mrand() % new_gen_ptcl->age_max;
        sfSprite_setTexture(new_gen_ptcl->particles[i].particle,
        new_gen_ptcl->texture, sfTrue);
        sfSprite_setPosition(new_gen_ptcl->particles[i].particle,
        new_gen_ptcl->particles[i].position);
        sfSprite_setScale(new_gen_ptcl->particles[i].particle,
        new_gen_ptcl->scale);
        new_gen_ptcl->particles[i].passage = 0;
    }
}

static void init_param_gen_ptcl(gen_ptcl_data_t data, gen_ptcl_t *new_gen_ptcl)
{
    new_gen_ptcl->title = data.title;
    new_gen_ptcl->path_texture = data.path_texture;
    new_gen_ptcl->path_sound = data.path_sound;
    new_gen_ptcl->nb_ptcl = data.nb_ptcl;
    new_gen_ptcl->max_time = data.max_time;
    new_gen_ptcl->gen_speed = data.gen_speed;
    new_gen_ptcl->position = data.position;
    new_gen_ptcl->scale = data.scale;
    new_gen_ptcl->age_max = data.age_max;
    new_gen_ptcl->direction = data.direction;
    new_gen_ptcl->slow = data.slow;
    new_gen_ptcl->opacity = data.opacity;
    if (new_gen_ptcl->path_sound == NULL)
        new_gen_ptcl->audio = 0;
    else {
        new_gen_ptcl->sound = sfSound_create();
        new_gen_ptcl->soundbuffer =
        sfSoundBuffer_createFromFile(new_gen_ptcl->path_sound);
        sfSound_setBuffer(new_gen_ptcl->sound, new_gen_ptcl->soundbuffer);
    }
}

void init_timer_gen_ptcl(gen_ptcl_t *new_gen_ptcl)
{
    new_gen_ptcl->clock = sfClock_create();
    new_gen_ptcl->time = 0;
    new_gen_ptcl->time_base = 0;
    new_gen_ptcl->start = 0;
    new_gen_ptcl->last_move = 0;
}

void create_gen_ptcl(gen_ptcl_data_t data, gen_ptcl_t **list_gen_ptcl)
{
    gen_ptcl_t *new_gen_ptcl = malloc(sizeof(gen_ptcl_t));

    new_gen_ptcl->audio = 0;
    new_gen_ptcl->speed_max = data.speed_max;
    init_param_gen_ptcl(data, new_gen_ptcl);
    gen_all_particles(new_gen_ptcl);
    init_timer_gen_ptcl(new_gen_ptcl);
    new_gen_ptcl->gen_ptcl_event = &handler_gen_ptcl;
    new_gen_ptcl->next = NULL;
    if (*list_gen_ptcl != NULL)
        get_last_gen_ptcl(*list_gen_ptcl)->next = new_gen_ptcl;
    else
        *list_gen_ptcl = new_gen_ptcl;
}