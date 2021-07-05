/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** character include
*/

#include "rpg.h"

// STRUCTURE //

typedef enum move_s {
    MOVE_UP = 0,
    MOVE_DOWN = 1,
    MOVE_RIGHT = 2,
    MOVE_LEFT = 3,
} move_t;

typedef enum state_key_s {
    UNPRESS = 0,
    PRESS = 1,
} state_key_t;

typedef struct stat_s {
    int health_max;
    int health;
    int xp;
    int lvl;
    int nxt_lvl;
    int damage;
    int armor;
    int progression;
    float coef;
    int nb_star;
} stat_t;

typedef struct skill_tree_s {
    int armor_1;
    int armor_2;
    int armor_3;
    int damage_1;
    int damage_2;
    int damage_3;
    int speed_1;
    int speed_2;
    int speed_3;
} skill_tree_t;

typedef struct list_key_s {
    state_key_t key_up;
    state_key_t key_down;
    state_key_t key_left;
    state_key_t key_right;
} list_key_t;

typedef struct player_s {
    char *name;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2u size_texture;
    sfVector2f pos;
    float speed;
    float last_move;
    move_t state_move;
    list_key_t key;
    sfBool is_move;
    int x_offset;
    int y_offset;
    stat_t p_stat;
    pars_obj_t *stat_json;
    skill_tree_t skill_tree;
    int is_in_conversation;
    int continue_conversation;
    object_t *cloud;
} player_t;

typedef struct player_data_s {
    char *name;
    char *path;
    int x_offset;
    int y_offset;
    float speed;
    sfVector2f pos_spawn;
    sfIntRect rect_texture;
    sfIntRect rect_player;
} player_data_t;

// FUNCTION //
void init_player(head_t *head);
void destroy_player(player_t *player);
void display_player(head_t *head, player_t *player);
void animate_player(player_t *player);
void player_event(head_t *head, sfEvent event, player_t *player);
void set_first_rect_player(player_t *player);
player_data_t get_preset_player(head_t *head);
void lvl_up(player_t *player);
void init_cloud(player_t *player);
void update_pos_cloud(player_t *player);
void init_player_aux(head_t *head, player_t *player, player_data_t player_dat);
void init_stat_player(head_t *head, player_t *player);
void init_position_player(head_t *head, player_t *player);
void init_key(player_t *player);
void init_first_rect(player_t *player, player_data_t player_data);
void display_cloud(head_t *head, player_t *player);
sfBool is_hitbox(head_t *head, sfVector2f pos);

// EVENT //
void manage_key_press_player(player_t *player, sfEvent event, head_t *head);
void manage_key_unpress_player(player_t *player, sfEvent event, head_t *head);

// MOVE //
void manage_move_player(player_t *player, head_t *head);
void move_up_player(player_t *player);
void move_down_player(player_t *player);
void move_left_player(player_t *player);
void move_right_player(player_t *player);

// TURN //
void turn_player_up(player_t *player);
void turn_player_down(player_t *player);
void turn_player_right(player_t *player);
void turn_player_left(player_t *player);

// DATA //
pars_data_t *init_player_data_json(char *name);
void init_skill_tree_player(head_t *head, player_t *player);

// PLAYER PRESET //

static const stat_t GAME_ONE =
{
    300, 250, 120, 1, 500, 14, 8, 1.4
};

static const player_data_t ALEX_PRESET =
{"Alex",
"./assets/character/alex.png",
2, 3,
5,
(sfVector2f){1000, 1000},
(sfIntRect){22, 16, 61, 125},
(sfIntRect){0, 0, 14, 29},
};

static const player_data_t ELLIOT_PRESET =
{"Elliot",
"./assets/character/elliot.png",
2, 3,
2.5,
(sfVector2f){100, 100},
(sfIntRect){23, 16, 62, 125},
(sfIntRect){0, 0, 14, 29},
};

static const player_data_t HALEY_PRESET =
{"Caroline",
"./assets/character/haley.png",
0, 6,
2.5,
(sfVector2f){100, 100},
(sfIntRect){21, 52, 64, 122},
(sfIntRect){0, 0, 16, 26},
};

static const player_data_t MARU_PRESET =
{"Maru",
"./assets/character/maru.png",
2, 6,
2.5,
(sfVector2f){100, 100},
(sfIntRect){21, 52, 62, 122},
(sfIntRect){0, 0, 14, 26},
};
