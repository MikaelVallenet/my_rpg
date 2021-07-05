/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init main menu
*/

#include "rpg.h"

void destroy_quest_menu(scenes_t *scenes)
{
    if (scenes->quest_menu == NULL)
        return;
    destroy_button(scenes->quest_menu->button);
    destroy_object(scenes->quest_menu->object);
    destroy_text(scenes->quest_menu->text);
    destroy_gen_ptcl(scenes->quest_menu->gen_ptcl);
    destroy_text_scrolling(scenes->quest_menu->text_scrolling);
    free(scenes->quest_menu);
    scenes->quest_menu = NULL;
}

void init_quest_menu(head_t *head)
{
    quest_menu_t *menu = malloc(sizeof(quest_menu_t));

    if (head->state == STATE_QUEST_MENU)
        scenes_unloader(head, head->scenes);
    menu->object = NULL;
    menu->button = NULL;
    menu->text = NULL;
    menu->text_scrolling = NULL;
    menu->gen_ptcl = NULL;
    create_object(TABLE_QUEST_MENU, &menu->object);
    create_object(QUEST_1, &menu->object);
    create_object(QUEST_2, &menu->object);
    create_object(QUEST_3, &menu->object);
    create_text(TEXT_QUEST_MENU, &menu->text);
    init_text_quest_menu(head, menu);
    head->scenes->quest_menu = menu;
}