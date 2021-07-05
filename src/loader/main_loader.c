/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** loader
*/

#include "rpg.h"

static option_t *option_initialize(void)
{
    option_t *option = malloc(sizeof(option_t));

    option->mode = (sfVideoMode){1920, 1080, 32};
    option->max_fps = FPS_NB;
    option->fullscreen = 0;
    option->automatic_resolution = 1;
    option->music_volume = 50;
    option->sound_volume = 50;
    return (option);
}

static engine_t *engine_initialize(void)
{
    engine_t *engine = malloc(sizeof(engine_t));

    return (engine);
}

static technical_t *technical_initialize(void)
{
    technical_t *tech = malloc(sizeof(technical_t));

    tech->size_map = (sfVector2f){5120, 4160};
    tech->state_2_ex = 0;
    tech->index_save = 0;
    return (tech);
}

static scenes_t *scenes_initialize(void)
{
    scenes_t *scenes = malloc(sizeof(scenes_t));

    scenes->in_game = NULL;
    scenes->main_menu = NULL;
    scenes->setting_menu = NULL;
    scenes->load_save_menu = NULL;
    scenes->select_player = NULL;
    scenes->pause_menu = NULL;
    scenes->skill_tree = NULL;
    scenes->duel_scene = NULL;
    scenes->quest_menu = NULL;
    return (scenes);
}

head_t *head_initialize(int ac, char **av)
{
    head_t *head = malloc(sizeof(head_t));

    head->option = option_initialize();
    head->engine = engine_initialize();
    head->technical = technical_initialize();
    head->scenes = scenes_initialize();
    head->res = res_initialize(head);
    head->state = STATE_MENU;
    head->event = event_initialize();
    head->state_2 = 0;
    head->window = NULL;
    INIT_PTR[head->state](head);
    init_global_scenes(head);
    return (head);
}