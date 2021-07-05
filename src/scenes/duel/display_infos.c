/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** display info duel
*/

#include "rpg.h"

void display_infos(head_t *head, fight_t *fight)
{
    sfSprite_setPosition(fight->sword_icone->sprite, (sfVector2f){460, 430});
    sfSprite_setPosition(fight->armor_icone->sprite, (sfVector2f){610, 435});
    sfRenderWindow_drawSprite(head->window, fight->armor_icone->sprite, NULL);
    sfRenderWindow_drawSprite(head->window, fight->sword_icone->sprite, NULL);
    sfSprite_setPosition(fight->sword_icone->sprite, (sfVector2f){1080, 430});
    sfSprite_setPosition(fight->armor_icone->sprite, (sfVector2f){1230, 435});
    sfRenderWindow_drawSprite(head->window, fight->armor_icone->sprite, NULL);
    sfRenderWindow_drawSprite(head->window, fight->sword_icone->sprite, NULL);
    sfRenderWindow_drawSprite(head->window,
    fight->player->healh_bg_bar->sprite, NULL);
    sfRenderWindow_drawSprite(head->window,
    fight->player->health_bar->sprite, NULL);
    sfRenderWindow_drawSprite(head->window,
    fight->ennemy->healh_bg_bar->sprite, NULL);
    sfRenderWindow_drawSprite(head->window,
    fight->ennemy->health_bar->sprite, NULL);
}