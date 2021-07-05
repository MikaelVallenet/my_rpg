/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init fight
*/

#include "rpg.h"

static void init_fight_text(head_t *head)
{
    create_text_scrolling(head, FIGHT_SWORD_P,
    &head->scenes->duel_scene->text_scrolling);
    create_text_scrolling(head, FIGHT_SHIELD_P,
    &head->scenes->duel_scene->text_scrolling);
    create_text_scrolling(head, FIGHT_SWORD_M,
    &head->scenes->duel_scene->text_scrolling);
    create_text_scrolling(head, FIGHT_SHIELD_M,
    &head->scenes->duel_scene->text_scrolling);
}

static void start_fight_text(head_t *head)
{
    start_text_scrolling("fight_sword_player",
    head->scenes->duel_scene->text_scrolling);
    start_text_scrolling("fight_shield_player",
    head->scenes->duel_scene->text_scrolling);
    start_text_scrolling("fight_sword_monster",
    head->scenes->duel_scene->text_scrolling);
    start_text_scrolling("fight_shield_monster",
    head->scenes->duel_scene->text_scrolling);
    display_on_text_scrolling("fight_sword_player",
    head->scenes->duel_scene->text_scrolling);
    display_on_text_scrolling("fight_shield_player",
    head->scenes->duel_scene->text_scrolling);
    display_on_text_scrolling("fight_sword_monster",
    head->scenes->duel_scene->text_scrolling);
    display_on_text_scrolling("fight_shield_monster",
    head->scenes->duel_scene->text_scrolling);
}

void rotate_health_bar(head_t *head, fight_t *fight)
{
    sfSprite_setRotation(fight->player->health_bar->sprite, -90);
    sfSprite_setRotation(fight->player->healh_bg_bar->sprite, -90);
    sfSprite_setRotation(fight->ennemy->health_bar->sprite, -90);
    sfSprite_setRotation(fight->ennemy->healh_bg_bar->sprite, -90);
}

void init_fight(head_t *head, fight_data_t data)
{
    fight_t *fight = malloc(sizeof(fight_t));

    head->scenes->duel_scene->fight_bool = 1;
    head->scenes->duel_scene->fight = fight;
    fight->player = malloc(sizeof(card_t));
    fight->ennemy = malloc(sizeof(card_t));
    fight->experience = data.experience;
    init_card_player(head, fight->player, CARD_PATH);
    init_card_monster(head, data, fight->ennemy, CARD_PATH);
    fight->armor_icone = create_object_inv(SHIELD_ICONE, NULL);
    fight->sword_icone = create_object_inv(SWORD_ICONE, NULL);
    init_fight_text(head);
    start_fight_text(head);
    rotate_health_bar(head, fight);
}