/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** update inventory
*/

#include "rpg.h"

void update_bar(object_t *object, int value)
{
    sfVector2u size_texture = sfTexture_getSize(object->texture);
    sfIntRect rect;

    rect.height = size_texture.y;
    rect.width = value * size_texture.x / 100;
    rect.top = 0;
    rect.left = 0;
    sfSprite_setTextureRect(object->sprite, rect);
}

static void update_health(inventory_t *inventory, text_scrolling_t *new_text,
player_t *player)
{
    if (new_text->display == 1) {
        my_strcpy(new_text->str_display, "Health : ");
        my_strcat_original(new_text->str_display,
        my_nbr_to_str(player->p_stat.health));
        my_strcat_original(new_text->str_display, " / ");
        my_strcat_original(new_text->str_display,
        my_nbr_to_str(player->p_stat.health_max));
    }
}

static void update_experience(inventory_t *inventory,
text_scrolling_t *new_text, player_t *player)
{
    if (new_text->display == 1) {
        my_strcpy(new_text->str_display, "Experience : ");
        my_strcat_original(new_text->str_display,
        my_nbr_to_str(player->p_stat.xp));
        my_strcat_original(new_text->str_display, " / ");
        my_strcat_original(new_text->str_display,
        my_nbr_to_str(player->p_stat.nxt_lvl));
    }
}

static void update_armor_damage(inventory_t *inventory,
text_scrolling_t *new_text, player_t *player, text_scrolling_t *text)
{
    new_text = find_text("inv_damage", text);
    if (new_text->display == 1) {
        my_strcpy(new_text->str_display, my_nbr_to_str(player->p_stat.damage));
    }
    new_text = find_text("inv_armor", text);
    if (new_text->display == 1) {
        my_strcpy(new_text->str_display, my_nbr_to_str(player->p_stat.armor));
    }
    new_text = find_text("inv_lvl", text);
    if (new_text->display == 1) {
        my_strcpy(new_text->str_display, "Level : ");
        my_strcat_original(new_text->str_display,
        my_nbr_to_str(player->p_stat.lvl));
    }
}

void update_inventory_str(inventory_t *inventory, text_scrolling_t *text,
player_t *player)
{
    text_scrolling_t *new_text;

    if (inventory->open == 1) {
        new_text = find_text("inv_name", text);
        if (new_text->display == 1)
            my_strcpy(new_text->str_display, player->name);
        new_text = find_text("inv_health", text);
        update_health(inventory, new_text, player);
        update_armor_damage(inventory, new_text, player, text);
        new_text = find_text("inv_xp", text);
        update_experience(inventory, new_text, player);
        update_bar(inventory->health_bar,
        (player->p_stat.health * 100) / player->p_stat.health_max);
        update_bar(inventory->experience_bar,
        (player->p_stat.xp * 100) / player->p_stat.nxt_lvl);
    }
}