/*
** EPITECH PROJECT, 2021
** FIGHT_H
** File description:
** FIGHT_H
*/

#ifndef FIGHT_H
#define FIGHT_H

#include "rpg.h"

#define SPEED_BAR 25
#define SPEED_SPIRIT 25
#define SPEED_BOSS 25
#define CARD_PATH "./assets/cards.png"
#define WOLF "./resources/mobs/wolf.json"
#define WOLFTANK "./resources/mobs/wolf_tank.json"
#define SPIRITMAGE "./resources/mobs/spirit_mage.json"
#define SPIRITATTACK "./resources/mobs/spirit_damage.json"
#define DEVIL "./resources/mobs/devil.json"

typedef struct duel_defense_s {
    object_t *arena;
    object_t *my_ptcl;
    float timer;
    float timer2;
    float timer3;
    int god;
    int activate;
    list_key_t keys;
    int direction_up;
    int direction_left;
    int end;
} duel_defense_t;

typedef struct reward_fight_s {
    int item;
    int experience;
} reward_fight_t;

typedef struct card_s {
    char *name;
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *texture_perso;
    sfSprite *sprite_perso;
    sfVector2f pos;
    sfVector2f pos_perso;
    object_t *healh_bg_bar;
    object_t *health_bar;
    int damage;
    int health;
    int health_max;
    int armor;
    int lvl;
} card_t;

typedef struct duel_attack_s {
    int activate;
    object_t *attack_bar;
    object_t *cursor;
    float timer;
    int run;
    int direction;
    int damage;
    int end;
} duel_attack_t;

typedef struct fight_data_s {
    char *name;
    char *path_enemy;
    stat_t ennemy_stat;
    int experience;
} fight_data_t;

typedef struct fight_s {
    card_t *player;
    card_t *ennemy;
    object_t *armor_icone;
    object_t *sword_icone;
    duel_attack_t *attack;
    duel_defense_t *defense;
    int experience;
} fight_t;

typedef struct attack_s {
    sfTexture *texture;
    sfSprite *sprite;
} attack_t;

//PROTOTYPES
void init_duel_scene(head_t *head, char *filepath);
void init_card_player(head_t *head, card_t *card, char *filepath);
void init_card_monster(head_t *head, fight_data_t data, card_t *card,
char *filepath);
fight_data_t load_monster(char *filepath);
void display_card(head_t *head, card_t *card);
void destroy_fight(head_t *head, fight_t *fight);
void init_fight(head_t *head, fight_data_t data);
void display_fights(head_t *head, fight_t *fight);
void update_duel_text(head_t *head, fight_t *fight, text_scrolling_t *text);
void init_defense(fight_t *fight, head_t *head);
void init_attack(fight_t *fight);
void hub_move_player_ptcl(fight_t *fight, sfEvent event);
void handler_ptcl_player_mv(fight_t *fight);
void move_gen_ptcl_along_box(gen_ptcl_t *list_gen, fight_t *fight);
void handle_collision(head_t *head, fight_t *figh, gen_ptcl_t *lis, float tim);
void handle_turn(head_t *head, fight_t *fight);
void reset_gen_ptcl(char *title, gen_ptcl_t *gen_ptcl);
void init_gen_mobs(head_t *head, fight_t *fight);

static const gen_ptcl_data_t GEN_UP = {"gen_up",
"./assets/particle/ptcl_fire.png", NULL, 12, 10,
(sfVector2f){1.0, 1.0}, G_FAST, 10.0, 999, 0, 0, (sfVector2f){929, 680},
(gen_direction_t){0, 1, 1, 1}};

static const gen_ptcl_data_t GEN_DOWN = {"gen_down",
"./assets/particle/ptcl_fire.png", NULL, 12, 10,
(sfVector2f){1.0, 1.0}, G_FAST, 10.0, 999, 0, 0, (sfVector2f){929, 995},
(gen_direction_t){1, 0, 1, 1}};

static const gen_ptcl_data_t GEN_LEFT = {"gen_left",
"./assets/particle/ptcl_fire.png", NULL, 12, 10,
(sfVector2f){1.0, 1.0}, G_FAST, 10.0, 999, 0, 0, (sfVector2f){1515, 820},
(gen_direction_t){1, 1, 1, 0}};

static const gen_ptcl_data_t GEN_RIGHT = {"gen_right",
"./assets/particle/ptcl_fire.png", NULL, 12, 10,
(sfVector2f){1.0, 1.0}, G_FAST, 10.0, 999, 0, 0, (sfVector2f){338, 808},
(gen_direction_t){1, 1, 0, 1}};

//

static const gen_ptcl_data_t GEN_UP_SPIRIT = {"gen_up",
"./assets/particle/ptcl_fire.png", NULL, 15, 13,
(sfVector2f){1.0, 1.0}, G_FAST, 10.0, 999, 0, 0, (sfVector2f){929, 680},
(gen_direction_t){0, 1, 1, 1}};

