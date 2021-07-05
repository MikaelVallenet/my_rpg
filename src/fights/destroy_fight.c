/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** destroy fight
*/

#include "rpg.h"

static void destroy_card(head_t *head, card_t *card)
{
    sfSprite_destroy(card->sprite);
    sfTexture_destroy(card->texture);
    if (card->sprite_perso != head->scenes->in_game->player->sprite) {
        sfSprite_destroy(card->sprite_perso);
        sfTexture_destroy(card->texture_perso);
    }
    destroy_object(card->healh_bg_bar);
    destroy_object(card->health_bar);
}

void destroy_fight(head_t *head, fight_t *fight)
{
    destroy_card(head, fight->player);
    destroy_card(head, fight->ennemy);
    free(fight);
}