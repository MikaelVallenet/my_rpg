/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function for setting button
*/

#include "rpg.h"

void on_off_music_setting(head_t *head, button_t *button)
{
    if (sfMusic_getVolume(head->res->music->music) > 0.0) {
        sfTexture_destroy(button->texture);
        button->texture =
        sfTexture_createFromFile("assets/buttons/button_off.png", NULL);
        sfSprite_setTexture(button->sprite, button->texture, sfTrue);
        sfMusic_setVolume(head->res->music->music, 0.0);
    }
    else {
        sfTexture_destroy(button->texture);
        button->texture =
        sfTexture_createFromFile("assets/buttons/button_on.png", NULL);
        sfSprite_setTexture(button->sprite, button->texture, sfTrue);
        sfMusic_setVolume(head->res->music->music, head->option->music_volume);
    }
    update_bar_music(head, head->scenes->setting_menu->music_bar);
}

void on_off_sound_setting(head_t *head, button_t *button)
{
    if (sfSound_getVolume(head->res->sfx->click_sound) > 0.0) {
        sfTexture_destroy(button->texture);
        button->texture =
        sfTexture_createFromFile("assets/buttons/button_off.png", NULL);
        sfSprite_setTexture(button->sprite, button->texture, sfTrue);
        set_volume(head, 0.0);
    }
    else {
        sfTexture_destroy(button->texture);
        button->texture =
        sfTexture_createFromFile("assets/buttons/button_on.png", NULL);
        sfSprite_setTexture(button->sprite, button->texture, sfTrue);
        set_volume(head, head->option->sound_volume);
    }
    update_bar_sound(head, head->scenes->setting_menu->sound_bar);
}

void raise_music_volume_setting(head_t *head, button_t *button)
{
    float volume = sfMusic_getVolume(head->res->music->music);
    float new_volume = volume + 10;

    if (volume <= 0)
        update_button_on_off_music(head,
        head->scenes->setting_menu->on_off_music);
    if (volume >= 99.0)
        return;
    if (new_volume >= 100.0)
        new_volume = 100.0;
    sfMusic_setVolume(head->res->music->music, new_volume);
    head->option->music_volume = new_volume;
    update_bar_music(head, head->scenes->setting_menu->music_bar);
    update_button_on_off_music(head, head->scenes->setting_menu->on_off_music);
}

void reduce_music_volume_setting(head_t *head, button_t *button)
{
    float volume = sfMusic_getVolume(head->res->music->music);
    float new_volume = volume - 10.0;

    if (volume < 0.0)
        return;
    if (new_volume <= 0) {
        new_volume = 0;
        sfMusic_setVolume(head->res->music->music, new_volume);
        update_button_on_off_music(head,
        head->scenes->setting_menu->on_off_music);
    }
    else
        sfMusic_setVolume(head->res->music->music, new_volume);
    if (head->option->music_volume > 10.0)
        head->option->music_volume = new_volume;
    update_bar_music(head, head->scenes->setting_menu->music_bar);
}

void raise_sound_volume_setting(head_t *head, button_t *button)
{
    float volume = sfSound_getVolume(head->res->sfx->click_sound);
    float new_volume = volume + 10;

    if (volume <= 0)
        update_button_on_off_sound(head,
        head->scenes->setting_menu->on_off_sound);
    if (volume >= 99.0)
        return;
    if (new_volume >= 100.0)
        new_volume = 100.0;
    set_volume(head, new_volume);
    head->option->sound_volume = new_volume;
    update_button_on_off_sound(head, head->scenes->setting_menu->on_off_sound);
    update_bar_sound(head, head->scenes->setting_menu->sound_bar);
}