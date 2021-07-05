/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** map
*/

#include "rpg.h"

static void display_layer(head_t *head, in_game_t *menu, sfSprite ***sprite)
{
    sfVector2f center = sfView_getCenter(menu->view);
    sfFloatRect rect = {center.x - 1060, center.y - 640, 2020, 1180};

    for (int i = menu->map->len.y - 1; i >= 0; i -= 1) {
        for (int j = menu->map->len.x - 1; j >= 0; j -= 1) {
            if (sprite[i][j] && sfFloatRect_contains(&rect, j * 64, i * 64)) {
                sfRenderWindow_drawSprite(head->window,
                sprite[i][j], NULL);
            }
        }
    }
}

void init_map(head_t *head, in_game_t *menu)
{
    char *map;

    map = json_search(head->scenes->in_game->player->stat_json->data,
    "map")->values.kstr;
    menu->map = load_map(head, map);
}

void display_map(head_t *head, in_game_t *menu)
{
    for (int k = 0; k < menu->map->layer_len; k += 1)
        display_layer(head, menu, menu->map->map[k]);
}

void display_map_top(head_t *head, in_game_t *menu)
{
    if (menu->map->top)
        display_layer(head, menu, menu->map->top);
}