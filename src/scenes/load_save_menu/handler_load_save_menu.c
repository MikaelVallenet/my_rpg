/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** main_pause_handler
*/

#include "rpg.h"

void load_save_menu_event(head_t *head, sfEvent event)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(head->window);
    sfVector2f pos_mouse;
    const sfView *view = sfRenderWindow_getView(head->window);

    p_mouse = sfMouse_getPositionRenderWindow(head->window);
    pos_mouse = sfRenderWindow_mapPixelToCoords(head->window, p_mouse, view);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(head->window);
    is_hover_button(head->scenes->load_save_menu->button, pos_mouse);
    if (event.type == sfEvtMouseButtonPressed && event.type != sfEvtClosed)
        is_clic_button(head, head->scenes->load_save_menu->button, pos_mouse);
    else
        animation_button_none(head->scenes->load_save_menu->button);
}

void load_save_menu_handler(head_t *head)
{
}

void load_save_menu_display(head_t *head)
{
    display_object(head, head->scenes->load_save_menu->object);
    display_button(head, head->scenes->load_save_menu->button);
    display_text(head, head->scenes->load_save_menu->text);
    display_text_scrolling(head, head->scenes->load_save_menu->text_scrolling);
    display_gen_ptcl(head, head->scenes->load_save_menu->gen_ptcl);
}