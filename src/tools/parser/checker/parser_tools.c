/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** parser_tools
*/

#include "../parser.h"

int my_strparser(char *str, const char *to_compare)
{
    int i;

    for (i = 0; str[i] == to_compare[i]; i++);
    if (to_compare[i] == '\0')
        return 1;
    return 0;
}

void json_whitespace(char **str)
{
    for (; (**str == ' ' || **str == '\t' ||
    **str == '\n' || **str == '\r') && **str != 0; *str += 1);
}

pars_data_t *json_search(pars_data_t *data, const char *to_find)
{
    while (data != NULL) {
        if (my_strcmp((char *)to_find, data->data_name) == 0)
            return (data);
        data = data->next;
    }
    return (NULL);
}