/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init main menu
*/

#include "rpg.h"

void destroy_in_game_scenes(scenes_t *scenes)
{
    if (scenes->in_game == NULL)
        return;
    sfClock_destroy(scenes->in_game->clock);
    sfView_destroy(scenes->in_game->view);
    destroy_object(scenes->in_game->object);
    destroy_button(scenes->in_game->button);
    destroy_text(scenes->in_game->text);
    destroy_gen_ptcl(scenes->in_game->gen_ptcl);
    destroy_player(scenes->in_game->player);
    destroy_inventory(scenes->in_game->inventory, scenes);
    destroy_text_scrolling(scenes->in_game->text_scrolling);
    destroy_npc(scenes->in_game->npc);
    if (scenes->in_game->bubble != NULL)
        destroy_object(scenes->in_game->bubble);
    if (scenes->in_game->face != NULL)
        destroy_object(scenes->in_game->face);
    free(scenes->in_game);
    scenes->in_game = NULL;
}

void set_null_object(in_game_t *menu)
{
    menu->button = NULL;
    menu->object = NULL;
    menu->text = NULL;
    menu->text_scrolling = NULL;
    menu->current_conversation = NULL;
    menu->gen_ptcl = NULL;
    menu->event_text_display = 0;
    menu->npc = NULL;
    menu->bubble = NULL;
    menu->face = NULL;
    menu->quests = NULL;
}

void init_view_in_game(in_game_t *menu)
{
    menu->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
}

void init_in_game_scenes(head_t *head)
{
    in_game_t *menu = malloc(sizeof(in_game_t));

    scenes_unloader(head, head->scenes);
    head->scenes->in_game = menu;
    menu->clock = sfClock_create();
    menu->time = 0;
    menu->time_base = 0;
    menu->time_last_save = 0;
    set_null_object(menu);
    init_player(head);
    init_map(head, menu);
    create_button(head, PAUSE_BUTTON, &menu->button);
    init_view_in_game(menu);
    init_inventory(head, INVENTORY);
    load_quest_from_save(head, head->scenes->in_game, json_search(menu
    ->player->stat_json->data, "quests"));
    menu->boss = 0;
    for (int i = 0; i < 8; i += 1)
        menu->opened_chest[i] = 0;
}