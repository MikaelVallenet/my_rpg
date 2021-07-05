/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** setting menu
*/

#ifndef SETTING_MENU_H_
#define SETTING_MENU_H_

#include "rpg.h"

// STRUCTURE //
typedef struct setting_menu_scene_s {
    object_t *object;
    button_t *button;
    text_t *text;
    text_scrolling_t *text_scrolling;
    gen_ptcl_t *gen_ptcl;
    object_t *music_bar;
    object_t *sound_bar;
    button_t *on_off_music;
    button_t *on_off_sound;
    button_t *on_off_fullscreen;
    button_t *quit_setting;
    button_t *framerate_30;
    button_t *framerate_60;
    button_t *framerate_90;
    button_t *framerate_select;
} setting_menu_scene_t;

// FUNCTION PROTOTYPE //
void init_setting_menu(head_t *head);
void destroy_setting_menu(scenes_t *scene);
void setting_menu_handler(head_t *head);
void setting_menu_display(head_t *head);
void setting_menu_event(head_t *head, sfEvent event);
void init_object_setting(head_t *head, setting_menu_scene_t *menu);
void init_button_setting(head_t *head, setting_menu_scene_t *menu);
void init_text_setting(head_t *head, setting_menu_scene_t *menu);

// UPDATE //
void update_button_framerate_setting(head_t *head, setting_menu_scene_t *menu);

// BUTTON FUNCTION //
void on_off_music_setting(head_t *head, button_t *button);
void raise_music_volume_setting(head_t *head, button_t *button);
void reduce_music_volume_setting(head_t *head, button_t *button);
void quit_setting(head_t *head, button_t *button);
void switch_fullscreen_setting(head_t *head, button_t *button);
void on_off_sound_setting(head_t *head, button_t *button);
void reduce_sound_volume_setting(head_t *head, button_t *button);
void raise_sound_volume_setting(head_t *head, button_t *button);
void set_framerate_30_window(head_t *head, button_t *button);
void set_framerate_60_window(head_t *head, button_t *button);
void set_framerate_90_window(head_t *head, button_t *button);

// MUSIC BUTTON //
static const button_data_t QUIT_SETTING =
{{(1920 / 2) - (1277 * 0.9 / 2) - 30,
(1080 / 2) - (1019 * 0.9 / 2) - 30},
{0.7, 0.7}, SQUARE,
"assets/buttons/button_left.png",
"", 20, (sfColor){255, 255, 255, 255},
"", 20, (sfColor){255, 255, 255, 255},
&quit_setting
};

static const button_data_t MUSIC_ON_OFF_SETTING =
{{(1920 / 2) - (421 * 1.2) - 15 + 280,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 170},
{1.2, 1.2}, SQUARE,
"assets/buttons/button_on.png",
"", 20, (sfColor){255, 255, 255, 255},
"", 20, (sfColor){255, 255, 255, 255},
&on_off_music_setting
};

static const button_data_t MUSIC_REDUCE_VOLUME_SETTING =
{{(1920 / 2) - (421 * 1.2) - 15 + 55,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 300},
{0.8, 0.8}, CIRCLE,
"assets/buttons/button_minus.png",
"", 20, (sfColor){255, 255, 255, 255},
"Reduce Volume", 20, (sfColor){255, 255, 255, 255},
&reduce_music_volume_setting
};

static const button_data_t MUSIC_RAISE_VOLUME_SETTING =
{{(1920 / 2) - (421 * 1.2) - 15 + 405,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 300},
{0.8, 0.8}, CIRCLE,
"assets/buttons/button_plus.png",
"", 20, (sfColor){255, 255, 255, 255},
"Raise Volume", 20, (sfColor){255, 255, 255, 255},
&raise_music_volume_setting
};

// SOUND BUTTON //
static const button_data_t SOUND_ON_OFF_SETTING =
{{(1920 / 2) - (421 * 1.2) - 15 + 280,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 430},
{1.2, 1.2}, SQUARE,
"assets/buttons/button_on.png",
"", 20, (sfColor){255, 255, 255, 255},
"", 20, (sfColor){255, 255, 255, 255},
&on_off_sound_setting
};

static const button_data_t SOUND_REDUCE_VOLUME_SETTING =
{{(1920 / 2) - (421 * 1.2) - 15 + 55,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 560},
{0.8, 0.8}, CIRCLE,
"assets/buttons/button_minus.png",
"", 20, (sfColor){255, 255, 255, 255},
"Reduce Volume", 20, (sfColor){255, 255, 255, 255},
&reduce_sound_volume_setting
};

static const button_data_t SOUND_RAISE_VOLUME_SETTING =
{{(1920 / 2) - (421 * 1.2) - 15 + 405,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 560},
{0.8, 0.8}, CIRCLE,
"assets/buttons/button_plus.png",
"", 20, (sfColor){255, 255, 255, 255},
"Raise Volume", 20, (sfColor){255, 255, 255, 255},
&raise_sound_volume_setting
};

// DISPLAY BUTTON //