static const gen_ptcl_data_t GEN_DOWN_SPIRIT = {"gen_down",
"./assets/particle/ptcl_fire.png", NULL, 15, 13,
(sfVector2f){1.0, 1.0}, G_FAST, 10.0, 999, 0, 0, (sfVector2f){929, 995},
(gen_direction_t){1, 0, 1, 1}};

static const gen_ptcl_data_t GEN_LEFT_SPIRIT = {"gen_left",
"./assets/particle/ptcl_fire.png", NULL, 15, 13,
(sfVector2f){1.0, 1.0}, G_FAST, 10.0, 999, 0, 0, (sfVector2f){1515, 820},
(gen_direction_t){1, 1, 1, 0}};

static const gen_ptcl_data_t GEN_RIGHT_SPIRIT = {"gen_right",
"./assets/particle/ptcl_fire.png", NULL, 15, 13,
(sfVector2f){1.0, 1.0}, G_FAST, 10.0, 999, 0, 0, (sfVector2f){338, 808},
(gen_direction_t){1, 1, 0, 1}};

//

static const gen_ptcl_data_t GEN_UP_BOSS = {"gen_up",
"./assets/particle/ptcl_fire.png", NULL, 18, 15,
(sfVector2f){1.0, 1.0}, G_FAST, 10.0, 999, 0, 0, (sfVector2f){929, 680},
(gen_direction_t){0, 1, 1, 1}};

static const gen_ptcl_data_t GEN_DOWN_BOSS = {"gen_down",
"./assets/particle/ptcl_fire.png", NULL, 18, 15,
(sfVector2f){1.0, 1.0}, G_FAST, 10.0, 999, 0, 0, (sfVector2f){929, 995},
(gen_direction_t){1, 0, 1, 1}};

static const gen_ptcl_data_t GEN_LEFT_BOSS = {"gen_left",
"./assets/particle/ptcl_fire.png", NULL, 18, 15,
(sfVector2f){1.0, 1.0}, G_FAST, 10.0, 999, 0, 0, (sfVector2f){1515, 820},
(gen_direction_t){1, 1, 1, 0}};

static const gen_ptcl_data_t GEN_RIGHT_BOSS = {"gen_right",
"./assets/particle/ptcl_fire.png", NULL, 18, 15,
(sfVector2f){1.0, 1.0}, G_FAST, 10.0, 999, 0, 0, (sfVector2f){338, 808},
(gen_direction_t){1, 1, 0, 1}};

//

static const object_data_t BAR_ATTACK =
{"assets/images/duel/bar_attack.png",
{382, 700},
{2, 2}
};

static const object_data_t SWORD_ICONE =
{"assets/images/picto/sword.png",
{1030, 330},
{0.23, 0.23}
};

static const object_data_t SHIELD_ICONE =
{"assets/images/picto/shield.png",
{1130, 333},
{0.23, 0.23}
};

static const object_data_t WHITE_CURSOR =
{"assets/images/duel/white_cursor.png",
{915, 700},
{2, 2}
};

static const object_data_t ARENA =
{"assets/images/duel/arena.png",
{382, 700},
{2, 2}
};

static const object_data_t PLAYER_PTCL =
{"assets/particle/player_ptcl.png",
{915, 860},
{1, 1}
};


static const text_data_scrolling_t FIGHT_SWORD_P = {"fight_sword_player",
NULL, "999", {540, 460}, (sfColor){0, 0, 0, 255}, 35, T_FULL};

static const text_data_scrolling_t FIGHT_SHIELD_P = {"fight_shield_player",
NULL, "999", {690, 460}, (sfColor){0, 0, 0, 255}, 35, T_FULL};

static const text_data_scrolling_t FIGHT_SWORD_M = {"fight_sword_monster",
NULL, "999", {1160, 460}, (sfColor){0, 0, 0, 255}, 35, T_FULL};

static const text_data_scrolling_t FIGHT_SHIELD_M = {"fight_shield_monster",
NULL, "999", {1310, 460}, (sfColor){0, 0, 0, 255}, 35, T_FULL};

static const object_data_t BAR_HEALTH_BG_PLAYER =
{"assets/images/bar_1/square_red_bar.png",
{170, 670},
{1.5, 2.5}
};

static const object_data_t BAR_HEALTH_PLAYER =
{"assets/images/bar_1/square_green_bar.png",
{188, 665},
{1.52, 2.5}
};

static const object_data_t BAR_HEALTH_BG_MONSTER =
{"assets/images/bar_1/square_red_bar.png",
{1550, 670},
{1.5, 2.5}
};

static const object_data_t BAR_HEALTH_MONSTER =
{"assets/images/bar_1/square_green_bar.png",
{1568, 665},
{1.52, 2.5}
};

#endif /* !FIGHT_H */
