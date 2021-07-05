/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** manage event in game
*/

#include "rpg.h"

void manage_event_button_in_game(head_t *head, sfEvent event)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(head->window);
    sfVector2f pos_mouse;
    const sfView *view = sfRenderWindow_getView(head->window);

    p_mouse = sfMouse_getPositionRenderWindow(head->window);
    pos_mouse = sfRenderWindow_mapPixelToCoords(head->window, p_mouse, view);
    if (event.type == sfEvtClosed) {
        DESTROY_PTR[head->state](head->scenes);
        sfRenderWindow_close(head->window);
        return;
    }
    is_hover_button(head->scenes->in_game->button, pos_mouse);
    if (event.type == sfEvtMouseButtonPressed && event.type != sfEvtClosed)
        is_clic_button(head, head->scenes->in_game->button, pos_mouse);
    else
        animation_button_none(head->scenes->in_game->button);
    manage_event_conversation(head, event);
}