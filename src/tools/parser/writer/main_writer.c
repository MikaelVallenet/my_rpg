/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** main_writer
*/

#include "../parser.h"

void write_data(pars_data_t *data, int fd, int nb_tab)
{
    write_tab(fd, "{\n", nb_tab - 1);
    while (data) {
        writer_data_name(data, fd, nb_tab);
        writer_value(data, fd, nb_tab);
        data = data->next;
        if (data)
            write_str(fd, ",");
        write_str(fd, "\n");
    }
    write_tab(fd, "}", nb_tab - 1);
}

static void write_obj(pars_obj_t *obj, int fd)
{
    for (; obj; obj = obj->next) {
        write_data(obj->data, fd, 1);
        write_str(fd, "\n");
    }
}

// If obj == NULL, it uses data
int writer_json(char *filepath, pars_obj_t *obj, pars_data_t *data)
{
    int fd = open(filepath, O_CREAT | O_RDWR | O_TRUNC);

    if (fd == -1)
        return (CREATE_ERROR);
    if (obj == NULL)
        write_data(data, fd, 1);
    else
        write_obj(obj, fd);
    close(fd);
    return (0);
}