/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** display inventory
*/

#include "rpg.h"

void display_inventory_bar(head_t *head)
{
    sfRenderWindow_drawSprite(head->window,
    head->scenes->in_game->inventory->healh_bg_bar->sprite, NULL);
    sfRenderWindow_drawSprite(head->window,
    head->scenes->in_game->inventory->health_bar->sprite, NULL);
    sfRenderWindow_drawSprite(head->window,
    head->scenes->in_game->inventory->experience_bg_bar->sprite, NULL);
    sfRenderWindow_drawSprite(head->window,
    head->scenes->in_game->inventory->experience_bar->sprite, NULL);
}

void display_inventory_icone(head_t *head)
{
    sfRenderWindow_drawSprite(head->window,
    head->scenes->in_game->inventory->damage->sprite, NULL);
    sfRenderWindow_drawSprite(head->window,
    head->scenes->in_game->inventory->armor->sprite, NULL);
}

void display_inventory(head_t *head)
{
    sfVector2f pos =
    sfSprite_getPosition(head->scenes->in_game->player->sprite);
    sfVector2f scale =
    sfSprite_getScale(head->scenes->in_game->player->sprite);

    if (head->scenes->in_game->inventory->open) {
        sfSprite_setPosition(head->scenes->in_game->player->sprite,
        head->scenes->in_game->inventory->p_position);
        sfSprite_setScale(head->scenes->in_game->player->sprite,
        (sfVector2f){6.0, 6.0});
        sfRenderWindow_drawSprite(head->window,
        head->scenes->in_game->inventory->sprite, NULL);
        sfRenderWindow_drawSprite(head->window,
        head->scenes->in_game->player->sprite, NULL);
        sfSprite_setPosition(head->scenes->in_game->player->sprite, pos);
        sfSprite_setScale(head->scenes->in_game->player->sprite, scale);
        display_inventory_bar(head);
        display_inventory_icone(head);
    }
}