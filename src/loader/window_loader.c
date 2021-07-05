/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** window_loader
*/

#include "rpg.h"

int create_windows(head_t *head, option_t *option)
{
    sfVideoMode window_mode = option->mode;

    if (option->automatic_resolution == 1) {
        window_mode = *sfVideoMode_getFullscreenModes(NULL);
        option->mode = window_mode;
    }
    head->window = sfRenderWindow_create(window_mode, GAME_NAME,
    sfDefaultStyle, NULL);
    if (head->window == NULL)
        return (EXIT_FAILURE);
    sfRenderWindow_setFramerateLimit(head->window, option->max_fps);
    head->technical->view = sfView_createFromRect((sfFloatRect)
    {0, 0, option->mode.width, option->mode.height});
    sfRenderWindow_setView(head->window, head->technical->view);
    return (0);
}