static const button_data_t FULLSCREEN_ON_OFF_SETTING =
{{(1920 / 2) + 15 + 310,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 170},
{1.2, 1.2}, SQUARE,
"assets/buttons/button_on.png",
"", 20, (sfColor){255, 255, 255, 255},
"", 20, (sfColor){255, 255, 255, 255},
&switch_fullscreen_setting
};

static const button_data_t SET_FRAMERATE_30_SETTING =
{{(1920 / 2) - (421 * 1.2) - 15 + 550,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 407},
{0.65, 0.65}, SQUARE,
"assets/buttons/button_empty_30.png",
"", 40, (sfColor){255, 255, 255, 255},
"", 20, (sfColor){255, 255, 255, 255},
&set_framerate_30_window
};

static const button_data_t SET_FRAMERATE_60_SETTING =
{{(1920 / 2) - (421 * 1.2) - 15 + 550 + 165,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 407},
{0.65, 0.65}, SQUARE,
"assets/buttons/button_empty_60.png",
"", 40, (sfColor){255, 255, 255, 255},
"", 20, (sfColor){255, 255, 255, 255},
&set_framerate_60_window
};

static const button_data_t SET_FRAMERATE_90_SETTING =
{{(1920 / 2) - (421 * 1.2) - 15 + 550 + 330,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 407},
{0.65, 0.65}, SQUARE,
"assets/buttons/button_empty_90.png",
"", 40, (sfColor){255, 255, 255, 255},
"", 20, (sfColor){255, 255, 255, 255},
&set_framerate_90_window
};

// OBJECT PRESET //
static const object_data_t TABLE_SETTING =
{"assets/images/table/table_big.png",
{(1920 / 2) - (1277 * 0.9 / 2),
(1080 / 2) - (1019 * 0.9 / 2)},
{0.9, 0.9}
};

static const object_data_t HEADER_SETTING =
{"assets/images/header/header_settings.png",
{763, 45},
{1, 1}
};

static const object_data_t WINDOW_LEFT_SETTING =
{"assets/images/window/window_1.png",
{(1920 / 2) - (421 * 1.2) - 15,
(1080 / 2) - (464 * 1.5 / 2) + 25},
{1.2, 1.50}
};

static const object_data_t WINDOW_RIGHT_SETTING =
{"assets/images/window/window_1.png",
{(1920 / 2) + 15, (1080 / 2) - (464 * 1.5 / 2) + 25},
{1.2, 1.50}
};

// MUSIC BAR //
static const object_data_t BAR_MUSIC_BG_SETTING =
{"assets/images/bar_1/bg_bar.png",
{(1920 / 2) - (421 * 1.2) - 15 + 65,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 300},
{1, 1}
};

static const object_data_t BAR_MUSIC_SETTING =
{"assets/images/bar_1/bar_2.png",
{(1920 / 2) - (421 * 1.2) - 15 + 73,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 307},
{1.123, 0.97}
};

// SOUND BAR //
static const object_data_t BAR_SOUND_BG_SETTING =
{"assets/images/bar_1/bg_bar.png",
{(1920 / 2) - (421 * 1.2) - 15 + 65,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 560},
{1, 1}
};

static const object_data_t BAR_SOUND_SETTING =
{"assets/images/bar_1/bar_2.png",
{(1920 / 2) - (421 * 1.2) - 15 + 73,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 567},
{1.123, 0.97}
};

// TEXT PRESET //
static const text_data_t TEXT_SETTING_AUDIO =
{"assets/fonts/Dimbo.ttf",
"Audio",
100,
{(1920 / 2) - (421 * 1.2) - 15 + 160,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 10},
(sfColor){255, 255, 255, 255}
};

static const text_data_t TEXT_SETTING_MUSIC =
{"assets/fonts/Dimbo.ttf",
"Music",
80,
{(1920 / 2) - (421 * 1.2) - 15 + 80,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 150},
(sfColor){255, 255, 255, 255}
};

static const text_data_t TEXT_SETTING_SOUND =
{"assets/fonts/Dimbo.ttf",
"Sound",
80,
{(1920 / 2) - (421 * 1.2) - 15 + 80,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 410},
(sfColor){255, 255, 255, 255}
};

static const text_data_t TEXT_SETTING_DISPLAY =
{"assets/fonts/Dimbo.ttf",
"Display",
100,
{(1920 / 2) - (421 * 1.2) - 15 + 680,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 10},
(sfColor){255, 255, 255, 255}
};

static const text_data_t TEXT_SETTING_FULLSCREEN =
{"assets/fonts/Dimbo.ttf",
"Fullscreen",
80,
{(1920 / 2) + 15 + 20,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 150},
(sfColor){255, 255, 255, 255}
};

static const text_data_t TEXT_SETTING_FRAMERATE =
{"assets/fonts/Dimbo.ttf",
"Framerate",
80,
{(1920 / 2) - (421 * 1.2) - 15 + 650,
(1080 / 2) - (464 * 1.5 / 2) + 25 + 307},
(sfColor){255, 255, 255, 255}
};

#endif /* !SETTING_MENU_H_ */