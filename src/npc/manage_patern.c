/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** manage_patern
*/

#include "rpg.h"

void move_up_npc(npc_t *npc)
{
    sfVector2f move = {0, npc->speed * -1};

    if (npc->orientation != UP)
        turn_npc_up(npc);
    npc->pos.y -= npc->speed;
    sfSprite_move(npc->sprite, move);
}

void move_down_npc(npc_t *npc)
{
    sfVector2f move = {0, npc->speed};

    if (npc->orientation != DOWN)
        turn_npc_down(npc);
    npc->pos.y += npc->speed;
    sfSprite_move(npc->sprite, move);
}

void move_left_npc(npc_t *npc)
{
    sfVector2f move = {npc->speed * -1, 0};

    if (npc->orientation != LEFT)
        turn_npc_left(npc);
    npc->pos.x -= npc->speed;
    sfSprite_move(npc->sprite, move);
}

void move_right_npc(npc_t *npc)
{
    sfVector2f move = {npc->speed, 0};

    if (npc->orientation != RIGHT)
        turn_npc_right(npc);
    npc->pos.x += npc->speed;
    sfSprite_move(npc->sprite, move);
}

void manage_patern(head_t *head, npc_t *npc)
{
    int index = npc->patern.index;

    if (npc->patern.point[index].x < npc->pos.x)
        move_left_npc(npc);
    if (npc->patern.point[index].x > npc->pos.x)
        move_right_npc(npc);
    if (npc->patern.point[index].y < npc->pos.y)
        move_up_npc(npc);
    if (npc->patern.point[index].y > npc->pos.y)
        move_down_npc(npc);
    if (npc->pos.y >= npc->patern.point[index].y &&
    npc->pos.y <= npc->patern.point[index].y + 10 &&
    npc->pos.x >= npc->patern.point[index].x &&
    npc->pos.x <= npc->patern.point[index].x + 10)
        npc->patern.index++;
    if (npc->patern.index > npc->patern.nb_point - 1)
        npc->patern.index = 0;
}