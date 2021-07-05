/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** scenes
*/

#ifndef SCENES_H_
#define SCENES_H_

#include "rpg.h"

// // // SCENES // // //
// // Event // //
// Prototype
void global_event(head_t *head, sfEvent event);
void in_game_event(head_t *head, sfEvent event);

// Function pointer
static void (*const EVENT_PTR[])
(head_t *, sfEvent) = {main_menu_event, setting_menu_event,
pause_menu_event, load_save_menu_event, in_game_event,
select_player_event, skill_tree_event, duel_event, quest_menu_event};

// // Handlers // //
// Prototype
void global_handler(head_t *head);
void in_game_handler(head_t *head);

// Function pointer
static void (*const SCENES_PTR[])
(head_t *) = {main_menu_handler, setting_menu_handler,
pause_menu_handler, load_save_menu_handler, in_game_handler,
select_player_handler, skill_tree_handler, duel_handler, quest_menu_handler};

// // Displays // //
// Prototype
void global_display(head_t *head);
void in_game_display(head_t *head);

// Function pointer
static void (*const DISPLAY_PTR[])
(head_t *) = {main_menu_display, setting_menu_display,
pause_menu_display, load_save_menu_display, in_game_display,
select_player_display, skill_tree_display, duel_display, quest_menu_display};

// // Init // //
// Prototype
void init_global_scenes(head_t *head);
void init_in_game_scenes(head_t *head);

// Function pointer
static void (*const INIT_PTR[])
(head_t *) = {init_main_menu, init_setting_menu,
init_pause_menu, init_load_save_menu, init_in_game_scenes,
init_select_player_scenes, init_skill_tree, NULL, init_quest_menu};

// // Destroy // //
// Prototype
void destroy_global_scenes(scenes_t *scene);
void destroy_in_game_scenes(scenes_t *scenes);

// Function pointer
#define DESTROY_PTR_NB 9
static void (*const DESTROY_PTR[DESTROY_PTR_NB])
(scenes_t *) = {destroy_main_menu, destroy_setting_menu,
destroy_pause_menu, destroy_load_save_menu, destroy_in_game_scenes,
destroy_select_player_scenes, destroy_skill_tree, destroy_duel_scene,
destroy_quest_menu};

// Prototype
void scenes_unloader(head_t *head, scenes_t *scene);

// // Structures // //
typedef struct global_scene_s {
    sfSprite *fader;
    sfClock *fade_clock;
    int anim_fade;
    state_t state;
    void (*fade_func)(head_t *);
} global_scene_t;

typedef struct scenes_s {
    global_scene_t *global;
    main_menu_scene_t *main_menu;
    setting_menu_scene_t *setting_menu;
    pause_menu_scene_t *pause_menu;
    load_save_menu_scene_t *load_save_menu;
    in_game_t *in_game;
    select_player_t *select_player;
    skill_tree_scenes_t *skill_tree;
    duel_scene_t *duel_scene;
    quest_menu_t *quest_menu;
} scenes_t;

// MENU //

// CONST VARIABLE TEXT char *title; char *filepath,
//sfVector2f pos, sfColor color, int size, float speed
static const text_data_scrolling_t WELCOME_TEXT = {"welcome",
"./dial/text_1.txt", NULL, {400, 200}, (sfColor){255, 145, 56, 255},
45, T_FAST};

static const text_data_scrolling_t SECOND_TEXT = {"second",
"./dial/text_2.txt", NULL, {800, 600}, (sfColor){25, 145, 220, 255},
30, T_LOW};

static const text_data_scrolling_t DIALOGUE = {"dialogue",
"./dial/text_3.txt", NULL, {500, 700}, (sfColor){0, 0, 220, 255},
25, T_MEDIUM};

static const text_data_scrolling_t INV_NAME = {"inv_name",
NULL, "Name : ANTICONSTITUTIONELLEMENT", {1110, 250}, (sfColor){0, 0, 0, 255},
22, T_FULL};

static const text_data_scrolling_t INV_LVL = {"inv_lvl",
NULL, "Level : 99999999", {1098, 280}, (sfColor){0, 0, 0, 255}, 22, T_FULL};

static const text_data_scrolling_t INV_HEALTH = {"inv_health",
NULL, "Health : 999999999 / 999999999", {1050, 400}, (sfColor){0, 0, 0, 255},
22, T_FULL};

static const text_data_scrolling_t INV_XP = {"inv_xp",
NULL, "Experience : 9999999999 / 9999999999", {1030, 450},
(sfColor){0, 0, 0, 255}, 22, T_FULL};

static const text_data_scrolling_t INV_DAMAGE = {"inv_damage",
NULL, "999", {1072, 340}, (sfColor){0, 0, 0, 255}, 22, T_FULL};

static const text_data_scrolling_t INV_ARMOR = {"inv_armor",
NULL, "999", {1174, 340}, (sfColor){0, 0, 0, 255}, 22, T_FULL};

// CONST VARIABLE GENERATOR PARTICLE char *title, char *path_texture,
//char *path_sound, int nb_ptcl, int speed_max, sfVector2f scale,
//float gen_speed, float max_time, int age_max, sfVector2f position
static const gen_ptcl_data_t GEN_BLOOD = {"blood",
"./assets/particle-blue.png", NULL, 250, 30,
(sfVector2f){4.0, 4.0}, G_FAST, 5.0, 25, 1, 5, (sfVector2f){800, 500},
(gen_direction_t){1, 1, 1, 1}};

// FUNCTION PROTOYPE //
void handler_menu(head_t *head);
void init_menu_scenes(head_t *head);
void execute_fade_anim(head_t *head);
void start_fade_animation(head_t *head, void (*fade_f)(head_t*), state_t stat);

void game_event_manager(head_t *head);
map_t *load_map(head_t *head, char *name);

#endif /* !SCENES_H_ */