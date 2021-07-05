/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Header tools
*/

#ifndef TOOLS_H
#define TOOLS_H

#include "rpg.h"

typedef struct pars_obj_s pars_obj_t;
typedef struct pars_data_s pars_data_t;
typedef struct text_s text_t;

// // Parser // //
#ifndef PARS_DATA
#define PARS_DATA

typedef struct pars_map_s pars_map_t;
typedef struct map_s map_t;

// Type
typedef enum type_s {
    kint,
    kfloat,
    kstr,
    kobj,
    knull
} type_t;

typedef union values_s {
    int kint;
    float kfloat;
    char *kstr;
    pars_data_t *kobj;
} values_t;

// Data
typedef struct pars_data_s {
    char *data_name;
    type_t type;
    values_t values;
    struct pars_data_s *next;
} pars_data_t;

typedef struct pars_obj_s {
    char *obj_name;
    pars_data_t *data;
    struct pars_obj_s *next;
} pars_obj_t;
#endif /* !PARS_DATA */

// // Prototype // //
int writer_json(char *filepath, pars_obj_t *obj, pars_data_t *data);
void pars_obj_destroy(pars_obj_t *obj);
void pars_data_destroy(pars_data_t *data);
void show_data(pars_data_t *data);
pars_data_t *json_obj(char **str);
pars_data_t *json_search(pars_data_t *data, const char *to_find);
void set_volume(head_t *head, float volume);

// PROTOTYPE //
sfBool is_in_button(button_t *button, sfVector2f clic);
sfText *sftext_create(sfFont *font, sfColor color, int size, char *str);

// TIME //
float get_time(head_t *head);

int file_size(char *file_path);
int read_file(char *file_path, char **buffer);
pars_obj_t *parser_json(char *filepath);
int mrand(void);
char *get_path_save(head_t *head);
void delete_save(char *path);

// TEXT //
text_t *get_last_text(text_t *first);

#endif /* !TOOLS_H */