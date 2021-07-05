/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** ini _text_quest_menu
*/

#include "rpg.h"

void text_nb_step_quest(quest_menu_t *menu, quest_t *quest,
sfVector2f pos, text_t *l_text)
{
    text_data_t data;
    char *nb_step = my_nbr_to_str(quest->step[quest->current_step]
    ->objective[0]->nb);
    char *current_step = my_nbr_to_str(quest->step[quest->current_step]
    ->objective[0]->cur_nb);

    data.color_text = sfWhite;
    data.path = "assets/fonts/Dimbo.ttf";
    data.pos = pos;
    data.pos.x += sfText_getGlobalBounds(l_text->text).width + 20;
    data.size_text = 35;
    data.text_str = my_strcat(current_step, " / ");
    data.text_str = my_strcat(data.text_str, nb_step);
    create_text(data, &menu->text);
}

void init_text_quest_menu(head_t *head, quest_menu_t *menu)
{
    quest_t *quest = head->scenes->in_game->quests;
    sfVector2f pos = {655, 210};

    for (int i = 0; i < 3 && quest; i++) {
        text_name_quest(menu, quest, pos);
        pos.y += 55;
        text_desc_quest(menu, quest, pos);
        pos.x += 515;
        pos.y -= 55;
        text_type_quest(menu, quest, pos);
        pos.x -= 515;
        pos.y += 110;
        text_award_quest(menu, quest, pos);
        pos.y += 55;
        text_step_quest(menu, quest, pos);
        text_nb_step_quest(menu, quest, pos, get_last_text(menu->text));
        pos.y += 105;
        quest = quest->next;
    }
}