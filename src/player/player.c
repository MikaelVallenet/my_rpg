/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** manage character
*/

#include "rpg.h"

void destroy_player(player_t *player)
{
    sfSprite_destroy(player->sprite);
    sfTexture_destroy(player->texture);
    pars_data_destroy(player->stat_json->data);
    free(player->stat_json);
    destroy_object(player->cloud);
    free(player);
}

void player_event(head_t *head, sfEvent event, player_t *player)
{
    if (event.type == sfEvtKeyPressed) {
        manage_key_press_player(player, event, head);
    }
    if (event.type == sfEvtKeyReleased) {
        manage_key_unpress_player(player, event, head);
    }
}

void display_player(head_t *head, player_t *player)
{
    if (player->is_in_conversation == 0) {
        manage_move_player(player, head);
    }
    sfRenderWindow_drawSprite(head->window, player->sprite, NULL);
}

void handler_player(head_t *head)
{
    return;
}