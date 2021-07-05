/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init cards
*/

#include "rpg.h"

void init_card_player(head_t *head, card_t *card, char *filepath)
{
    card->name = head->scenes->in_game->player->name;
    card->texture = sfTexture_createFromFile(filepath, NULL);
    card->sprite = sfSprite_create();
    card->pos = (sfVector2f){400, 50};
    sfSprite_setTexture(card->sprite, card->texture, sfTrue);
    sfSprite_setPosition(card->sprite, card->pos);
    sfSprite_setScale(card->sprite, (sfVector2f){1, 1});
    card->texture_perso = head->scenes->in_game->player->texture;
    card->sprite_perso = sfSprite_copy(head->scenes->in_game->player->sprite);
    card->pos_perso = (sfVector2f){570, 150};
    sfSprite_setPosition(card->sprite_perso, card->pos_perso);
    sfSprite_setScale(card->sprite_perso, (sfVector2f){8.0, 8.0});
    card->healh_bg_bar = create_object_inv(BAR_HEALTH_BG_PLAYER,
    &head->scenes->in_game->object);
    card->health_bar = create_object_inv(BAR_HEALTH_PLAYER,
    &head->scenes->in_game->object);
    card->damage = head->scenes->in_game->player->p_stat.damage;
    card->health = head->scenes->in_game->player->p_stat.health;
    card->health_max = head->scenes->in_game->player->p_stat.health_max;
    card->armor = head->scenes->in_game->player->p_stat.armor;
    card->lvl = head->scenes->in_game->player->p_stat.lvl;
}

void init_card_monster(head_t *head, fight_data_t data, card_t *card,
char *filepath)
{
    card->name = data.name;
    card->texture = sfTexture_createFromFile(filepath, NULL);
    card->sprite = sfSprite_create();
    card->pos = (sfVector2f){1000, 50};
    sfSprite_setTexture(card->sprite, card->texture, sfTrue);
    sfSprite_setPosition(card->sprite, card->pos);
    sfSprite_setScale(card->sprite, (sfVector2f){1, 1});
    card->texture_perso = sfTexture_createFromFile(data.path_enemy, NULL);
    card->sprite_perso = sfSprite_create();
    card->pos_perso = (sfVector2f){1100, 130};
    sfSprite_setTexture(card->sprite_perso, card->texture_perso, sfTrue);
    sfSprite_setPosition(card->sprite_perso, card->pos_perso);
    card->healh_bg_bar = create_object_inv(BAR_HEALTH_BG_MONSTER,
    &head->scenes->in_game->object);
    card->health_bar = create_object_inv(BAR_HEALTH_MONSTER,
    &head->scenes->in_game->object);
    card->damage = data.ennemy_stat.damage;
    card->armor = data.ennemy_stat.armor;
    card->health = data.ennemy_stat.health;
    card->health_max = data.ennemy_stat.health;
    card->lvl = data.ennemy_stat.lvl;
}