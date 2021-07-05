/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** quest_menu
*/

#ifndef QUEST_MENU_H_
#define QUEST_MENU_H_

#include "rpg.h"

// STRUCTURE //
typedef struct quest_menu_s {
    object_t *object;
    button_t *button;
    text_t *text;
    text_scrolling_t *text_scrolling;
    gen_ptcl_t *gen_ptcl;
} quest_menu_t;

// FUNCTION PROTOTYPE //
void init_quest_menu(head_t *head);
void destroy_quest_menu(scenes_t *scene);
void quest_menu_handler(head_t *head);
void quest_menu_display(head_t *head);
void quest_menu_event(head_t *head, sfEvent event);
void init_text_quest_menu(head_t *head, quest_menu_t *menu);
void text_name_quest(quest_menu_t *menu, quest_t *quest, sfVector2f pos);
void text_desc_quest(quest_menu_t *menu, quest_t *quest, sfVector2f pos);
void text_type_quest(quest_menu_t *menu, quest_t *quest, sfVector2f pos);
void text_award_quest(quest_menu_t *menu, quest_t *quest, sfVector2f pos);
void text_step_quest(quest_menu_t *menu, quest_t *quest, sfVector2f pos);

// BUTTON FUNCTION //
void open_quest_menu(head_t *head, button_t *button);
void quit_quest_menu(head_t *head, button_t *button);

// BUTTON PRESET //
// static const button_data_t RESUME_BUTTON_PAUSE =
// {{(1920 / 2) - (331 * 0.75 / 2),
// (1080 / 2) - (329 * 0.75 / 2) + 0},
// {0.75, 0.75}, CIRCLE,
// "assets/buttons/play.png",
// "", 20, (sfColor){255, 255, 255, 255},
// "Resume Game", 20, (sfColor){255, 255, 255, 255},
// &resume_game};

// OBJECT PRESET //
static const object_data_t TABLE_QUEST_MENU =
{"assets/images/table/table_1.png",
{(1920 / 2) - (639 * 1.3 / 2),
(1080 / 2) - (801 * 1.3 / 2)},
{1.3, 1.3}
};

static const object_data_t QUEST_1 =
{"assets/images/window/large_window.png",
{(1920 / 2) - (438 * 1.5 / 2),
(1080 / 2) - (130 * 1.3 / 2) - 250},
{1.5, 1.75}
};

static const object_data_t QUEST_2 =
{"assets/images/window/large_window.png",
{(1920 / 2) - (438 * 1.5 / 2),
(1080 / 2) - (130 * 1.3 / 2) + 15},
{1.5, 1.75}
};

static const object_data_t QUEST_3 =
{"assets/images/window/large_window.png",
{(1920 / 2) - (438 * 1.5 / 2),
(1080 / 2) - (130 * 1.0 / 2) + 265},
{1.5, 1.75}
};

// TEXT PRESET //
static const text_data_t TEXT_QUEST_MENU =
{"assets/fonts/Dimbo.ttf",
"Quest", 110,
{(1920 / 2) - (639 * 1.3 / 2) + 310,
(1080 / 2) - (801 * 1.3 / 2) + 30},
(sfColor){255, 255, 255, 255}};

#endif /* !QUEST_MENU_H_ */