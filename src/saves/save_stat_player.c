/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** save_stat_player
*/

#include "rpg.h"

void save_inventory(head_t *head)
{
    pars_data_t *data_player = head->scenes->in_game->player->stat_json->data;
    pars_data_t *obj = json_search(data_player, "inventory");
    pars_data_t *stat;

    obj = obj->values.kobj;
    for (int i = 0; i < 32; i++) {
        stat = obj->values.kobj;
        stat->values.kint = head->scenes->in_game->inventory->items[i].id;
        stat = stat->next;
        stat->values.kint = head->scenes->in_game->inventory->items[i].nbr;
        stat = stat->next;
        stat->values.kint = i;
        obj = obj->next;
    }
}

void save_skill_tree(head_t *head)
{
    pars_data_t *data_player = head->scenes->in_game->player->stat_json->data;
    pars_data_t *obj = json_search(data_player, "skill_tree");

    obj = obj->values.kobj->values.kobj;
    obj->values.kint = head->scenes->in_game->player->skill_tree.armor_1;
    obj = obj->next;
    obj->values.kint = head->scenes->in_game->player->skill_tree.armor_2;
    obj = obj->next;
    obj->values.kint = head->scenes->in_game->player->skill_tree.armor_3;
    obj = obj->next;
    obj->values.kint = head->scenes->in_game->player->skill_tree.damage_1;
    obj = obj->next;
    obj->values.kint = head->scenes->in_game->player->skill_tree.damage_2;
    obj = obj->next;
    obj->values.kint = head->scenes->in_game->player->skill_tree.damage_3;
    obj = obj->next;
    obj->values.kint = head->scenes->in_game->player->skill_tree.speed_1;
    obj = obj->next;
    obj->values.kint = head->scenes->in_game->player->skill_tree.speed_2;
    obj = obj->next;
    obj->values.kint = head->scenes->in_game->player->skill_tree.speed_3;
}

void save_stat_player_inv(head_t *head)
{
    pars_data_t *stat;
    pars_data_t *data_player = head->scenes->in_game->player->stat_json->data;

    stat = json_search(data_player, "map");
    stat->values.kstr = head->scenes->in_game->map->name;
    save_inventory(head);
    save_skill_tree(head);
}

void save_stat_player_aux(head_t *head)
{
    pars_data_t *stat;
    pars_data_t *data_player = head->scenes->in_game->player->stat_json->data;

    stat = json_search(data_player, "progression");
    stat->values.kint = head->scenes->in_game->player->p_stat.progression;
    stat = json_search(data_player, "time_played");
    stat->values.kint +=
    (head->scenes->in_game->time / 60 - head->scenes->in_game->time_last_save);
    head->scenes->in_game->time_last_save = head->scenes->in_game->time / 60;
    stat = json_search(data_player, "pos_x");
    stat->values.kint = head->scenes->in_game->player->pos.x;
    stat = json_search(data_player, "pos_y");
    stat->values.kint = head->scenes->in_game->player->pos.y;
    stat = json_search(data_player, "nb_star");
    stat->values.kint = head->scenes->in_game->player->p_stat.nb_star;
    stat = json_search(data_player, "speed");
    stat->values.kint = head->scenes->in_game->player->speed;
    save_stat_player_inv(head);
}

void save_stat_player(head_t *head)
{
    pars_data_t *stat;
    pars_data_t *data_player = head->scenes->in_game->player->stat_json->data;

    stat = json_search(data_player, "health");
    stat->values.kint = head->scenes->in_game->player->p_stat.health;
    stat = json_search(data_player, "health_max");
    stat->values.kint = head->scenes->in_game->player->p_stat.health_max;
    stat = json_search(data_player, "damage");
    stat->values.kint = head->scenes->in_game->player->p_stat.damage;
    stat = json_search(data_player, "armor");
    stat->values.kint = head->scenes->in_game->player->p_stat.armor;
    stat = json_search(data_player, "level");
    stat->values.kint = head->scenes->in_game->player->p_stat.lvl;
    stat = json_search(data_player, "xp");
    stat->values.kint = head->scenes->in_game->player->p_stat.xp;
    stat = json_search(data_player, "xp_next_level");
    stat->values.kint = head->scenes->in_game->player->p_stat.nxt_lvl;
    stat = json_search(data_player, "quests");
    stat->values.kobj = save_quests_progress(head->scenes->in_game->quests);
    save_stat_player_aux(head);
    writer_json(get_path_save(head), NULL, data_player);
}