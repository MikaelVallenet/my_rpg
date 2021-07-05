/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** manage_damage
*/

#include "rpg.h"

void buy_damage_skill(int cost, int damage, head_t *head)
{
    player_t *player = head->scenes->in_game->player;
    skill_tree_scenes_t *menu = head->scenes->skill_tree;

    player->p_stat.damage += damage;
    player->p_stat.nb_star -= cost;
    if (cost == 1)
        player->skill_tree.damage_1 = 1;
    if (cost == 2)
        player->skill_tree.damage_2 = 1;
    if (cost == 3)
        player->skill_tree.damage_3 = 1;
    set_state_damage_button(head, menu);
    sfText_setString(menu->nb_star->text,
    my_nbr_to_str(head->scenes->in_game->player->p_stat.nb_star));
}

void manage_clic_damage(head_t *head, button_t *button)
{
    skill_tree_scenes_t *menu = head->scenes->skill_tree;
    player_t *player = head->scenes->in_game->player;

    if (button == menu->damage_1) {
        if (player->p_stat.nb_star >= 1)
            buy_damage_skill(1, 3, head);
    }
    if (button == menu->damage_2) {
        if (player->p_stat.nb_star >= 2)
            buy_damage_skill(2, 6, head);
    }
    if (button == menu->damage_3) {
        if (player->p_stat.nb_star >= 3)
            buy_damage_skill(3, 10, head);
    }
}