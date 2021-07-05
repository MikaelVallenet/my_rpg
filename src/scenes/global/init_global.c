/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** init_global
*/

#include "rpg.h"

void destroy_global_scenes(scenes_t *scene)
{
    if (scene->global == NULL)
        return;
}

void init_global_scenes(head_t *head)
{
    global_scene_t *gls;
    sfColor color;

    gls = malloc(sizeof(global_scene_t));
    gls->fader = sfSprite_create();
    sfSprite_setTexture(gls->fader, head->res->text->fader, sfTrue);
    color = sfSprite_getColor(gls->fader);
    color.a = 0;
    sfSprite_setColor(gls->fader, color);
    gls->fade_clock = NULL;
    gls->anim_fade = 0;
    head->scenes->global = gls;
}