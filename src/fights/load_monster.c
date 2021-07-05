/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** load monster
*/

#include "rpg.h"

fight_data_t load_monster(char *filepath)
{
    fight_data_t fight;
    pars_obj_t *obj = parser_json(filepath);
    pars_data_t *data = obj->data;

    fight.path_enemy = json_search(data, "sprite")->values.kstr;
    fight.name = json_search(data, "name")->values.kstr;
    fight.ennemy_stat.health = json_search(data, "health")->values.kint;
    fight.ennemy_stat.damage = json_search(data, "damage")->values.kint;
    fight.ennemy_stat.armor = json_search(data, "armor")->values.kint;
    fight.ennemy_stat.lvl = json_search(data, "level")->values.kint;
    fight.experience = json_search(data, "xp")->values.kint;
    return (fight);
}