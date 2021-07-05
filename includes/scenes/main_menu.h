/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** scenes
*/

#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_

#include "rpg.h"

typedef struct head_s head_t;

// STRUCTURE //
typedef struct main_menu_scene_s {
    object_t *object;
    button_t *button;
    text_t *text;
    text_scrolling_t *text_scrolling;
    gen_ptcl_t *gen_ptcl;
} main_menu_scene_t;

// FUNCTION PROTOTYPE //
void init_main_menu(head_t *head);
void destroy_main_menu(scenes_t *scene);
void main_menu_handler(head_t *head);
void main_menu_display(head_t *head);
void main_menu_event(head_t *head, sfEvent event);
void open_setting(head_t *head, button_t *button);

// BUTTON FUNCTION //
void switch_music_menu(head_t *head, button_t *button);
void switch_sound_menu(head_t *head, button_t *button);
void close_window(head_t *head, button_t *button);
void launch_game_function(head_t *head, button_t *button);

// BUTTON PRESET //
static const button_data_t PLAY_BUTTON = {{1920 / 2 - 120, 1080 / 2 - 100},
{0.65, 0.65}, CIRCLE,
"assets/buttons/play.png",
"", 20, (sfColor){255, 255, 255, 255},
"Launch Game", 20, (sfColor){255, 255, 255, 255},
&launch_game_function};

static const button_data_t QUIT_BUTTON = {{1835, 15}, {0.7, 0.7}, CIRCLE,
"assets/buttons/close.png",
"", 20, (sfColor){255, 255, 255, 255},
"Quit Game", 20, (sfColor){255, 255, 255, 255},
&close_window};

static const button_data_t MUSIC_BUTTON = {{15, 15}, {0.7, 0.7}, SQUARE,
"assets/buttons/music_on.png",
"", 20, (sfColor){255, 255, 255, 255},
"Cut Music", 20, (sfColor){255, 255, 255, 255},
&switch_music_menu};

static const button_data_t SOUND_BUTTON = {{140, 15}, {0.7, 0.7}, SQUARE,
"assets/buttons/sound_on.png",
"", 20, (sfColor){255, 255, 255, 255},
"Cut Sound Effect", 20, (sfColor){255, 255, 255, 255},
&switch_sound_menu};

static const button_data_t SETTING_BUTTON = {{265, 15}, {0.7, 0.7}, SQUARE,
"assets/buttons/setting.png",
"", 20, (sfColor){255, 255, 255, 255},
"Open Settings", 20, (sfColor){255, 255, 255, 255},
&open_setting};

// OBJECT PRESET //
static const object_data_t BACKGROUND_OBJECT = {"assets/images/bg.png",
{0, 0}, {1, 1}};

static const object_data_t BACKGROUND_DARK_OBJECT = {"assets/images/dark.png",
{0, 0}, {1, 1}};

static const object_data_t LOGO_OBJECT = {"assets/images/logo.png",
{1920 / 2 - 708, 1080 / 2 - 398 - 200}, {1.2, 1.2}};

#endif /* !MAIN_MENU_H_ */