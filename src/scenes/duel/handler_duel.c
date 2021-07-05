/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** handler duel
*/

#include "rpg.h"

static void handle_all_gen_particle(gen_ptcl_t *list_gen)
{
    gen_ptcl_t *gen = list_gen;

    while (gen != NULL) {
        handler_gen_ptcl(gen);
        gen = gen->next;
    }
}

void duel_event(head_t *head, sfEvent event)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(head->window);
    sfVector2f ps_mouse;
    const sfView *view = sfRenderWindow_getView(head->window);

    p_mouse = sfMouse_getPositionRenderWindow(head->window);
    ps_mouse = sfRenderWindow_mapPixelToCoords(head->window, p_mouse, view);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(head->window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace &&
    head->scenes->duel_scene->fight->attack->run == 1)
        press_space_attack(head, head->scenes->duel_scene->fight);
    hub_move_player_ptcl(head->scenes->duel_scene->fight, event);
    (void)ps_mouse;
}

void duel_handler(head_t *head)
{
    handle_turn(head, head->scenes->duel_scene->fight);
    if (head->scenes->duel_scene->fight->defense->activate) {
        handler_ptcl_player_mv(head->scenes->duel_scene->fight);
        if (head->scenes->duel_scene->fight->defense->end == 0)
            handle_all_gen_particle(head->scenes->duel_scene->gen_ptcl);
        if (head->scenes->duel_scene->fight->defense->end == 0)
            move_gen_ptcl_along_box(head->scenes->duel_scene->gen_ptcl,
            head->scenes->duel_scene->fight);
        head->scenes->in_game->time = head->scenes->in_game->time_base;
        head->scenes->in_game->time += get_time(head);
        if (head->scenes->duel_scene->fight->defense->end == 0)
            handle_collision(head, head->scenes->duel_scene->fight,
            head->scenes->duel_scene->gen_ptcl, head->scenes->in_game->time);
        handle_turn(head, head->scenes->duel_scene->fight);
    }
    return;
}

void duel_display(head_t *head)
{
    sfRenderWindow_clear(head->window, sfBlack);
    sfRenderWindow_drawSprite(head->window, head->scenes->duel_scene->sprite,
    NULL);
    display_fights(head, head->scenes->duel_scene->fight);
    display_infos(head, head->scenes->duel_scene->fight);
    display_text_scrolling(head, head->scenes->duel_scene->text_scrolling);
    handle_attack(head, head->scenes->duel_scene->fight);
    handle_defense(head, head->scenes->duel_scene->fight);
    return;
}