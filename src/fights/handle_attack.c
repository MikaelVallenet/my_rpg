/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** handle attack
*/

#include "rpg.h"

static void move_stick(head_t *head, fight_t *fight)
{
    sfVector2f position = sfSprite_getPosition(fight->attack->cursor->sprite);
    double value = sin(((position.x - 420) / 1000) * M_PI) * SPEED_BAR + 1;

    if (!fight->attack->run)
        return;
    if (position.x < 420) {
        fight->attack->direction = 1;
    }
    if (position.x > 1420)
        fight->attack->direction = -1;
    if (fight->attack->direction == -1)
        position.x -= value;
    else
        position.x += value;
    sfSprite_setPosition(fight->attack->cursor->sprite, position);
}

void press_space_attack(head_t *head, fight_t *fight)
{
    sfVector2f position = sfSprite_getPosition(fight->attack->cursor->sprite);

    sfSound_play(head->res->sfx->attack_sound);
    if (!fight->attack->activate)
        return;
    fight->attack->run = 0;
    fight->attack->damage =
    sin(((position.x - 420) / 1000) * M_PI) * fight->player->damage;
    fight->ennemy->health -= fight->attack->damage;
    update_bar(fight->ennemy->health_bar,
    (fight->ennemy->health * 100) / fight->ennemy->health_max);
    fight->attack->end = 1;
}

static void display_attack(head_t *head, fight_t *fight)
{
    if (fight->attack->activate) {
        sfRenderWindow_drawSprite(head->window,
        fight->attack->attack_bar->sprite, NULL);
        sfRenderWindow_drawSprite(head->window,
        fight->attack->cursor->sprite, NULL);
    }
}

void handle_attack(head_t *head, fight_t *fight)
{
    if (!fight->attack->activate)
        return;
    move_stick(head, fight);
    display_attack(head, fight);
    handle_turn(head, head->scenes->duel_scene->fight);
}