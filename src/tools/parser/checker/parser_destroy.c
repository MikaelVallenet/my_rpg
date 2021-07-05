/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** parser_destroy
*/

#include "../parser.h"

void pars_data_destroy(pars_data_t *data)
{
    pars_data_t *next;

    while (data) {
        if (data->type == kobj)
            pars_data_destroy(data->values.kobj);
        if (data->type == kstr)
            free(data->values.kstr);
        if (data->data_name)
            free(data->data_name);
        next = data->next;
        free(data);
        data = next;
    }
}

void pars_obj_destroy(pars_obj_t *obj)
{
    pars_obj_t *next;

    while (obj) {
        pars_data_destroy(obj->data);
        if (obj->obj_name)
            free(obj->obj_name);
        next = obj->next;
        free(obj);
        obj = next;
    }
}