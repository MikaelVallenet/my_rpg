/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** init_text_skill_tree
*/

#include "rpg.h"

void set_pos_text_skill_tree(head_t *head, skill_tree_scenes_t *menu)
{
    sfVector2f pos = {(1920 / 2) - (557 * 0.5 / 2) + 30, 950 + 10};

    sfText_setPosition(menu->armor_1->hover_text, pos);
    sfText_setCharacterSize(menu->armor_1->hover_text, 40);
    sfText_setPosition(menu->armor_2->hover_text, pos);
    sfText_setCharacterSize(menu->armor_2->hover_text, 40);
    sfText_setPosition(menu->armor_3->hover_text, pos);
    sfText_setCharacterSize(menu->armor_3->hover_text, 40);
    sfText_setPosition(menu->damage_1->hover_text, pos);
    sfText_setCharacterSize(menu->damage_1->hover_text, 40);
    sfText_setPosition(menu->damage_2->hover_text, pos);
    sfText_setCharacterSize(menu->damage_2->hover_text, 40);
    sfText_setPosition(menu->damage_3->hover_text, pos);
    sfText_setCharacterSize(menu->damage_3->hover_text, 40);
    sfText_setPosition(menu->speed_1->hover_text, pos);
    sfText_setCharacterSize(menu->speed_1->hover_text, 40);
    sfText_setPosition(menu->speed_2->hover_text, pos);
    sfText_setCharacterSize(menu->speed_2->hover_text, 40);
    sfText_setPosition(menu->speed_3->hover_text, pos);
    sfText_setCharacterSize(menu->speed_3->hover_text, 40);
}

void init_text_skill_tree(head_t *head, skill_tree_scenes_t *menu)
{
    create_object(NB_STAR, &menu->object);
    create_text(TEXT_NB_STAR, &menu->text);
    menu->nb_star = get_last_text(menu->text);
    create_text(TEXT_SKILL_TREE, &menu->text);
    sfText_setRotation(get_last_text(menu->text)->text, 90);
    sfText_setString(menu->nb_star->text,
    my_nbr_to_str(head->scenes->in_game->player->p_stat.nb_star));
}