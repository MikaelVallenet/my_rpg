/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** npc
*/

#ifndef NPC_H_
#define NPC_H_

#include "rpg.h"

typedef enum state_npc_s {
    STATIC = 0,
    MOVE = 1,
} state_npc_t;

typedef enum orientation_s {
    UP = 0,
    DOWN = 1,
    RIGHT = 2,
    LEFT = 3,
} orientaion_t;

typedef struct patern_s {
    int nb_point;
    int index;
    sfVector2f *point;
} patern_t;

typedef struct npc_s {
    char *name;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2u size_texture;
    sfVector2f pos;
    float last_move;
    float scale;
    sfIntRect event_zone;
    struct npc_s *next;
    pars_data_t *data;
    pars_obj_t *current_conversation_data;
    sfBool is_in_event;
    state_npc_t state_move;
    int speed;
    patern_t patern;
    orientaion_t orientation;
    char *filepath_conversation;
} npc_t;

void test_npc_function(head_t *head);

// INIT //
void init_npc(head_t *head, npc_t **list, char *path);
void init_event_zone(pars_data_t *data, npc_t *npc);
void init_first_rect_npc(npc_t *npc);
void destroy_npc(npc_t *npc);
void handler_npc(head_t *head);

// ANIMATED //
void display_npc(head_t *head, npc_t *npc);
void animate_npc(npc_t *npc);
void move_event_zone(npc_t *npc);
void manage_animated_npc(npc_t *npc, head_t *head);

// EVENT //
sfBool is_in_event_zone(player_t *player, npc_t *npc);
void manage_conversation(head_t *head, player_t *player, npc_t *npc);
void manage_event_conversation(head_t *head, sfEvent event);

// INTERACTION //
void load_face_conversation(head_t *head, npc_t *npc, player_t *player);
void check_interaction_npc(head_t *head, npc_t *npc);

// CONVERSATION //
void launch_function_conversation(head_t *head, player_t *player, npc_t *npc);
void continue_function_conversation(head_t *head, player_t *player, npc_t *np);
void load_face_conversation(head_t *head, npc_t *npc, player_t *player);
void launch_first_conversation(head_t *head, player_t *player, npc_t *npc);
void continue_conversation(head_t *head, player_t *player, npc_t *npc);
void launch_npc_function(head_t *head, player_t *player, npc_t *npc);
void load_conversation(npc_t *npc);

// MOVEMENT //
void manage_patern(head_t *head, npc_t *npc);
void init_movement_npc(pars_data_t *data, npc_t *npc);
void turn_npc_up(npc_t *npc);
void turn_npc_down(npc_t *npc);
void turn_npc_left(npc_t *npc);
void turn_npc_right(npc_t *npc);

// FUNCTION //
void give_sword(head_t *head);

// PRESET //

// OBJECT PRESET //
static const object_data_t BUBBLE = {"./assets/images/bubble.png",
{320, 685 - 340}, {0.9, 0.9}};

// TEXT_SCROLLING PRESET //
static const text_data_scrolling_t NPC_CONVERSATION = {"npc_conversation",
NULL, "A", {350, 685 - 325}, (sfColor){0, 0, 0, 255},
45, T_MEDIUM};

#endif /* !NPC_H_ */