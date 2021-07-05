/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** pars_map_init_2
*/

#include "rpg.h"
#include "../world.h"

static game_event_t *init_event_layers(pars_data_t *layers)
{
    pars_data_t *cur;
    game_event_t *event = malloc(sizeof(game_event_t));
    game_event_t *first_event = event;

    for (; layers; layers = layers->next) {
        cur = layers->values.kobj;
        event->name = my_strdup(json_search(cur, "name")->values.kstr);
        event->event.width = (float) json_search(cur, "width")->values.kfloat;
        event->event.height = (float) json_search(cur, "height")->values.kfloat;
        event->event.left = (float) json_search(cur, "x")->values.kfloat;
        event->event.top = (float) json_search(cur, "y")->values.kfloat;
        if (!layers->next) {
            event->next = NULL;
        }
        else {
            event->next = malloc(sizeof(game_event_t));
            event = event->next;
        }
    }
    return (first_event);
}

char *game_event_detector(player_t *player, map_t *map)
{
    game_event_t *event = map->event;

    for (; event; event = event->next) {
        if (sfFloatRect_contains(&event->event,
        player->pos.x / 4 + player->rect.width / 2,
        player->pos.y / 4 + player->rect.height / 2)) {
            return (event->name);
        }
    }
    return (NULL);
}

int event_layers(pars_data_t *data, map_t *map)
{
    char *str = json_search(data, "type")->values.kstr;

    map->event = NULL;
    if (my_strcmp(str, "objectgroup") == 0) {
        map->event = init_event_layers(json_search(data,
        "objects")->values.kobj);
        return (1);
    }
    return (0);
}

event_switch_t event_finder(game_event_t *event, char *event_name)
{
    for (int i = 0; GLOBAL_EVENT[i].name; i += 1) {
        if (my_strcmp(GLOBAL_EVENT[i].name, event_name) == 0) {
            return (GLOBAL_EVENT[i]);
        }
    }
    return ((event_switch_t){.name = NULL});
}

void event_launch(head_t *head, event_switch_t event)
{
    int activated = verify_quest_event(head, head->scenes->in_game->quests,
    event.name);

    if (event.name == NULL || activated == 0 || (event.activated == 0
    && activated != 1))
        return;
    if (event.needs_to_click) {
        if (head->event->key_input != sfKeyE) {
            head->scenes->in_game->event_text_display = 1;
            return;
        }
        head->event->key_input = 0;
    }
    if (event.map_name) {
        switch_map(head, head->scenes->in_game, event.map_name, event.pos);
    } else if (event.pos.x != -1 && event.pos.y != -1) {
        head->scenes->in_game->player->pos = event.pos;
        sfSprite_setPosition(head->scenes->in_game->player->sprite, event.pos);
    }
    if (event.event_func)
        event.event_func(head);
}