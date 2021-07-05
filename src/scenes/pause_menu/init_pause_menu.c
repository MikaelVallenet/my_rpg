/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init pause menu
*/

#include "rpg.h"

void destroy_pause_menu(scenes_t *scenes)
{
    if (scenes->pause_menu == NULL)
        return;
    destroy_button(scenes->pause_menu->button);
    destroy_object(scenes->pause_menu->object);
    destroy_text(scenes->pause_menu->text);
    destroy_text_scrolling(scenes->pause_menu->text_scrolling);
    destroy_gen_ptcl(scenes->pause_menu->gen_ptcl);
    free(scenes->pause_menu);
    scenes->pause_menu = NULL;
}

void init_button_pause(head_t *head, pause_menu_scene_t *menu)
{
    create_button(head, RESUME_BUTTON_PAUSE, &menu->button);
    create_button(head, MENU_BUTTON_PAUSE, &menu->button);
    create_button(head, QUIT_BUTTON_PAUSE, &menu->button);
    create_button(head, SAVE_BUTTON_PAUSE, &menu->button);
    create_button(head, SETTING_BUTTON_PAUSE, &menu->button);
}

void init_pause_menu(head_t *head)
{
    pause_menu_scene_t *menu = malloc(sizeof(pause_menu_scene_t));

    if (head->state == STATE_PAUSE_MENU)
        scenes_unloader(head, head->scenes);
    menu->object = NULL;
    menu->button = NULL;
    menu->text = NULL;
    menu->text_scrolling = NULL;
    menu->gen_ptcl = NULL;
    create_object(BACKGROUND_DARK_OBJECT, &menu->object);
    create_object(TABLE_PAUSE, &menu->object);
    create_object(ROPE_LEFT_PAUSE, &menu->object);
    create_object(ROPE_RIGHT_PAUSE, &menu->object);
    init_button_pause(head, menu);
    create_text(TEXT_PAUSE, &menu->text);
    head->scenes->pause_menu = menu;
}