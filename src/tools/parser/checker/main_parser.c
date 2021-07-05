/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** parser
*/

#include "../parser.h"

pars_data_t *json_obj(char **str)
{
    pars_data_t *data = malloc(sizeof(pars_data_t));
    pars_data_t *first_data = data;

    for (; **str; *str += (**str == ',')) {
        data->next = NULL;
        json_whitespace(str);
        if (**str == '}') {
            data->type = knull;
            break;
        }
        data->data_name = json_string(str);
        json_whitespace(str);
        *str += (**str == ':');
        json_value(str, data);
        if (**str == '}')
            break;
        data->next = malloc(sizeof(pars_data_t));
        data = data->next;
    }
    *str += (**str == '}');
    return (first_data);
}

static pars_obj_t *read_json(char *str)
{
    pars_obj_t *obj = malloc(sizeof(pars_obj_t));
    pars_obj_t *first = obj;
    pars_obj_t *prev;

    for (; *str; str += (*str != 0)) {
        if (*str == '{') {
            str += 1;
            obj->obj_name = NULL;
            obj->data = json_obj(&str);
            obj->next = malloc(sizeof(pars_obj_t));
            prev = obj;
            obj = obj->next;
            obj->next = NULL;
        }
    }
    free(obj);
    prev->next = NULL;
    return (first);
}

pars_obj_t *parser_json(char *filepath)
{
    char *str;
    pars_obj_t *obj;

    read_file(filepath, &str);
    obj = read_json(str);
    free(str);
    return (obj);
}