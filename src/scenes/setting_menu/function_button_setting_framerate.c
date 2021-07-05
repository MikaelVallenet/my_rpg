/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function for switch framerate
*/

#include "rpg.h"

void update_button_framerate_setting(head_t *head, setting_menu_scene_t *menu)
{
    if (head->option->max_fps == 30) {
        menu->framerate_select = menu->framerate_30;
        sfText_setString(menu->framerate_select->hover_text, "selected");
    }
    if (head->option->max_fps == 60) {
        menu->framerate_select = menu->framerate_60;
        sfText_setString(menu->framerate_select->hover_text, "selected");
    }
    if (head->option->max_fps == 90) {
        menu->framerate_select = menu->framerate_90;
        sfText_setString(menu->framerate_select->hover_text, "selected");
    }
    set_pos_hover_text(menu->framerate_select);
}

void set_framerate_30_window(head_t *head, button_t *button)
{
    button_t *framerate_select = head->scenes->setting_menu->framerate_select;

    if (button == framerate_select)
        return;
    sfText_setString(framerate_select->hover_text, "");
    sfText_setString(button->hover_text, "selected");
    head->scenes->setting_menu->framerate_select = button;
    head->option->max_fps = 30;
    set_pos_hover_text(head->scenes->setting_menu->framerate_select);
    sfRenderWindow_setFramerateLimit(head->window, 30);
}

void set_framerate_60_window(head_t *head, button_t *button)
{
    button_t *framerate_select = head->scenes->setting_menu->framerate_select;

    if (button == framerate_select)
        return;
    sfText_setString(framerate_select->hover_text, "");
    sfText_setString(button->hover_text, "selected");
    head->scenes->setting_menu->framerate_select = button;
    head->option->max_fps = 60;
    set_pos_hover_text(head->scenes->setting_menu->framerate_select);
    sfRenderWindow_setFramerateLimit(head->window, 60);
}

void set_framerate_90_window(head_t *head, button_t *button)
{
    button_t *framerate_select = head->scenes->setting_menu->framerate_select;

    if (button == framerate_select)
        return;
    sfText_setString(framerate_select->hover_text, "");
    sfText_setString(button->hover_text, "selected");
    head->scenes->setting_menu->framerate_select = button;
    head->option->max_fps = 90;
    set_pos_hover_text(head->scenes->setting_menu->framerate_select);
    sfRenderWindow_setFramerateLimit(head->window, 90);
}