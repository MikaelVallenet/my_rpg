/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** parser_element
*/

#include "../parser.h"

char *json_string(char **str)
{
    int word_len = 0;
    char *key;
    int j = 0;

    *str += 1;
    for (int i = 0; str[0][i] && str[0][i] != '"'; i++)
        word_len += 1;
    key = malloc(sizeof(char) * (word_len + 2));
    for (int i = 0; i < word_len; i += 1) {
        if (str[0][i] == '\\')
            continue;
        if (i != 0 && str[0][i] == 'n' && str[0][i - 1] == '\\') {
            key[j++] = '\n';
            continue;
        }
        key[j++] = str[0][i];
    }
    key[j] = 0;
    *str += word_len + 1;
    return key;
}

static pars_data_t *json_array(char **str)
{
    pars_data_t *value = malloc(sizeof(pars_data_t));
    pars_data_t *first = value;

    for (*str += 1; **str; *str += (**str == ',')) {
        json_value(str, value);
        value->data_name = NULL;
        if (**str == ']')
            break;
        value->next = malloc(sizeof(pars_data_t));
        value = value->next;
    }
    *str += 1;
    value->next = NULL;
    return first;
}

static float json_number(char **str)
{
    double number = 0;
    double virgule = 0;

    if (my_strparser(*str, "true")) {
        *str += 4;
        return (1);
    }
    if (my_strparser(*str, "false")) {
        *str += 5;
        return (0);
    }
    number = my_getnbr(*str);
    for (; **str == '-' || ('0' <= **str && **str <= '9'); *str += 1);
    if (**str == '.')
        virgule = ABS(my_getnbr(*str + 1));
    for (; virgule > 1; virgule /= 10);
    for (*str += (**str == '.'); '0' <= **str && **str <= '9'; *str += 1);
    number += virgule;
    return number;
}

void json_value_number(char **str, pars_data_t *obj)
{
    float tmp;

    tmp = json_number(str);
    if ((int) tmp == tmp) {
        obj->values.kint = (int) tmp;
        obj->type = (int) kint;
    } else {
        obj->values.kfloat = tmp;
        obj->type = kfloat;
    }
}

void json_value(char **str, pars_data_t *obj)
{
    json_whitespace(str);
    if (**str == '{') {
        *str += 1;
        obj->type = kobj;
        obj->values.kobj = json_obj(str);
        return;
    }
    if (**str == '"') {
        obj->values.kstr = json_string(str);
        obj->type = kstr;
    } else if (**str == '[') {
        obj->values.kobj = json_array(str);
        obj->type = kobj;
    } else
        json_value_number(str, obj);
    json_whitespace(str);
}