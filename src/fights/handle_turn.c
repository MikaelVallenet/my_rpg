/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** handle turn
*/

#include "rpg.h"

void switch_map(head_t *head, in_game_t *game, char *map_name, sfVector2f pos);
void check_duel_ennemy(head_t *head, fight_t *fight);

void create_gen_ptcl_defense(head_t *head)
{
    init_gen_mobs(head, head->scenes->duel_scene->fight);
    start_gen_ptcl("gen_up", head->scenes->duel_scene->gen_ptcl);
    start_gen_ptcl("gen_left", head->scenes->duel_scene->gen_ptcl);
    start_gen_ptcl("gen_right", head->scenes->duel_scene->gen_ptcl);
    start_gen_ptcl("gen_down", head->scenes->duel_scene->gen_ptcl);
}

int check_win(head_t *head, fight_t *fight)
{
    int stuff = mrand() % 13;
    int potion = mrand() % 3;
    sfVector2f pos = {340, 65};

    if (fight->ennemy->health < 1) {
        head->scenes->in_game->player->p_stat.xp += fight->experience;
        if (potion != 0)
            add_items(potion, head->scenes->in_game->inventory);
        if (stuff != 0)
            add_items(stuff, head->scenes->in_game->inventory);
        check_duel_ennemy(head, fight);
        return (1);
    }
    if (fight->player->health < 1) {
        fight->player->health = fight->player->health_max;
        switch_map(head, head->scenes->in_game, "infirmary.json", pos);
        return (2);
    }
    return (0);
}

void reset_all_gen_ptcl(gen_ptcl_t *gen_ptcl)
{
    reset_gen_ptcl("gen_up", gen_ptcl);
    reset_gen_ptcl("gen_left", gen_ptcl);
    reset_gen_ptcl("gen_right", gen_ptcl);
    reset_gen_ptcl("gen_down", gen_ptcl);
}

void handle_turn_aux(head_t *head, fight_t *fight)
{
    if (fight->defense->activate == 1 && fight->defense->end == 1) {
        fight->defense->activate = 0;
        fight->defense->end = 0;
        fight->attack->direction = -1;
        fight->attack->timer = 0;
        fight->attack->activate = 1;
        fight->attack->run = 1;
        destroy_gen_ptcl(head->scenes->duel_scene->gen_ptcl);
    }
}

void handle_turn(head_t *head, fight_t *fight)
{
    head->scenes->in_game->time = head->scenes->in_game->time_base;
    head->scenes->in_game->time += get_time(head);
    if (check_win(head, fight) != 0) {
        quit_duel(head, NULL);
        head->scenes->in_game->player->p_stat.health = fight->player->health;
        return;
    }
    if (fight->attack->activate == 1 && fight->attack->end == 1) {
        head->scenes->duel_scene->gen_ptcl = NULL;
        fight->attack->activate = 0;
        fight->attack->end = 0;
        fight->defense->activate = 1;
        fight->defense->timer3 = head->scenes->in_game->time;
        fight->defense->timer = head->scenes->in_game->time;
        sfSprite_setPosition(fight->defense->my_ptcl->sprite,
        (sfVector2f){915, 860});
        fight->defense->keys =
        (list_key_t){UNPRESS, UNPRESS, UNPRESS, UNPRESS};
        return (create_gen_ptcl_defense(head));
    }
    handle_turn_aux(head, fight);
}