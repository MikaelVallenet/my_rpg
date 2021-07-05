/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** update
*/

#include "rpg.h"

static void put_escape_desc(inventory_t *inventory,
text_scrolling_t *new_text)
{
    for (int i = 0; new_text->str_display[i] != '\0'; i += 1) {
        if (i % 35 == 0 && i != 0) {
            new_text->str_display =
            my_strncat(new_text->str_display, "\n", i);
        }
    }
}

void update_item_text(inventory_t *inventory, text_scrolling_t *text)
{
    text_scrolling_t *new_text;
    sfVector2f position = (sfVector2f){270, 145};

    if (inventory->item_window->open == 1) {
        new_text = find_text("item_name", text);
        my_strcpy(new_text->str_display,
        inventory->items[inventory->item_window->id].name);
        position.x -= (my_strlen(new_text->str_display) / 2) * 6;
        sfText_setPosition(new_text->text, position);
        new_text = find_text("item_quantity", text);
        my_strcpy(new_text->str_display, "Quantity : ");
        my_strcat_original(new_text->str_display,
        my_nbr_to_str(inventory->items[inventory->item_window->id].nbr));
        new_text = find_text("item_desc", text);
        new_text->str_display =
        my_strdup(inventory->items[inventory->item_window->id].description);
        put_escape_desc(inventory, new_text);
    }
}