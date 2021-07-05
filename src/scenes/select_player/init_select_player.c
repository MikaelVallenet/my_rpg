/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init main menu
*/

#include "rpg.h"

void destroy_select_player_scenes(scenes_t *scenes)
{
    if (scenes->select_player == NULL)
        return;
    destroy_object(scenes->select_player->object);
    destroy_button(scenes->select_player->button);
    destroy_text(scenes->select_player->text);
    destroy_text_scrolling(scenes->select_player->text_scrolling);
    destroy_gen_ptcl(scenes->select_player->gen_ptcl);
    free(scenes->select_player);
    scenes->select_player = NULL;
}

void create_select_player_text(head_t *head, select_player_t *menu)
{
    create_text(CHOOSE_CHARACTER, &menu->text);
}

void init_select_player_scenes(head_t *head)
{
    select_player_t *menu = malloc(sizeof(select_player_t));

    scenes_unloader(head, head->scenes);
    menu->button = NULL;
    menu->object = NULL;
    menu->text = NULL;
    menu->text_scrolling = NULL;
    menu->gen_ptcl = NULL;
    create_object(BACKGROUND_SELECT_PLAYER, &menu->object);
    create_button(head, QUIT_SELECT_PLAYER, &menu->button);
    create_button_face(head, menu);
    create_object_appearance(head, menu);
    create_object_name(head, menu);
    create_select_player_text(head, menu);
    head->scenes->select_player = menu;
}