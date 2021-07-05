/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** writer_element
*/

#include "../parser.h"

void writer_data_name(pars_data_t *data, int fd, int nb_tab)
{
    write_tab(fd, "\"", nb_tab);
    write_str(fd, data->data_name);
    write_str(fd, "\"");
    write_str(fd, ":");
}

void writer_array(pars_data_t *data, int fd, int nb_tab)
{
    write_str(fd, "[");
    for (; data; data = data->next) {
        writer_value(data, fd, nb_tab);
        if (data->next)
            write_str(fd, ", ");
    }
    write_str(fd, "]");
}

void writer_float(pars_data_t *data, int fd)
{
    return;
}

void writer_value(pars_data_t *data, int fd, int nb_tab)
{
    switch (data->type) {
    case (kint):
        write_str(fd, my_nbr_to_str(data->values.kint));
        break;
    case (kstr):
        write_str(fd, "\"");
        write_str(fd, data->values.kstr);
        write_str(fd, "\"");
        break;
    case (kfloat):
        break;
    case (kobj):
        if (data->values.kobj->data_name == NULL)
            writer_array(data->values.kobj, fd, nb_tab + 1);
        else
            write_data(data->values.kobj, fd, nb_tab + 1);
        break;
    case (knull):
        break;
    }
}