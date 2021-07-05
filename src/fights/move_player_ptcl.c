/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** move_player_ptcl
*/

#include "rpg.h"

static void move_left(fight_t *fight)
{
    sfVector2f pos = sfSprite_getPosition(fight->defense->my_ptcl->sprite);

    if (pos.x > 409) {
        pos.x -= 8;
    }
    sfSprite_setPosition(fight->defense->my_ptcl->sprite, pos);
}

static void move_right(fight_t *fight)
{
    sfVector2f pos = sfSprite_getPosition(fight->defense->my_ptcl->sprite);

    if (pos.x < 1420) {
        pos.x += 8;
    }
    sfSprite_setPosition(fight->defense->my_ptcl->sprite, pos);
}

static void move_up(fight_t *fight)
{
    sfVector2f pos = sfSprite_getPosition(fight->defense->my_ptcl->sprite);

    if (pos.y > 720) {
        pos.y -= 8;
    }
    sfSprite_setPosition(fight->defense->my_ptcl->sprite, pos);
}

static void move_down(fight_t *fight)
{
    sfVector2f pos = sfSprite_getPosition(fight->defense->my_ptcl->sprite);

    if (pos.y < 975) {
        pos.y += 8;
    }
    sfSprite_setPosition(fight->defense->my_ptcl->sprite, pos);
}

void handler_ptcl_player_mv(fight_t *fight)
{
    if (fight->defense->activate == 1) {
        if (fight->defense->keys.key_left == PRESS) {
            move_left(fight);
        }
        if (fight->defense->keys.key_right == PRESS) {
            move_right(fight);
        }
        if (fight->defense->keys.key_down == PRESS) {
            move_down(fight);
        }
        if (fight->defense->keys.key_up == PRESS) {
            move_up(fight);
        }
    }
}