/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** init_text_load_save_menu_aux
*/

#include "rpg.h"

void init_text_name_save(load_save_menu_scene_t *menu,
sfVector2f pos, char *path)
{
    text_data_t text_data;
    pars_obj_t *obj = parser_json(path);
    pars_data_t *name;

    text_data.path = "assets/fonts/Dimbo.ttf";
    text_data.color_text = sfWhite;
    name = json_search(obj->data, "character");
    text_data.text_str = my_strcat("Character: ", name->values.kstr);
    text_data.size_text = 80;
    text_data.pos = pos;
    create_text(text_data, &menu->text);
}

void init_text_progression_save(load_save_menu_scene_t *menu,
sfVector2f pos, char *path)
{
    text_data_t text_data;
    pars_obj_t *obj = parser_json(path);
    pars_data_t *name;

    text_data.path = "assets/fonts/Dimbo.ttf";
    text_data.color_text = sfWhite;
    name = json_search(obj->data, "time_played");
    text_data.text_str = my_strcat("Time played: ",
    my_nbr_to_str(name->values.kint));
    text_data.text_str = my_strcat(text_data.text_str, "min");
    text_data.pos = pos;
    text_data.size_text = 60;
    create_text(text_data, &menu->text);
}

void init_text_time_save(load_save_menu_scene_t *menu,
sfVector2f pos, char *path)
{
    text_data_t text_data;
    pars_obj_t *obj = parser_json(path);
    pars_data_t *name;

    text_data.path = "assets/fonts/Dimbo.ttf";
    text_data.color_text = sfWhite;
    name = json_search(obj->data, "progression");
    text_data.text_str = my_strcat("Progression: ",
    my_nbr_to_str(name->values.kint));
    text_data.text_str = my_strcat(text_data.text_str, "%");
    text_data.pos = pos;
    text_data.size_text = 60;
    create_text(text_data, &menu->text);
}