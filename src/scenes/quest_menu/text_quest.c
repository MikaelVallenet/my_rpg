/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** text_quest
*/

#include "rpg.h"

void text_name_quest(quest_menu_t *menu, quest_t *quest, sfVector2f pos)
{
    text_data_t data;
    text_t *text;

    data.color_text = sfWhite;
    data.path = "assets/fonts/Dimbo.ttf";
    data.pos = pos;
    data.size_text = 45;
    data.text_str = quest->name;
    create_text(data, &menu->text);
    text = get_last_text(menu->text);
    pos.x = (1920 / 2) - (sfText_getGlobalBounds(text->text).width / 2);
    sfText_setPosition(text->text, pos);
}

void text_desc_quest(quest_menu_t *menu, quest_t *quest, sfVector2f pos)
{
    text_data_t data;

    data.color_text = sfWhite;
    data.path = "assets/fonts/Dimbo.ttf";
    data.pos = pos;
    data.size_text = 35;
    data.text_str = quest->description;
    create_text(data, &menu->text);
}

void text_type_quest(quest_menu_t *menu, quest_t *quest, sfVector2f pos)
{
    text_data_t data;

    data.color_text = sfWhite;
    data.path = "assets/fonts/Dimbo.ttf";
    data.pos = pos;
    data.size_text = 35;
    if (quest->value == MAIN_QUEST)
        data.text_str = "Principal";
    else
        data.text_str = "Secondaire";
    create_text(data, &menu->text);
}

void text_award_quest(quest_menu_t *menu, quest_t *quest, sfVector2f pos)
{
    text_data_t data;

    data.color_text = sfWhite;
    data.path = "assets/fonts/Dimbo.ttf";
    data.pos = pos;
    data.size_text = 35;
    data.text_str = my_strcat("Recompense: ", quest->awards_desc);
    create_text(data, &menu->text);
}

void text_step_quest(quest_menu_t *menu, quest_t *quest, sfVector2f pos)
{
    text_data_t data;

    data.color_text = sfWhite;
    data.path = "assets/fonts/Dimbo.ttf";
    data.pos = pos;
    data.size_text = 35;
    data.text_str = quest->step[quest->current_step]->objective[0]->obj_name;
    create_text(data, &menu->text);
}