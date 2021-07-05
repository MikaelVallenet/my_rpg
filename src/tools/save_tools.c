/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** save_tools
*/

#include "rpg.h"

void delete_save(char *path)
{
    int flags = O_CREAT | O_WRONLY | O_TRUNC;

    close(open(path, flags, S_IRWXU));
}

char *get_path_save(head_t *head)
{
    if (head->technical->index_save == 1)
        return ("saves/save_1.json");
    if (head->technical->index_save == 2)
        return ("saves/save_2.json");
    if (head->technical->index_save == 3)
        return ("saves/save_3.json");
    return (NULL);
}