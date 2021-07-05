/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** init_player_aux
*/

#include "rpg.h"

void display_cloud(head_t *head, player_t *player)
{
    update_pos_cloud(player);
    sfRenderWindow_drawSprite(head->window, player->cloud->sprite, NULL);
}

void update_pos_cloud(player_t *player)
{
    sfVector2f pos = player->pos;

    pos.x += 55;
    pos.y -= 55;
    sfSprite_setPosition(player->cloud->sprite, pos);
}

void init_cloud(player_t *player)
{
    sfVector2f pos = player->pos;
    char *path = "./assets/images/cloud.png";

    pos.x += 55;
    pos.y -= 55;
    player->cloud = malloc(sizeof(object_t));
    player->cloud->texture = sfTexture_createFromFile(path, NULL);
    player->cloud->sprite = sfSprite_create();
    player->cloud->scale = (sfVector2f){0.15, 0.15};
    sfSprite_setPosition(player->cloud->sprite, pos);
    sfSprite_setTexture(player->cloud->sprite, player->cloud->texture, sfTrue);
    sfSprite_setScale(player->cloud->sprite, player->cloud->scale);
    player->cloud->next = NULL;
}

void init_player_aux(head_t *head, player_t *player, player_data_t player_data)
{
    init_stat_player(head, player);
    init_skill_tree_player(head, player);
    init_position_player(head, player);
    init_first_rect(player, player_data);
    init_key(player);
    init_cloud(player);
}