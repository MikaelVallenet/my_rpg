/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** move player
*/

#include "rpg.h"

void init_first_rect(player_t *player, player_data_t player_data)
{
    sfIntRect rect = player_data.rect_player;

    sfSprite_setTextureRect(player->sprite, rect);
    player->rect = rect;
}

void init_key(player_t *player)
{
    player->key.key_down = UNPRESS;
    player->key.key_up = UNPRESS;
    player->key.key_left = UNPRESS;
    player->key.key_right = UNPRESS;
}

void init_stat_player(head_t *head, player_t *player)
{
    pars_obj_t *obj = parser_json(get_path_save(head));

    player->stat_json = obj;
    player->p_stat.armor = json_search(obj->data, "armor")->values.kint;
    player->p_stat.damage = json_search(obj->data, "damage")->values.kint;
    player->p_stat.health = json_search(obj->data, "health")->values.kint;
    player->p_stat.lvl = json_search(obj->data, "level")->values.kint;
    player->p_stat.nxt_lvl =
    json_search(obj->data, "xp_next_level")->values.kint;
    player->p_stat.xp = json_search(obj->data, "xp")->values.kint;
    player->p_stat.coef = 1.5;
    player->p_stat.health_max =
    json_search(obj->data, "health_max")->values.kint;
    player->p_stat.progression =
    json_search(obj->data, "progression")->values.kint;
    player->p_stat.nb_star = json_search(obj->data, "nb_star")->values.kint;
    player->speed = json_search(obj->data, "speed")->values.kint;
}

void init_position_player(head_t *head, player_t *player)
{
    sfVector2f pos_spaw;

    pos_spaw.x =
    json_search(player->stat_json->data, "pos_x")->values.kint;
    pos_spaw.y =
    json_search(player->stat_json->data, "pos_y")->values.kint;
    sfSprite_setPosition(player->sprite, pos_spaw);
    player->pos = pos_spaw;
}

void init_player(head_t *head)
{
    player_t *player = malloc(sizeof(player_t));
    player_data_t player_data = get_preset_player(head);

    player->sprite = sfSprite_create();
    player->x_offset = player_data.x_offset;
    player->y_offset = player_data.y_offset;
    player->texture = sfTexture_createFromFile(player_data.path,
    &(player_data.rect_texture));
    sfSprite_setTexture(player->sprite, player->texture, sfFalse);
    sfSprite_setScale(player->sprite, (sfVector2f){3.5, 3.5});
    player->size_texture = sfTexture_getSize(player->texture);
    player->state_move = MOVE_DOWN;
    player->name = player_data.name;
    player->last_move = 0;
    player->is_in_conversation = 0;
    player->continue_conversation = 1;
    init_player_aux(head, player, player_data);
    head->scenes->in_game->player = player;
}