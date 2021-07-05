/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** switch_map
*/

#include "rpg.h"
#include "../world.h"

static void transition_map(head_t *head)
{
    in_game_t *game = head->scenes->in_game;
    new_map_t new_map = game->new_map;
    char *filepath = new_map.new_filepath;
    sfVector2f pos = new_map.new_pos;

    unload_map_t(game->map);
    destroy_npc(head->scenes->in_game->npc);
    head->scenes->in_game->npc = NULL;
    head->scenes->in_game->map = load_map(head, filepath);
    game->player->pos = pos;
    sfSprite_setPosition(game->player->sprite, pos);
    free(new_map.new_filepath);
}

void switch_map(head_t *head, in_game_t *game, char *map_name, sfVector2f pos)
{
    char *filepath = my_strcat(TILED_MAP_FILE, map_name);

    game->new_map.new_filepath = filepath;
    game->new_map.new_pos = pos;
    start_fade_animation(head, transition_map, 0);
}