/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** parser
*/

#ifndef PARSER_H_
#define PARSER_H_

#include "my_lib.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct pars_obj_s pars_obj_t;
typedef struct pars_data_s pars_data_t;

int show_error(char *message);
#define CREATE_ERROR show_error("Error: Can't create file")

// Enums
typedef enum bool_s {
    false = 0,
    true = 1
} bool_t;

// Structures
#ifndef PARS_DATA
#define PARS_DATA

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

// Prototype

char *get_key(char **str);
int my_strparser(char *str, const char *to_compare);

void json_whitespace(char **str);

char *json_string(char **str);
void json_value(char **str, pars_data_t *obj);

// Writer
void write_str(int fd, char *str);
void write_tab(int fd, char *str, int nb_tab);
void writer_data_name(pars_data_t *data, int fd, int nb_tab);
void write_data(pars_data_t *data, int fd, int nb_tab);
void writer_value(pars_data_t *data, int fd, int nb_tab);
int read_file(char *file_path, char **buffer);

int writer_json(char *filepath, pars_obj_t *obj, pars_data_t *data);
void pars_obj_destroy(pars_obj_t *obj);
void pars_data_destroy(pars_data_t *data);
void show_data(pars_data_t *data);
pars_data_t *json_obj(char **str);
pars_data_t *json_search(pars_data_t *data, const char *to_find);

#endif /* !PARSER_H_ */
