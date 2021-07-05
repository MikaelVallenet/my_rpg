/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** init_text_load_save
*/

#include "rpg.h"

void init_text_first_save(head_t *head, load_save_menu_scene_t *menu)
{
    sfVector2f pos = (sfVector2f){1920 / 2 - 483 + 270, 1080 / 2 - 450 + 10};

    init_text_name_save(menu, pos, "saves/save_1.json");
    pos = (sfVector2f){1920 / 2 - 483 + 70, 1080 / 2 - 450 + 125};
    init_text_time_save(menu, pos, "saves/save_1.json");
    pos = (sfVector2f){1920 / 2 - 483 + 530, 1080 / 2 - 450 + 125};
    init_text_progression_save(menu, pos, "saves/save_1.json");
}

void init_text_second_save(head_t *head, load_save_menu_scene_t *menu)
{
    sfVector2f pos = (sfVector2f){1920 / 2 - 483 + 270, 1080 / 2 - 450 + 310};

    init_text_name_save(menu, pos, "saves/save_2.json");
    pos = (sfVector2f){1920 / 2 - 483 + 70, 1080 / 2 - 450 + 425};
    init_text_time_save(menu, pos, "saves/save_2.json");
    pos = (sfVector2f){1920 / 2 - 483 + 530, 1080 / 2 - 450 + 425};
    init_text_progression_save(menu, pos, "saves/save_2.json");
}

void init_text_third_save(head_t *head, load_save_menu_scene_t *menu)
{
    sfVector2f pos = (sfVector2f){1920 / 2 - 483 + 270, 1080 / 2 - 450 + 610};

    init_text_name_save(menu, pos, "saves/save_3.json");
    pos = (sfVector2f){1920 / 2 - 483 + 70, 1080 / 2 - 450 + 725};
    init_text_time_save(menu, pos, "saves/save_3.json");
    pos = (sfVector2f){1920 / 2 - 483 + 530, 1080 / 2 - 450 + 725};
    init_text_progression_save(menu, pos, "saves/save_2.json");
}