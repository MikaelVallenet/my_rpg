/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** global_animation
*/

#include "rpg.h"

void execute_little_fade(head_t *head, global_scene_t *gls)
{
    gls->anim_fade = 1;
    gls->fade_func(head);
}

void execute_fade_anim(head_t *head)
{
    global_scene_t *gls = head->scenes->global;
    sfColor color;

    if (sfClock_getElapsedTime(gls->fade_clock).microseconds > 1000) {
        color = sfSprite_getColor(gls->fader);
        if (gls->anim_fade == 0 && color.a >= 243) {
            execute_little_fade(head, gls);
            head->state = (gls->state + 1 ?: head->state) - (gls->state != -1);
        } else if (gls->anim_fade == 0)
            color.a += 12;
        if (gls->anim_fade == 1 && color.a <= 12) {
            gls->anim_fade = 0;
            sfClock_destroy(gls->fade_clock);
            gls->fade_clock = NULL;
        } else if (gls->anim_fade == 1)
            color.a -= 12;
        sfSprite_setColor(gls->fader, color);
        if (gls->fade_clock != NULL)
            sfClock_restart(gls->fade_clock);
    }
    sfRenderWindow_drawSprite(head->window, gls->fader, NULL);
}

void start_fade_animation(head_t *head, void (*fade_f)(head_t*), state_t state)
{
    global_scene_t *gls = head->scenes->global;

    if (gls->fade_clock != NULL)
        return;
    gls->fade_clock = sfClock_create();
    gls->fade_func = fade_f ?: INIT_PTR[state];
    gls->state = -1;
    if (fade_f == NULL)
        gls->state = state;
}