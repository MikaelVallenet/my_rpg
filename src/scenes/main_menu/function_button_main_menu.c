/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function for menu button
*/

#include "rpg.h"

void open_setting(head_t *head, button_t *button)
{
    start_fade_animation(head, NULL, STATE_SETTING_MENU);
}

void close_window_2(head_t *head)
{
    sfRenderWindow_close(head->window);
}

void close_window(head_t *head, button_t *button)
{
    start_fade_animation(head, close_window_2, head->state);
}

void switch_sound_menu(head_t *head, button_t *button)
{
    if (sfSound_getVolume(head->res->sfx->click_sound) > 0.0) {
        sfTexture_destroy(button->texture);
        button->texture =
        sfTexture_createFromFile("assets/buttons/sound_off.png", NULL);
        sfSprite_setTexture(button->sprite, button->texture, sfTrue);
        sfSound_setVolume(head->res->sfx->click_sound, 0.0);
    }
    else {
        sfTexture_destroy(button->texture);
        button->texture =
        sfTexture_createFromFile("assets/buttons/sound_on.png", NULL);
        sfSprite_setTexture(button->sprite, button->texture, sfTrue);
        sfSound_setVolume(head->res->sfx->click_sound,
        head->option->music_volume);
    }
}

void switch_music_menu(head_t *head, button_t *button)
{
    if (sfMusic_getVolume(head->res->music->music) > 0.0) {
        sfTexture_destroy(button->texture);
        button->texture =
        sfTexture_createFromFile("assets/buttons/music_off.png", NULL);
        sfSprite_setTexture(button->sprite, button->texture, sfTrue);
        sfMusic_setVolume(head->res->music->music, 0.0);
    }
    else {
        sfTexture_destroy(button->texture);
        button->texture =
        sfTexture_createFromFile("assets/buttons/music_on.png", NULL);
        sfSprite_setTexture(button->sprite, button->texture, sfTrue);
        sfMusic_setVolume(head->res->music->music, head->option->music_volume);
    }
}