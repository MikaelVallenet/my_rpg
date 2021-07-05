/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** pause menu
*/

#ifndef PAUSE_MENU_H_
#define PAUSE_MENU_H_

#include "rpg.h"

// STRUCTURE //
typedef struct pause_menu_scene_s {
    object_t *object;
    button_t *button;
    text_t *text;
    text_scrolling_t *text_scrolling;
    gen_ptcl_t *gen_ptcl;
} pause_menu_scene_t;

// FUNCTION PROTOTYPE //
void init_pause_menu(head_t *head);
void destroy_pause_menu(scenes_t *scene);
void pause_menu_handler(head_t *head);
void pause_menu_display(head_t *head);
void pause_menu_event(head_t *head, sfEvent event);

// BUTTON FUNCTION //
void open_setting_pause(head_t *head, button_t *button);
void button_save_game(head_t *head, button_t *button);
void resume_game(head_t *head, button_t *button);
void return_to_menu(head_t *head, button_t *button);

// BUTTON PRESET //
static const button_data_t RESUME_BUTTON_PAUSE =
{{(1920 / 2) - (331 * 0.75 / 2),
(1080 / 2) - (329 * 0.75 / 2) + 0},
{0.75, 0.75}, CIRCLE,
"assets/buttons/play.png",
"", 20, (sfColor){255, 255, 255, 255},
"Resume Game", 20, (sfColor){255, 255, 255, 255},
&resume_game};

static const button_data_t MENU_BUTTON_PAUSE =
{{(1920 / 2) - (176 * 1 / 2) - 270,
(1080 / 2) - (175 * 1 / 2) + 0},
{1, 1}, SQUARE,
"assets/buttons/button_left.png",
"", 20, (sfColor){255, 255, 255, 255},
"Return to menu", 20, (sfColor){255, 255, 255, 255},
&return_to_menu};

static const button_data_t QUIT_BUTTON_PAUSE =
{{(1920 / 2) - (176 * 1 / 2) + 275,
(1080 / 2) - (175 * 1 / 2) + 0},
{1, 1}, SQUARE,
"assets/buttons/button_exit.png",
"", 20, (sfColor){255, 255, 255, 255},
"Quit game", 20, (sfColor){255, 255, 255, 255},
&close_window};

static const button_data_t SAVE_BUTTON_PAUSE =
{{(1920 / 2) - (176 * 1 / 2) - 140,
(1080 / 2) - (175 * 1 / 2) + 190},
{0.8, 0.8}, SQUARE,
"assets/buttons/button_save.png",
"", 70, (sfColor){255, 255, 255, 255},
"", 20, (sfColor){255, 255, 255, 255},
&button_save_game};

static const button_data_t SETTING_BUTTON_PAUSE =
{{(1920 / 2) - (176 * 1 / 2) + 170,
(1080 / 2) - (175 * 1 / 2) + 190},
{0.8, 0.8}, SQUARE,
"assets/buttons/setting.png",
"", 70, (sfColor){255, 255, 255, 255},
"", 20, (sfColor){255, 255, 255, 255},
&open_setting_pause};

// OBJECT PRESET //
static const object_data_t TABLE_PAUSE =
{"assets/images/table/table_medium.png",
{(1920 / 2) - (966 * 0.9 / 2),
(1080 / 2) - (627 * 0.9 / 2)},
{0.9, 0.9}
};

static const object_data_t ROPE_LEFT_PAUSE =
{"assets/images/rope_big.png",
{(1920 / 2) - (966 * 0.9 / 2) + 200,
0},
{0.8, 0.8}
};

static const object_data_t ROPE_RIGHT_PAUSE =
{"assets/images/rope_big.png",
{(1920 / 2) - (966 * 0.9 / 2) + 630,
0},
{0.8, 0.8}
};

// TEXT PRESET //
static const text_data_t TEXT_PAUSE =
{"assets/fonts/Dimbo.ttf",
"PAUSE", 110,
{(1920 / 2) - (331 * 0.65 / 2) - 10,
(1080 / 2) - (329 * 0.65 / 2) - 150},
(sfColor){255, 255, 255, 255}};

#endif /* !PAUSE_MENU_H_ */