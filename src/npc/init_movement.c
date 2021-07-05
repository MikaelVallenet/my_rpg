/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** init_movement
*/

#include "rpg.h"

void init_orientation_npc(pars_data_t *data, npc_t *npc)
{
    char *state_orientation = json_search(data, "orientation")->values.kstr;

    if (my_strcmp(state_orientation, "left") == 0)
        turn_npc_left(npc);
    if (my_strcmp(state_orientation, "right") == 0)
        turn_npc_right(npc);
    if (my_strcmp(state_orientation, "down") == 0)
        turn_npc_down(npc);
    if (my_strcmp(state_orientation, "up") == 0)
        turn_npc_up(npc);
}

void init_patern_npc(pars_data_t *data, npc_t *npc)
{
    pars_data_t *point = json_search(data, "point");
    pars_data_t *stat;

    npc->patern.nb_point = json_search(data, "nb_point")->values.kint;
    npc->patern.index = 0;
    npc->patern.point = malloc(sizeof(sfVector2f) * npc->patern.nb_point);
    point = point->values.kobj;
    for (int i = 0; i < npc->patern.nb_point; i++) {
        stat = point->values.kobj;
        npc->patern.point[i].x = stat->values.kint;
        stat = stat->next;
        npc->patern.point[i].y = stat->values.kint;
        point = point->next;
    }
}

void init_movement_npc(pars_data_t *data, npc_t *npc)
{
    char *state_movement = json_search(data, "state")->values.kstr;

    if (my_strcmp(state_movement, "move") == 0)
        npc->state_move = MOVE;
    else
        npc->state_move = STATIC;
    if (npc->state_move == MOVE)
        init_patern_npc(data, npc);
    init_orientation_npc(data, npc);
}