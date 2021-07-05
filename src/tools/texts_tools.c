/*
** EPITECH PROJECT, 2021
** My World
** File description:
** texts_tools
*/

#include <SFML/Graphics.h>
#include "rpg.h"

sfText *sftext_create(sfFont *font, sfColor color, int size, char *str)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setFillColor(text, color);
    sfText_setCharacterSize(text, size);
    sfText_setString(text, str);
    return (text);
}