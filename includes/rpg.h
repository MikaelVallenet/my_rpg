/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Header
*/

#ifndef RPG_HEADER
#define RPG_HEADER

// // Includes // //

// CSFML
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

// Libs
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Include files
#include "my_lib.h"
typedef struct player_s player_t;

// Game infos
#define GAME_NAME "my_rpg"

// // Structures // //
// State
typedef enum state_s {
    STATE_MENU = 0,
    STATE_SETTING_MENU = 1,
    STATE_PAUSE_MENU = 2,
    STATE_LOAD_SAVE_MENU = 3,
    STATE_INGAME = 4,
    STATE_SELECT_PLAYER = 5,
    STATE_SKILL_TREE = 6,
    STATE_DUEL = 7,
    STATE_QUEST_MENU = 8,
} state_t;

typedef struct resources_s resources_t;
typedef struct button_s button_t;
typedef struct scenes_s scenes_t;

typedef struct engine_s {

} engine_t;

typedef struct technical_s {
    sfView *view;
    sfVector2f size_map;
    state_t state_2_ex;
    int index_save;
} technical_t;

typedef struct event_s {
    sfVector2f mouse_coords;
    sfKeyCode key_input;
} event_t;

typedef struct option_s {
    int max_fps;
    int sound_volume;
    int music_volume;
    sfVideoMode mode;
    sfBool automatic_resolution;
    sfBool fullscreen;
} option_t;

typedef struct head_s {
    engine_t *engine;
    technical_t *technical;
    event_t *event;
    option_t *option;
    resources_t *res;
    state_t state;
    state_t state_2;
    scenes_t *scenes;
    sfRenderWindow *window;
} head_t;

// // Prototype // //
// Window
int manage_windows(head_t *head);
int create_windows(head_t *head, option_t *option);

// Structures
head_t *head_initialize(int ac, char **av);
resources_t *res_initialize(head_t *head);
void main_destroy(head_t *head);
event_t *event_initialize(void);

void execute_global_animations(head_t *head);

// Event

// Includes
#include "quests.h"
#include "tools.h"
#include "game_engine.h"
#include "scenes/main_menu.h"
#include "scenes/setting_menu.h"
#include "scenes/pause_menu.h"
#include "scenes/load_save_menu.h"
#include "scenes/skill_tree.h"
#include "scenes/duel.h"
#include "scenes/quest_menu.h"
#include "player.h"
#include "npc.h"
#include "items.h"
#include "inventory.h"
#include "fight.h"
#include "scenes/in_game.h"
#include "scenes/select_player.h"
#include "scenes.h"
#include "resources.h"
#include "error.h"
#include "physics.h"
#include "save.h"
#include "view.h"

#endif /* !RPG_HEADER */