/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** in_game
*/

#ifndef IN_GAME_H_
#define IN_GAME_H_

#include "rpg.h"

#define COLLISION_LAYER "COLLISION"
#define TOP_LAYER "TOP"
#define EVENT_LAYER "EVENT"

enum layers_t {
    COLLISION,
    TOP
};

typedef struct game_event_s {
    char *name;
    sfFloatRect event;
    struct game_event_s *next;
} game_event_t;

typedef struct map_s {
    sfSprite ****map;
    sfSprite ***top;
    sfSprite ***collision;
    sfTexture **res;
    sfVector2f len;
    int layer_len;
    int tile_len;
    sfBool **hitbox;
    game_event_t *event;
    char *name;
} map_t;

typedef struct new_map_s {
    char *new_filepath;
    sfVector2f new_pos;
} new_map_t;

typedef struct in_game_s {
    sfClock *clock;
    float time;
    float time_base;
    float time_pause;
    int time_last_save;
    sfView *view;
    object_t *object;
    button_t *button;
    sfBool event_text_display;
    text_t *text;
    text_scrolling_t *text_scrolling;
    text_scrolling_t *current_conversation;
    gen_ptcl_t *gen_ptcl;
    player_t *player;
    npc_t *npc;
    inventory_t *inventory;
    map_t *map;
    sfFloatRect player_rect;
    new_map_t new_map;
    object_t *bubble;
    object_t *face;
    quest_t *quests;
    sfBool opened_chest[10];
    sfBool boss;
} in_game_t;

// FUNCTION //
void init_in_game_scenes(head_t *head);
void destroy_in_game_scenes(scenes_t *scenes);
void in_game_event(head_t *head, sfEvent event);
void in_game_handler(head_t *head);
void in_game_display(head_t *head);

// MAP //
void init_map(head_t *head, in_game_t *menu);
void display_map(head_t *head, in_game_t *menu);
void display_map_top(head_t *head, in_game_t *menu);

// CONVERSATION //
void display_conversation(head_t *head, player_t *player);

// QUEST //
quest_t *load_quest(in_game_t *game, int quest_id);

// EVENT //
void manage_event_button_in_game(head_t *head, sfEvent event);
char *game_event_detector(player_t *player, map_t *map);

// FUNCTION BUTTON //
void open_pause_menu(head_t *head, button_t *button);
void open_skill_tree(head_t *head);

// BUTTON PRESET //
static const button_data_t PAUSE_BUTTON = {{1795, 5}, {0.7, 0.7}, SQUARE,
"assets/buttons/pause.png",
"", 20, (sfColor){255, 255, 255, 255},
"Pause", 20, (sfColor){255, 255, 255, 255},
&open_pause_menu};

#endif /* !IN_GAME_H_ */