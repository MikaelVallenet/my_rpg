/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init main menu
*/

#include "rpg.h"

void destroy__scenes(scenes_t *scenes)
{
    if (scenes->main_menu == NULL)
        return;

    free(scenes->main_menu);
}

void init__scenes(head_t *head)
{
    main_menu_scene_t *menu = malloc(sizeof(main_menu_scene_t));

    scenes_unloader(head, head->scenes);
    head->scenes->main_menu = menu;
}