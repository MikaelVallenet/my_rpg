/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** load_face_convesation
*/

#include "rpg.h"

void load_face_npc_conversation(head_t *head, npc_t *npc)
{
    char *path = json_search(npc->data, "image")->values.kstr;
    pars_data_t *data = npc->current_conversation_data->data;
    pars_data_t *data_2 = json_search(data, "face")->values.kobj;
    int x = json_search(data_2, "top_rect")->values.kint;
    int y = json_search(data_2, "left_rect")->values.kint;
    sfIntRect rect = {y, x, 76, 75};
    sfVector2f pos = {20, 685};
    sfVector2f scale = {5, 5};

    head->scenes->in_game->face = malloc(sizeof(object_t));
    head->scenes->in_game->face->sprite = sfSprite_create();
    head->scenes->in_game->face->texture =
    sfTexture_createFromFile(path, &rect);
    sfSprite_setTexture(head->scenes->in_game->face->sprite,
    head->scenes->in_game->face->texture, sfFalse);
    sfSprite_setPosition(head->scenes->in_game->face->sprite, pos);
    sfSprite_setScale(head->scenes->in_game->face->sprite, scale);
    head->scenes->in_game->face->next = NULL;
}

void load_face_player_conversation(head_t *head, npc_t *npc, player_t *player)
{
    player_data_t data_p = get_preset_player(head);
    pars_data_t *data = npc->current_conversation_data->data;
    pars_data_t *data_2 = json_search(data, "face")->values.kobj;
    int x = json_search(data_2, "top_rect")->values.kint;
    int y = json_search(data_2, "left_rect")->values.kint;
    sfIntRect rect = {y, x, 76, 75};

    sfTexture_destroy(head->scenes->in_game->face->texture);
    head->scenes->in_game->face->texture =
    sfTexture_createFromFile(data_p.path, &rect);
    sfSprite_setTexture(head->scenes->in_game->face->sprite,
    head->scenes->in_game->face->texture, sfFalse);
}

void load_face_conversation(head_t *head, npc_t *npc, player_t *player)
{
    pars_data_t *data = npc->current_conversation_data->data;
    char *speaker = json_search(data, "speaker")->values.kstr;

    if (my_strcmp("npc", speaker) == 0)
        load_face_npc_conversation(head, npc);
    else
        load_face_player_conversation(head, npc, player);
}
