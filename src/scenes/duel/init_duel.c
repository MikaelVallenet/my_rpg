/*
** EPITECH PROJECT, 2021
** my rpg
** File description:
** init duel
*/

#include "rpg.h"

void quit_duel(head_t *head, button_t * button)
{
    head->technical->state_2_ex = STATE_DUEL;
    head->state_2 = 0;
}

void destroy_duel_scene(scenes_t *scenes)
{
    if (scenes->duel_scene == NULL)
        return;
    destroy_text_scrolling(scenes->duel_scene->text_scrolling);
    sfSprite_destroy(scenes->duel_scene->sprite);
    scenes->duel_scene = NULL;
}

void init_duel_scene(head_t *head, char *filepath)
{
    duel_scene_t *duel = malloc(sizeof(duel_scene_t));

    if (head->state == STATE_DUEL)
        scenes_unloader(head, head->scenes);
    duel->gen_ptcl = malloc(sizeof(gen_ptcl_t));
    duel->text_scrolling = malloc(sizeof(text_scrolling_t));
    duel->gen_ptcl = NULL;
    duel->text_scrolling = NULL;
    duel->texture = sfTexture_createFromFile(BLACKWALL, NULL);
    duel->sprite = sfSprite_create();
    duel->fight_bool = 0;
    sfSprite_setTexture(duel->sprite, duel->texture, sfTrue);
    head->scenes->duel_scene = duel;
    init_fight(head, load_monster(filepath));
    update_duel_text(head, head->scenes->duel_scene->fight,
    head->scenes->duel_scene->text_scrolling);
    init_attack(head->scenes->duel_scene->fight);
    init_defense(head->scenes->duel_scene->fight, head);
}