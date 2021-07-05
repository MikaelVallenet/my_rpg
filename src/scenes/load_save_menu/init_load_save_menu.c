/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init pause menu
*/

#include "rpg.h"

void destroy_load_save_menu(scenes_t *scenes)
{
    if (scenes->load_save_menu == NULL)
        return;
    destroy_button(scenes->load_save_menu->button);
    destroy_object(scenes->load_save_menu->object);
    destroy_text(scenes->load_save_menu->text);
    destroy_text_scrolling(scenes->load_save_menu->text_scrolling);
    destroy_gen_ptcl(scenes->load_save_menu->gen_ptcl);
    free(scenes->load_save_menu);
    scenes->load_save_menu = NULL;
}

void init_button_load_save_menu(head_t *head, load_save_menu_scene_t *menu)
{
    create_button(head, FIRST_SAVE, &menu->button);
    menu->first_save_button = get_last_button(menu->button);
    create_button(head, SECOND_SAVE, &menu->button);
    menu->second_save_button = get_last_button(menu->button);
    create_button(head, THIRD_SAVE, &menu->button);
    menu->third_save_button = get_last_button(menu->button);
    create_button(head, QUIT_LOAD_SAVE, &menu->button);
    create_button(head, DELETE_FIRST_SAVE, &menu->button);
    menu->delete_first_save = get_last_button(menu->button);
    create_button(head, DELETE_SECOND_SAVE, &menu->button);
    menu->delete_second_save = get_last_button(menu->button);
    create_button(head, DELETE_THIRD_SAVE, &menu->button);
    menu->delete_third_save = get_last_button(menu->button);
}

void init_text_load_save_menu(head_t *head, load_save_menu_scene_t *menu)
{
    int flags = O_CREAT | O_WRONLY | O_TRUNC;

    if (file_size("saves/save_1.json") <= 0) {
        create_text(EMPTY_SAVE_1_TEXT, &menu->text);
        close(open("saves/save_1.json", flags, S_IRWXU));
    }
    else
        init_text_first_save(head, menu);
    if (file_size("saves/save_2.json") <= 0) {
        create_text(EMPTY_SAVE_2_TEXT, &menu->text);
        close(open("saves/save_2.json", flags, S_IRWXU));
    }
    else
        init_text_second_save(head, menu);
    if (file_size("saves/save_3.json") <= 0) {
        create_text(EMPTY_SAVE_3_TEXT, &menu->text);
        close(open("saves/save_3.json", flags, S_IRWXU));
    }
    else
        init_text_third_save(head, menu);
}

void init_load_save_menu(head_t *head)
{
    load_save_menu_scene_t *menu = malloc(sizeof(load_save_menu_scene_t));

    scenes_unloader(head, head->scenes);
    menu->object = NULL;
    menu->button = NULL;
    menu->text = NULL;
    menu->text_scrolling = NULL;
    menu->gen_ptcl = NULL;
    create_object(BACKGROUND_OBJECT, &menu->object);
    init_button_load_save_menu(head, menu);
    init_text_load_save_menu(head, menu);
    head->scenes->load_save_menu = menu;
}