/*
** EPITECH PROJECT, 2021
** DUEL_H
** File description:
** DUEL_H
*/

#ifndef DUEL_H
#define DUEL_H

#include "rpg.h"

#define BLACKWALL "./assets/blackwall.jpg"

typedef struct head_s head_t;
typedef struct fight_s fight_t;

//STRUCTURE

typedef struct duel_scene_s {
    sfTexture *texture;
    sfSprite *sprite;
    text_scrolling_t *text_scrolling;
    gen_ptcl_t *gen_ptcl;
    fight_t *fight;
    int fight_bool;
} duel_scene_t;

// FUNCTION PROTOTYPE

void init_duel_scene(head_t *head, char *filepath);
void destroy_duel_scene(scenes_t *scenes);
void open_duel_menu(head_t *head, char *filepath);
void duel_event(head_t *head, sfEvent event);
void duel_handler(head_t *head);
void duel_display(head_t *head);
void quit_duel(head_t *head, button_t * button);
void display_infos(head_t *head, fight_t *fight);
void handle_attack(head_t *head, fight_t *fight);
void press_space_attack(head_t *head, fight_t *fight);
void handle_defense(head_t *head, fight_t *fight);

#endif /* !DUEL_H */
