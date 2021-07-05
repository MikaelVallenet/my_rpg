/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** in_game_handler
*/

#include "rpg.h"

void select_player_event(head_t *head, sfEvent event)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(head->window);
    sfVector2f pos_mouse;
    const sfView *view = sfRenderWindow_getView(head->window);

    p_mouse = sfMouse_getPositionRenderWindow(head->window);
    pos_mouse = sfRenderWindow_mapPixelToCoords(head->window, p_mouse, view);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(head->window);
    is_hover_button(head->scenes->select_player->button, pos_mouse);
    if (event.type == sfEvtMouseButtonPressed && event.type != sfEvtClosed)
        is_clic_button(head, head->scenes->select_player->button, pos_mouse);
    else
        animation_button_none(head->scenes->select_player->button);
}

void select_player_handler(head_t *head)
{

}

void select_player_display(head_t *head)
{
    display_object(head, head->scenes->select_player->object);
    display_button(head, head->scenes->select_player->button);
    display_text(head, head->scenes->select_player->text);
    display_text_scrolling(head, head->scenes->select_player->text_scrolling);
    display_gen_ptcl(head, head->scenes->select_player->gen_ptcl);
}