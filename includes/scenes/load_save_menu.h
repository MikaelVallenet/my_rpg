/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** setting menu
*/

#ifndef LOAD_SAVE_MENU_H_
#define LOAD_SAVE_MENU_H_

#include "rpg.h"

// FUNCTION PROTOTYPE //
void init_load_save_menu(head_t *head);
void destroy_load_save_menu(scenes_t *scene);
void load_save_menu_handler(head_t *head);
void load_save_menu_display(head_t *head);
void load_save_menu_event(head_t *head, sfEvent event);
void update_load_save_menu(head_t *head);

// // STRUCTURE // //
typedef struct load_save_menu_scene_s {
    object_t *object;
    button_t *button;
    text_t *text;
    text_scrolling_t *text_scrolling;
    gen_ptcl_t *gen_ptcl;
    button_t *first_save_button;
    button_t *second_save_button;
    button_t *third_save_button;
    button_t *delete_first_save;
    button_t *delete_second_save;
    button_t *delete_third_save;
} load_save_menu_scene_t;

// FUNCTION //
void init_text_name_save(load_save_menu_scene_t *menu,
sfVector2f pos, char *path);
void init_text_progression_save(load_save_menu_scene_t *menu,
sfVector2f pos, char *path);
void init_text_time_save(load_save_menu_scene_t *menu,
sfVector2f pos, char *path);
void load_save(head_t *head, char *path);
void launch_save(head_t *head, button_t *button);

// TEXT SAVE //
void init_text_first_save(head_t *head, load_save_menu_scene_t *menu);
void init_text_second_save(head_t *head, load_save_menu_scene_t *menu);
void init_text_third_save(head_t *head, load_save_menu_scene_t *menu);
void init_text_load_save_menu(head_t *head, load_save_menu_scene_t *menu);

// FUNCTION BUTTON //
void launch_save(head_t *head, button_t *button);
void delete_save_button(head_t *head, button_t *button);

// BUTTON PRESET //
static const button_data_t FIRST_SAVE = {{1920 / 2 - 483, 1080 / 2 - 450},
{1, 0.4}, SQUARE,
"assets/images/table/table_medium.png",
"", 20, (sfColor){255, 255, 255, 255},
"", 20, (sfColor){255, 255, 255, 255},
&launch_save};

static const button_data_t SECOND_SAVE = {{1920 / 2 - 483, 390},
{1, 0.4}, SQUARE,
"assets/images/table/table_medium.png",
"", 20, (sfColor){255, 255, 255, 255},
"", 20, (sfColor){255, 255, 255, 255},
&launch_save};

static const button_data_t THIRD_SAVE = {{1920 / 2 - 483, 690},
{1, 0.4}, SQUARE,
"assets/images/table/table_medium.png",
"", 20, (sfColor){255, 255, 255, 255},
"", 20, (sfColor){255, 255, 255, 255},
&launch_save};

static const button_data_t DELETE_FIRST_SAVE = {
{1920 / 2 - 483 + 970, 1080 / 2 - 450 + 40},
{1, 1}, SQUARE,
"assets/buttons/button_delete.png",
"", 20, (sfColor){255, 255, 255, 255},
"Delete save", 20, (sfColor){255, 255, 255, 255},
&delete_save_button};

static const button_data_t DELETE_SECOND_SAVE = {
{1920 / 2 - 483 + 970, 390 + 40},
{1, 1}, SQUARE,
"assets/buttons/button_delete.png",
"", 20, (sfColor){255, 255, 255, 255},
"Delete save", 20, (sfColor){255, 255, 255, 255},
&delete_save_button};

static const button_data_t DELETE_THIRD_SAVE = {
{1920 / 2 - 483 + 970, 690 + 40},
{1, 1}, SQUARE,
"assets/buttons/button_delete.png",
"", 20, (sfColor){255, 255, 255, 255},
"Delete save", 20, (sfColor){255, 255, 255, 255},
&delete_save_button};

// TEXT PRESET //
static const text_data_t EMPTY_SAVE_1_TEXT = {"assets/fonts/Dimbo.ttf",
"EMPTY", 130, {1920 / 2 - 483 + 330, 1080 / 2 - 450 + 40},
(sfColor){255, 255, 255, 255}};

static const text_data_t EMPTY_SAVE_2_TEXT = {"assets/fonts/Dimbo.ttf",
"EMPTY", 130, {1920 / 2 - 483 + 330, 1080 / 2 - 450 + 340},
(sfColor){255, 255, 255, 255}};

static const text_data_t EMPTY_SAVE_3_TEXT = {"assets/fonts/Dimbo.ttf",
"EMPTY", 130, {1920 / 2 - 483 + 330, 1080 / 2 - 450 + 640},
(sfColor){255, 255, 255, 255}};

static const button_data_t QUIT_LOAD_SAVE =
{{10, 10},
{0.7, 0.7}, SQUARE,
"assets/buttons/button_left.png",
"", 20, (sfColor){255, 255, 255, 255},
"", 20, (sfColor){255, 255, 255, 255},
&quit_setting
};

#endif /* !SETTING_MENU_H_ */