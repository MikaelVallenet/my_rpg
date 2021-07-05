/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** display fights
*/

#include "rpg.h"

void display_fights(head_t *head, fight_t *fight)
{
    if (head->scenes->duel_scene->fight_bool == 0)
        return;
    display_card(head, fight->player);
    display_card(head, fight->ennemy);
    return;
}