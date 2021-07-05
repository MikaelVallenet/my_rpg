/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** destroy scenes
*/

#include "rpg.h"

void destroy_setting_menu(scenes_t *scenes)
{
    if (scenes->setting_menu == NULL)
        return;
    destroy_button(scenes->setting_menu->button);
    destroy_object(scenes->setting_menu->object);
    destroy_text(scenes->setting_menu->text);
    destroy_text_scrolling(scenes->setting_menu->text_scrolling);
    destroy_gen_ptcl(scenes->setting_menu->gen_ptcl);
    free(scenes->setting_menu);
    scenes->setting_menu = NULL;
}