/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** manage_button
*/

#include "rpg.h"

int table_is_visible(head_t *head, button_t *button, sfVector2f clic)
{
    if (is_button_skill(head, button) && is_in_button(button, clic))
        return (1);
    else
        return (0);
}

void is_hover_button_skill_aux(head_t *head, button_t *button, sfVector2f clic)
{
    if (is_button_activate(head, button)) {
        if (is_in_button(button, clic)) {
            sfSprite_setColor(button->sprite, sfYellow);
            sfText_setFillColor(button->hover_text, sfWhite);
        }
        else {
            sfSprite_setColor(button->sprite, sfWhite);
            sfText_setFillColor(button->hover_text, sfTransparent);
        }
    }
    else {
        if (is_in_button(button, clic))
            sfText_setFillColor(button->hover_text, sfWhite);
        else
            sfText_setFillColor(button->hover_text, sfTransparent);
    }
}

void is_hover_button_skill(head_t *head, button_t *button, sfVector2f clic)
{
    int is_visible = 0;
    sfSprite *table = head->scenes->skill_tree->table_description->sprite;

    while (button != NULL) {
        is_hover_button_skill_aux(head, button, clic);
        if (is_visible == 0 && table_is_visible(head, button, clic))
            is_visible = 1;
        button = button->next;
    }
    if (is_visible == 1)
        sfSprite_setScale(table, (sfVector2f){0.5, 0.5});
    else
        sfSprite_setScale(table, (sfVector2f){0, 0});
}

void is_clic_button_skill(head_t *head, button_t *button, sfVector2f clic)
{
    while (button != NULL) {
        if (is_button_activate(head, button) && is_in_button(button, clic)) {
            animation_button_clic(button);
            button->call_func(head, button);
        }
        button = button->next;
    }
}