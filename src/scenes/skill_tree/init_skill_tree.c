/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init pause menu
*/

#include "rpg.h"

void destroy_skill_tree(scenes_t *scenes)
{
    if (scenes->skill_tree == NULL)
        return;
    destroy_button(scenes->skill_tree->button);
    destroy_object(scenes->skill_tree->object);
    destroy_text(scenes->skill_tree->text);
    destroy_text_scrolling(scenes->skill_tree->text_scrolling);
    destroy_gen_ptcl(scenes->skill_tree->gen_ptcl);
    free(scenes->skill_tree);
    scenes->skill_tree = NULL;
}

void init_skill_tree(head_t *head)
{
    skill_tree_scenes_t *menu = malloc(sizeof(skill_tree_scenes_t));

    if (head->state == STATE_SKILL_TREE)
        scenes_unloader(head, head->scenes);
    menu->object = NULL;
    menu->button = NULL;
    menu->text = NULL;
    menu->text_scrolling = NULL;
    menu->gen_ptcl = NULL;
    menu->table_description = NULL;
    create_button(head, QUIT_SKILL_TREE, &menu->button);
    create_object(TABLE_SKILL_TREE, &menu->object);
    create_object(TABLE_2_SKILL_TREE, &menu->table_description);
    init_skill_tree_aux(head, menu);
    head->scenes->skill_tree = menu;
}