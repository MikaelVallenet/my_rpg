/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** main_window
*/

#include "rpg.h"

static void main_event(head_t *head)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(head->window, &event)) {
        global_event(head, event);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF11)
            switch_full_screen_window(head, head->option);
        if (head->state_2) {
            EVENT_PTR[head->state_2](head, event);
        }
        else
            EVENT_PTR[head->state](head, event);
    }
}

static void main_game(head_t *head)
{
    global_handler(head);
    if (head->state_2)
        SCENES_PTR[head->state_2](head);
    else
        SCENES_PTR[head->state](head);
}

static void main_display(head_t *head)
{
    if (head->state_2)
        DISPLAY_PTR[head->state_2](head);
    else
        DISPLAY_PTR[head->state](head);
    global_display(head);
    if (head->scenes->global->fade_clock != NULL)
        execute_fade_anim(head);
}

int manage_windows(head_t *head)
{
    if (create_windows(head, head->option))
        return (WINDOW_ERROR);
    while (sfRenderWindow_isOpen(head->window)) {
        main_game(head);
        main_display(head);
        main_event(head);
        sfRenderWindow_display(head->window);
        if (head->technical->state_2_ex != 0) {
            DESTROY_PTR[head->technical->state_2_ex](head->scenes);
            head->technical->state_2_ex = 0;
        }
    }
    main_destroy(head);
    return (0);
}