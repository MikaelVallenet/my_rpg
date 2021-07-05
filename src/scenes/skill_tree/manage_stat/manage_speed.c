/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** manage_speed
*/

#include "rpg.h"

void buy_speed_skill(int cost, float speed, head_t *head)
{
    player_t *player = head->scenes->in_game->player;
    skill_tree_scenes_t *menu = head->scenes->skill_tree;

    player->speed += speed;
    player->p_stat.nb_star -= cost;
    if (cost == 1)
        player->skill_tree.speed_1 = 1;
    if (cost == 2)
        player->skill_tree.speed_2 = 1;
    if (cost == 3)
        player->skill_tree.speed_3 = 1;
    set_state_speed_button(head, menu);
    sfText_setString(menu->nb_star->text,
    my_nbr_to_str(head->scenes->in_game->player->p_stat.nb_star));
}

void manage_clic_speed(head_t *head, button_t *button)
{
    skill_tree_scenes_t *menu = head->scenes->skill_tree;
    player_t *player = head->scenes->in_game->player;

    if (button == menu->speed_1) {
        if (player->p_stat.nb_star >= 1)
            buy_speed_skill(1, 0.2, head);
    }
    if (button == menu->speed_2) {
        if (player->p_stat.nb_star >= 2)
            buy_speed_skill(2, 0.3, head);
    }
    if (button == menu->speed_3) {
        if (player->p_stat.nb_star >= 3)
            buy_speed_skill(3, 0.6, head);
    }
}