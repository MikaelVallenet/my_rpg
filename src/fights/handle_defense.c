/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** handle defense
*/

#include "rpg.h"

void move_gen_ptcl_along_box_aux(gen_ptcl_t *list_gen, fight_t *fight)
{
    gen_ptcl_t *gen;

    gen = find_gen_ptcl("gen_right", list_gen);
    if (fight->defense->direction_left == 1)
        gen->position.y += 5;
    else
        gen->position.y -= 5;
    if (gen->position.y < 750)
        fight->defense->direction_left = -1;
    if (gen->position.y > 900)
        fight->defense->direction_left = 1;
    gen = find_gen_ptcl("gen_down", list_gen);
    if (fight->defense->direction_up == 1)
        gen->position.x -= 5;
    else
        gen->position.x += 5;
    if (gen->position.x < 500)
        fight->defense->direction_up = -1;
    if (gen->position.x > 1300)
        fight->defense->direction_up = 1;
}

void move_gen_ptcl_along_box(gen_ptcl_t *list_gen, fight_t *fight)
{
    gen_ptcl_t *gen;

    gen = find_gen_ptcl("gen_up", list_gen);
    if (fight->defense->direction_up == 1)
        gen->position.x += 5;
    else
        gen->position.x -= 5;
    gen = find_gen_ptcl("gen_left", list_gen);
    if (fight->defense->direction_left == 1)
        gen->position.y -= 5;
    else
        gen->position.y += 5;
    move_gen_ptcl_along_box_aux(list_gen, fight);
}

void hub_move_player_ptcl(fight_t *fight, sfEvent event)
{
    if (fight->defense->activate == 0)
        return;
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyUp)
        fight->defense->keys.key_up = UNPRESS;
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyDown)
        fight->defense->keys.key_down = UNPRESS;
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyLeft)
        fight->defense->keys.key_left = UNPRESS;
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyRight)
        fight->defense->keys.key_right = UNPRESS;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp)
        fight->defense->keys.key_up = PRESS;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown)
        fight->defense->keys.key_down = PRESS;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft)
        fight->defense->keys.key_left = PRESS;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight)
        fight->defense->keys.key_right = PRESS;
}

static void display_defense(head_t *head, fight_t *fight)
{
    if (fight->defense->activate) {
        sfRenderWindow_drawSprite(head->window, fight->defense->arena->sprite,
        NULL);
        if (fight->defense->god == 1 || fight->defense->god == 0) {
            sfRenderWindow_drawSprite(head->window,
            fight->defense->my_ptcl->sprite, NULL);
        }
        display_gen_ptcl(head, head->scenes->duel_scene->gen_ptcl);
    }
}

void handle_defense(head_t *head, fight_t *fight)
{
    if (!fight->defense->activate)
        return;
    head->scenes->in_game->time = head->scenes->in_game->time_base;
    head->scenes->in_game->time += get_time(head);
    display_defense(head, fight);
    if (fight->defense->activate == 1 &&
    fight->defense->timer3 + 7.5 < head->scenes->in_game->time) {
        fight->defense->end = 1;
    }
}