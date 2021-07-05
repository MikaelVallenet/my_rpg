/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** manage_move_animation
*/

#include "rpg.h"

void set_first_rect_player(player_t *player)
{
    sfIntRect rect = player->rect;

    player->last_move = 0;
    if (rect.left != 0) {
        rect.left = 0;
        player->rect = rect;
        sfSprite_setTextureRect(player->sprite, rect);
    }
}

void manage_animated_player(player_t *player, int is_animated, head_t *head)
{
    if (head->scenes->in_game->time > player->last_move + (1.0/9.0)) {
        player->last_move = head->scenes->in_game->time;
        if (is_animated == 1)
            animate_player(player);
        else
            set_first_rect_player(player);
    }
}

static void manage_move_player_2(player_t *player, head_t *head,
int *is_animated, sfVector2f pos)
{
    if (player->key.key_right == PRESS && player->key.key_left != PRESS) {
        if (is_hitbox(head, (sfVector2f){pos.x + player->speed, pos.y})) {
            move_right_player(player);
            *is_animated = 1;
        }
        else
            turn_player_right(player);
        launch_rdm_fight(head);
    }
    if (player->key.key_right != PRESS && player->key.key_left == PRESS) {
        if (is_hitbox(head, (sfVector2f){pos.x - player->speed, pos.y})) {
            move_left_player(player);
            *is_animated = 1;
        }
        else
            turn_player_left(player);
        launch_rdm_fight(head);
    }
}

void manage_move_player(player_t *player, head_t *head)
{
    int is_animated = 0;
    sfVector2f pos = player->pos;

    if (player->key.key_down == PRESS && player->key.key_up != PRESS) {
        if (is_hitbox(head, (sfVector2f){pos.x, pos.y + player->speed})) {
            move_down_player(player);
            is_animated = 1;
        }
        else
            turn_player_down(player);
    }
    if (player->key.key_down != PRESS && player->key.key_up == PRESS) {
        if (is_hitbox(head, (sfVector2f){pos.x, pos.y - player->speed})) {
            move_up_player(player);
            is_animated = 1;
        }
        else
            turn_player_up(player);
    }
    manage_move_player_2(player, head, &is_animated, pos);
    manage_animated_player(player, is_animated, head);
}