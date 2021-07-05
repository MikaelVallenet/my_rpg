/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** world
*/

#ifndef WORLD_H_
#define WORLD_H_

#include "rpg.h"
#include "quests.h"

#define TILED_MAP_FILE "./resources/maps/"
#define QUEST_FILEPATH "./resources/quests/"
#define CONV_FP "./resources/conversation/"
#define MUSIC "./assets/music/"
#define NPC "./resources/npc/"
#define CREATE_ERROR show_error("Error: Can't create file")


#define FIRST_VILLAGE "./resources/maps/first_village.json"
#define HOUSE "./resources/maps/house.json"
#define MAIRIE "./resources/maps/Mairie.json"
#define HOUSE_4 "./resources/maps/house_4.json"

// Prototype callback
void end_of_main_quest(head_t *head);
void chest_one(head_t *head);
void chest_two(head_t *head);
void chest_three(head_t *head);
void chest_four(head_t *head);
void trigger_cave(head_t *head);
void chest_five(head_t *head);

// // Event // //
typedef struct event_switch_s {
    char *name;
    void (*event_func)(head_t *);
    sfVector2f pos;
    char *map_name;
    sfBool needs_to_click;
    sfBool activated;
} event_switch_t;

static const event_switch_t GLOBAL_EVENT[] = {
    {"EnterInfirmary", NULL, {330, 430}, "infirmary.json", 1, 1},
    {"ExitInfirmary", NULL, {3780, 3790}, "first_village.json", 1, 1},
    {"EnterMairie", NULL, {590, 720}, "Mairie.json", 1, 1},
    {"ExitMairie", NULL, {1700, 2580}, "first_village.json", 1, 1},
    {"EnterHouse", NULL, {270, 490}, "house.json", 1, 1},
    {"ExitHouse", NULL, {3280, (5060)}, "first_village.json", 1, 1},
    {"EnterHouse_2", NULL, {390, 510}, "house_2.json", 1, 1},
    {"ExitHouse_2", NULL, {4010, 6470}, "first_village.json", 1, 1},
    {"EnterHouse_3", NULL, {270, 490}, "house_3.json", 1, 1},
    {"ExitHouse_3", NULL, {7500, 3740}, "first_village.json", 1, 1},
    {"EnterHouse_4", NULL, {390, 510}, "house_4.json", 1, 1},
    {"ExitHouse_4", NULL, {8380, 4820}, "first_village.json", 1, 1},
    {"Enter_TheMine", trigger_cave, {2353 * 4, 610 * 4},
    "the_cave.json", 1, 1},
    {"Enter_DeepCave", NULL, {1166 * 4, 968 * 4}, "the_deep_cave.json", 1, 1},
    {"ExitCave", NULL, {48 * 4, 1329 * 4}, "first_village.json", 1, 1},
    {"AscendCave", NULL, {1995 * 4, 360 * 4}, "the_cave.json", 1, 1},
    {"AscendDeepCave", NULL, {356 * 4, 950 * 4}, "the_deep_cave.json", 1, 1},
    {"EnterLavaCave", NULL, {424 * 4, 496 * 4}, "lava_cave.json", 1, 1},
    {"StartFight", end_of_main_quest, {-1, -1}, NULL, 1, 1},
    {"ExitTheCave", NULL, {34 * 4, 1311 * 4}, "first_village.json", 1, 1},
    {"TP_1", NULL, {1340 * 4, 1356 * 4}, NULL, 1, 1},
    {"TP_2", NULL, {1128 * 4, 1368 * 4}, NULL, 1, 1},
    {"TP_3", NULL, {363 * 4, 557 * 4}, NULL, 1, 1},
    {"TP_4", NULL, {1165 * 4, 575 * 4}, NULL, 1, 1},
    {"TP_5", NULL, {1375 * 4, 910 * 4}, NULL, 1, 1},
    {"TP_6", NULL, {904 * 4, 908 * 4}, NULL, 1, 1},
    {"TP_7", NULL, {1448 * 4, 158 * 4}, NULL, 1, 1},
    {"TP_8", NULL, {1055 * 4, 175 * 4}, NULL, 1, 1},
    {"TP_9", NULL, {1435 * 4, 1326 * 4}, NULL, 1, 1},
    {"TP_10", NULL, {1435 * 4, 1389 * 4}, NULL, 1, 1},
    {"TP_11", NULL, {110 * 4, 893 * 4}, NULL, 1, 1},
    {"TP_12", NULL, {75 * 4, 155 * 4}, NULL, 1, 1},
    {"TP_13", NULL, {571 * 4, 892 * 4}, NULL, 1, 1},
    {"TP_14", NULL, {317 * 4, 1339 * 4}, NULL, 1, 1},
    {"TP_15", NULL, {623 * 4, 1342 * 4}, NULL, 1, 1},
    {"CHEST_1", chest_one, {-1, -1}, NULL, 1, 1},
    {"CHEST_2", chest_two, {-1, -1}, NULL, 1, 1},
    {"CHEST_3", chest_three, {-1, -1}, NULL, 1, 1},
    {"CHEST_4", chest_four, {-1, -1}, NULL, 1, 1},
    {"CHEST_5", chest_five, {-1, -1}, NULL, 1, 1},
    {.name = NULL}
};

