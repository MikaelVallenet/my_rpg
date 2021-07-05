/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init main menu
*/

#include "rpg.h"

void update_button_bar_setting(head_t *head, setting_menu_scene_t *menu)
{
    update_bar_music(head, menu->music_bar);
    update_bar_sound(head, menu->sound_bar);
    update_button_fullscreen(head, menu->on_off_fullscreen);
    update_button_on_off_music(head, menu->on_off_music);
    update_button_on_off_music(head, menu->on_off_sound);
    update_button_framerate_setting(head, menu);
}

void init_button_setting(head_t *head, setting_menu_scene_t *menu)
{
    create_button(head, MUSIC_ON_OFF_SETTING, &menu->button);
    menu->on_off_music = get_last_button(menu->button);
    create_button(head, MUSIC_REDUCE_VOLUME_SETTING, &menu->button);
    create_button(head, MUSIC_RAISE_VOLUME_SETTING, &menu->button);
    create_button(head, SOUND_ON_OFF_SETTING, &menu->button);
    menu->on_off_sound = get_last_button(menu->button);
    create_button(head, SOUND_REDUCE_VOLUME_SETTING, &menu->button);
    create_button(head, SOUND_RAISE_VOLUME_SETTING, &menu->button);
    create_button(head, QUIT_SETTING, &menu->button);
    menu->quit_setting = get_last_button(menu->button);
    create_button(head, FULLSCREEN_ON_OFF_SETTING, &menu->button);
    menu->on_off_fullscreen = get_last_button(menu->button);
    create_button(head, SET_FRAMERATE_30_SETTING, &menu->button);
    menu->framerate_30 = get_last_button(menu->button);
    create_button(head, SET_FRAMERATE_60_SETTING, &menu->button);
    menu->framerate_60 = get_last_button(menu->button);
    create_button(head, SET_FRAMERATE_90_SETTING, &menu->button);
    menu->framerate_90 = get_last_button(menu->button);
}

void init_object_setting(head_t *head, setting_menu_scene_t *menu)
{
    if (head->state_2 == 0)
        create_object(BACKGROUND_OBJECT, &menu->object);
    else
        create_object(BACKGROUND_DARK_OBJECT, &menu->object);
    create_object(TABLE_SETTING, &menu->object);
    create_object(HEADER_SETTING, &menu->object);
    create_object(WINDOW_LEFT_SETTING, &menu->object);
    create_object(BAR_MUSIC_BG_SETTING, &menu->object);
    create_object(BAR_MUSIC_SETTING, &menu->object);
    menu->music_bar = get_last_object(menu->object);
    create_object(BAR_SOUND_BG_SETTING, &menu->object);
    create_object(BAR_SOUND_SETTING, &menu->object);
    menu->sound_bar = get_last_object(menu->object);
    create_object(WINDOW_RIGHT_SETTING, &menu->object);
}

void init_text_setting(head_t *head, setting_menu_scene_t *menu)
{
    create_text(TEXT_SETTING_AUDIO, &menu->text);
    create_text(TEXT_SETTING_MUSIC, &menu->text);
    create_text(TEXT_SETTING_SOUND, &menu->text);
    create_text(TEXT_SETTING_DISPLAY, &menu->text);
    create_text(TEXT_SETTING_FULLSCREEN, &menu->text);
    create_text(TEXT_SETTING_FRAMERATE, &menu->text);
}

void init_setting_menu(head_t *head)
{
    setting_menu_scene_t *menu = malloc(sizeof(setting_menu_scene_t));

    if (head->state == STATE_SETTING_MENU)
        scenes_unloader(head, head->scenes);
    menu->object = NULL;
    menu->button = NULL;
    menu->text = NULL;
    menu->text_scrolling = NULL;
    menu->gen_ptcl = NULL;
    init_object_setting(head, menu);
    init_button_setting(head, menu);
    init_text_setting(head, menu);
    update_button_bar_setting(head, menu);
    head->scenes->setting_menu = menu;
}