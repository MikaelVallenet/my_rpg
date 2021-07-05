/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init main menu
*/

#include "rpg.h"

void destroy_main_menu(scenes_t *scenes)
{
    if (scenes->main_menu == NULL)
        return;
    destroy_button(scenes->main_menu->button);
    destroy_object(scenes->main_menu->object);
    destroy_text(scenes->main_menu->text);
    destroy_gen_ptcl(scenes->main_menu->gen_ptcl);
    destroy_text_scrolling(scenes->main_menu->text_scrolling);
    free(scenes->main_menu);
    scenes->main_menu = NULL;
}

void init_button_main_menu(head_t *head, main_menu_scene_t *menu)
{
    create_button(head, PLAY_BUTTON, &menu->button);
    create_button(head, QUIT_BUTTON, &menu->button);
    create_button(head, MUSIC_BUTTON, &menu->button);
    create_button(head, SOUND_BUTTON, &menu->button);
    create_button(head, SETTING_BUTTON, &menu->button);
}

void init_main_menu(head_t *head)
{
    main_menu_scene_t *menu = malloc(sizeof(main_menu_scene_t));
    object_t *obj;

    scenes_unloader(head, head->scenes);
    menu->object = NULL;
    menu->button = NULL;
    menu->text = NULL;
    menu->text_scrolling = NULL;
    menu->gen_ptcl = NULL;
    create_object(BACKGROUND_OBJECT, &menu->object);
    create_object(LOGO_OBJECT, &menu->object);
    obj = get_last_object(menu->object);
    sfTexture_setSmooth(obj->texture, sfTrue);
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    init_button_main_menu(head, menu);
    head->scenes->main_menu = menu;
}