/*
static const event_switch_t FIRST_VILLAGE_EVENT[] = {
    {"EnterPharm", NULL, {270, 500}, "house.json", 1, 0}
};*/

typedef struct npc_switch_s {
    char *map_name;
    char *npc_json;
} npc_switch_t;

static const npc_switch_t GLOBAL_NPC[] = {
    {MAIRIE, NPC"caroline.json"},
    {MAIRIE, NPC"lewis.json"},
    {HOUSE_4, NPC"clint.json"},
    {FIRST_VILLAGE, NPC"jas.json"},
    {NULL, NULL}
};

typedef struct music_switch_s {
    char *map_name;
    char *filepath;
} music_switch_t;

static const music_switch_t GLOBAL_MUSIC[] = {
    {FIRST_VILLAGE, "./assets/village.ogg"},
    {"./resources/maps/the_deep_cave.json", "./assets/mines.ogg"},
    {"resources/maps/infirmary.json", "./assets/village.ogg"},
    {NULL, NULL}
};

// Pars map //
// Structures
typedef struct pars_res_info_s {
    int column;
    char *file_path;
    int image_height;
    int image_width;
    int tile_height;
    int tile_width;
    int tile_count;
    pars_data_t *data;
} pars_res_info_t;

typedef struct pars_map_s {
    pars_obj_t *obj;
    pars_data_t *data;
    pars_data_t *tilesets;
    pars_data_t *layers;
    int height;
    int width;
    int tile_height;
    int tile_width;
} pars_map_t;

// Prototype
pars_res_info_t *load_tileset(pars_data_t *obj);
int tileset_len(pars_data_t *obj);
int pars_obj_len(pars_data_t *obj);
pars_res_info_t *load_pars_res(pars_data_t *obj);
void destroy_tileset(pars_res_info_t *info);
void set_npc_conversation(head_t *head, quest_t *cur);
int add_to_quest(quest_t *quest,
char *quest_name, char *objective_name, int nb);

// Prototype
map_t *pars_map_sprite_init(sfTexture **texture, pars_map_t *map);
int event_layers(pars_data_t *data, map_t *map);
map_t *map_t_init(sfTexture **textures, pars_map_t *pmap);
void unload_map_t(map_t *map);
void switch_map(head_t *head, in_game_t *game, char *map_name, sfVector2f pos);
void event_launch(head_t *head, event_switch_t event);
event_switch_t event_finder(game_event_t *event, char *event_name);
quest_event_t **init_event(pars_data_t *data);
quest_objective_t **init_objective(pars_data_t *data);
awards_t **init_awards(pars_data_t *data);
void destroy_quest(quest_t *quest);

#endif /* !WORLD_H_ */
