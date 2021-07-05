/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** in_game
*/

#ifndef SELECT_PLAYER_H_
#define SELECT_PLAYER_H_

#include "rpg.h"

typedef struct select_player_s {
    object_t *object;
    button_t *button;
    text_t *text;
    text_scrolling_t *text_scrolling;
    gen_ptcl_t *gen_ptcl;
    button_t *alex_button;
    button_t *elliot_button;
    button_t *haley_button;
    button_t *maru_button;
} select_player_t;

// FUNCTION //
void destroy_select_player_scenes(scenes_t *scenes);
void init_select_player_scenes(head_t *head);
void select_player_event(head_t *head, sfEvent event);
void select_player_handler(head_t *head);
void select_player_display(head_t *head);

// FUNCTION INIT //
void create_button_face(head_t *head, select_player_t *menu);
void create_object_appearance(head_t *head, select_player_t *menu);
void create_object_name(head_t *head, select_player_t *menu);

// EVENT //

// FUNCTION BUTTON //
void launch_game(head_t *head, button_t *button);
void quit_select_player(head_t *head, button_t *button);

// RECT BUTTON //
static const sfIntRect ALEX_FACE_RECT = {106, 1, 76, 75};
static const sfIntRect ELLIOT_FACE_RECT = {106, 77, 76, 75};
static const sfIntRect HALEY_FACE_RECT = {106, 1, 76, 75};
static const sfIntRect MARU_FACE_RECT = {106, 77, 76, 75};
static const sfIntRect ALEX_APPEARANCE_RECT = {22, 16, 14, 29};
static const sfIntRect ELLIOT_APPEARANCE_RECT = {23, 16, 14, 29};
static const sfIntRect HALEY_APPEARANCE_RECT = {21, 52, 16, 26};
static const sfIntRect MARU_APPEARANCE_RECT = {21, 52, 14, 26};
static const sfIntRect ALEX_NAME_RECT = {2, 437, 103, 19};
static const sfIntRect ELLIOT_NAME_RECT = {2, 437, 103, 19};
static const sfIntRect HALEY_NAME_RECT = {2, 437, 103, 19};
static const sfIntRect MARU_NAME_RECT = {2, 437, 103, 19};

// BUTTON PRESET //
static const button_data_t ALEX_BUTTON = {{400, 100}, {4, 4}, SQUARE,
"assets/character/alex.png",
"", 20, (sfColor){255, 255, 255, 255},
"", 20, (sfColor){255, 255, 255, 255},
&launch_game};

static const button_data_t ELLIOT_BUTTON = {{1216, 100}, {4, 4}, SQUARE,
"assets/character/elliot.png",
"", 20, (sfColor){255, 255, 255, 255},
"", 20, (sfColor){255, 255, 255, 255},
&launch_game};

static const button_data_t HALEY_BUTTON = {{400, 600}, {4, 4}, SQUARE,
"assets/character/haley.png",
"", 20, (sfColor){255, 255, 255, 255},
"", 20, (sfColor){255, 255, 255, 255},
&launch_game};

static const button_data_t MARU_BUTTON = {{1216, 600}, {4, 4}, SQUARE,
"assets/character/maru.png",
"", 20, (sfColor){255, 255, 255, 255},
"", 20, (sfColor){255, 255, 255, 255},
&launch_game};

static const button_data_t QUIT_SELECT_PLAYER =
{{10, 10},
{0.7, 0.7}, SQUARE,
"assets/buttons/button_left.png",
"", 20, (sfColor){255, 255, 255, 255},
"", 20, (sfColor){255, 255, 255, 255},
&quit_select_player
};

// OBJECT PRESET //
static const object_data_t BACKGROUND_SELECT_PLAYER =
{"assets/images/bg_mountains.png",
{0, 0}, {1, 1}};

static const object_data_t ALEX_APPEARANCE =
{"assets/character/alex.png",
{300, 200},
{4, 4}
};

static const object_data_t ELLIOT_APPEARANCE =
{"assets/character/elliot.png",
{1116, 200},
{4, 4}
};

static const object_data_t HALEY_APPEARANCE =
{"assets/character/haley.png",
{300, 700},
{4, 4}
};

static const object_data_t MARU_APPEARANCE =
{"assets/character/maru.png",
{1116, 700},
{4, 4}
};

static const object_data_t ALEX_NAME =
{"assets/character/alex.png",
{346, 415},
{4, 4}
};

static const object_data_t ELLIOT_NAME =
{"assets/character/elliot.png",
{1162, 415},
{4, 4}
};

static const object_data_t HALEY_NAME =
{"assets/character/haley.png",
{346, 915},
{4, 4}
};

static const object_data_t MARU_NAME =
{"assets/character/maru.png",
{1162, 915},
{4, 4}
};

// TEXT PRESET //
static const text_data_t CHOOSE_CHARACTER =
{"assets/fonts/Dimbo.ttf",
"Choose your character",
100,
{(1920 / 2) - (421 * 1.2) - 15 + 160,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 260},
(sfColor){91, 97, 138, 255}
};

#endif /* !SELECT_PLAYER_H_ */