/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** main_pause_handler
*/

#include "rpg.h"

void skill_tree_event(head_t *head, sfEvent event)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(head->window);
    sfVector2f ps_mouse;
    const sfView *view = sfRenderWindow_getView(head->window);

    p_mouse = sfMouse_getPositionRenderWindow(head->window);
    ps_mouse = sfRenderWindow_mapPixelToCoords(head->window, p_mouse, view);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(head->window);
    is_hover_button_skill(head, head->scenes->skill_tree->button, ps_mouse);
    if (event.type == sfEvtMouseButtonPressed && event.type != sfEvtClosed)
        is_clic_button_skill(head, head->scenes->skill_tree->button, ps_mouse);
    else
        animation_button_none(head->scenes->skill_tree->button);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS)
        quit_skill_tree(head, NULL);
}

void skill_tree_handler(head_t *head)
{

}

void skill_tree_display(head_t *head)
{
    in_game_display(head);
    display_object(head, head->scenes->skill_tree->object);
    sfRenderWindow_drawSprite(head->window,
    head->scenes->skill_tree->table_description->sprite, NULL);
    display_button(head, head->scenes->skill_tree->button);
    display_cost_star(head);
    display_text(head, head->scenes->skill_tree->text);
    display_text_scrolling(head, head->scenes->skill_tree->text_scrolling);
    display_gen_ptcl(head, head->scenes->skill_tree->gen_ptcl);
}