/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function for setting button
*/

#include "rpg.h"

void reduce_sound_volume_setting(head_t *head, button_t *button)
{
    float volume = sfSound_getVolume(head->res->sfx->click_sound);
    float new_volume = volume - 10.0;

    if (volume < 0.0)
        return;
    if (new_volume <= 0) {
        new_volume = 0;
        set_volume(head, new_volume);
        update_button_on_off_sound(head,
        head->scenes->setting_menu->on_off_sound);
    }
    else
        set_volume(head, new_volume);
    if (head->option->sound_volume > 10.0)
        head->option->sound_volume = new_volume;
    update_bar_sound(head, head->scenes->setting_menu->sound_bar);
}

void quit_setting(head_t *head, button_t *button)
{
    start_fade_animation(head, NULL, STATE_MENU);
}

void switch_fullscreen_setting(head_t *head, button_t *button)
{
    if (head->option->fullscreen) {
        sfTexture_destroy(button->texture);
        button->texture =
        sfTexture_createFromFile("assets/buttons/button_off.png", NULL);
        sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    }
    else {
        sfTexture_destroy(button->texture);
        button->texture =
        sfTexture_createFromFile("assets/buttons/button_on.png", NULL);
        sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    }
    switch_full_screen_window(head, head->option);
}