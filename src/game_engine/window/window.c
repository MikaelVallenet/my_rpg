/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** switch fullscreen
*/

#include "rpg.h"

void create_window_fullscreen(head_t *head, sfVideoMode window_mode)
{
    head->window = sfRenderWindow_create(window_mode,
    GAME_NAME, sfDefaultStyle | sfFullscreen, NULL);
    head->option->fullscreen = 1;
    if (head->state == STATE_SETTING_MENU)
        update_button_fullscreen(head,
        head->scenes->setting_menu->on_off_fullscreen);
    if (head->state_2 == STATE_SETTING_MENU)
        update_button_fullscreen(head,
        head->scenes->setting_menu->on_off_fullscreen);
}

void create_window_no_fullscreen(head_t *head, sfVideoMode window_mode)
{
    head->window = sfRenderWindow_create(window_mode,
    GAME_NAME, sfDefaultStyle, NULL);
    head->option->fullscreen = 0;
    if (head->state == STATE_SETTING_MENU)
        update_button_fullscreen(head,
        head->scenes->setting_menu->on_off_fullscreen);
    if (head->state_2 == STATE_SETTING_MENU)
        update_button_fullscreen(head,
        head->scenes->setting_menu->on_off_fullscreen);
}

void switch_full_screen_window(head_t *head, option_t *option)
{
    sfVideoMode window_mode = option->mode;

    sfRenderWindow_destroy(head->window);
    if (option->automatic_resolution == 1) {
        window_mode = *sfVideoMode_getFullscreenModes(NULL);
        option->mode = window_mode;
    }
    if (head->option->fullscreen == 1)
        create_window_no_fullscreen(head, window_mode);
    else
        create_window_fullscreen(head, window_mode);
    sfRenderWindow_setFramerateLimit(head->window, option->max_fps);
    head->technical->view = sfView_createFromRect((sfFloatRect)
    {0, 0, option->mode.width, option->mode.height});
    sfRenderWindow_setView(head->window, head->technical->view);
}

void update_button_fullscreen(head_t *head, button_t *object)
{
    if (head->option->fullscreen == 1) {
        sfTexture_destroy(object->texture);
        object->texture =
        sfTexture_createFromFile("assets/buttons/button_on.png", NULL);
        sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    }
    else {
        sfTexture_destroy(object->texture);
        object->texture =
        sfTexture_createFromFile("assets/buttons/button_off.png", NULL);
        sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    }
}