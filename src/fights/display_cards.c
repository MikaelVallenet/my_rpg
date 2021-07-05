/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** display cards
*/

#include "rpg.h"

void update_duel_text(head_t *head, fight_t *fight, text_scrolling_t *text)
{
    text_scrolling_t *new_text;

    new_text = find_text("fight_sword_player", text);
    my_strcpy(new_text->str_display, my_nbr_to_str(fight->player->damage));
    new_text = find_text("fight_shield_player", text);
    my_strcpy(new_text->str_display, my_nbr_to_str(fight->player->armor));
    new_text = find_text("fight_sword_monster", text);
    my_strcpy(new_text->str_display, my_nbr_to_str(fight->ennemy->damage));
    new_text = find_text("fight_shield_monster", text);
    my_strcpy(new_text->str_display, my_nbr_to_str(fight->ennemy->armor));
}

void display_card(head_t *head, card_t *card)
{
    sfRenderWindow_drawSprite(head->window, card->sprite, NULL);
    sfRenderWindow_drawSprite(head->window, card->sprite_perso, NULL);
}