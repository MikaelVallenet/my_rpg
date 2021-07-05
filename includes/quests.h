/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** quests
*/

#ifndef QUESTS_H_
#define QUESTS_H_

#include "tools.h"

typedef struct in_game_s in_game_t;

// Quests structures
enum quest_value {
    MAIN_QUEST,
    SECONDARY_QUEST
};

typedef struct awards_s {
    int id;
    int quantity;
} awards_t;

typedef struct quest_npc_s {
    char *npc_name;
    char *conversation; // filepath
} quest_npc_t;

typedef struct quest_event_s {
    char *name;
    sfBool activated;
} quest_event_t;

typedef struct quest_objective_s {
    char *obj_name;
    int cur_nb;
    int nb;
} quest_objective_t;

typedef struct quest_step_s {
    int id;
    char *description;
    quest_npc_t **npc;
    quest_event_t **event;
    quest_objective_t **objective;
} quest_step_t;

typedef struct quest_s {
    char *name;
    char *description;
    int quest_id;
    awards_t **awards; // list non chainé
    quest_step_t **step;
    int current_step;
    char *awards_desc;
    enum quest_value value; // Quête principal ou secondaire
    pars_obj_t *obj;
    struct quest_s *next;
} quest_t;

enum quests {
    MQ_BEGINNING,
    SQ_CHICKEN
};

void load_quest_from_save(head_t *head, in_game_t *game, pars_data_t *data);
pars_data_t *save_quests_progress(quest_t *quest);
void main_quest(head_t *head, in_game_t *game, quest_t *quest);
int verify_quest_event(head_t *head, quest_t *quest, char *name);
int add_to_quest(quest_t *quest,
char *quest_name, char *objective_name, int nb);
#endif /* !QUESTS_H_ */
