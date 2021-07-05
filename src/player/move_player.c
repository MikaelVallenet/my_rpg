/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** move player
*/

#include "rpg.h"

void move_up_player(player_t *player)
{
    sfVector2f move = {0, player->speed * -1};

    if (player->state_move != MOVE_UP)
        turn_player_up(player);
    player->pos.y -= player->speed;
    sfSprite_move(player->sprite, move);
}

void move_down_player(player_t *player)
{
    sfVector2f move = {0, player->speed};

    if (player->state_move != MOVE_DOWN)
        turn_player_down(player);
    player->pos.y += player->speed;
    sfSprite_move(player->sprite, move);
}

void move_left_player(player_t *player)
{
    sfVector2f move = {player->speed * -1, 0};

    if (player->state_move != MOVE_LEFT)
        turn_player_left(player);
    player->pos.x -= player->speed;
    sfSprite_move(player->sprite, move);
}

void move_right_player(player_t *player)
{
    sfVector2f move = {player->speed, 0};

    if (player->state_move != MOVE_RIGHT)
        turn_player_right(player);
    player->pos.x += player->speed;
    sfSprite_move(player->sprite, move);
}