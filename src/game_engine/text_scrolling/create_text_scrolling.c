/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create object
*/

#include "rpg.h"

text_scrolling_t *get_last_text_scro(text_scrolling_t *first_text)
{
    while ((first_text)->next != NULL)
        first_text = (first_text)->next;
    return (first_text);
}

static int read_text(text_scrolling_t *text)
{
    struct stat size;
    int fd = open(text->filepath, O_RDONLY);

    if (fd < 0)
        return (84);
    stat(text->filepath, &size);
    text->str = malloc(sizeof(char) * size.st_size + 1);
    text->str_display = malloc(sizeof(char) * size.st_size + 1);
    if (size.st_size == 0)
        return (84);
    if (S_ISREG(size.st_mode) != 1)
        return (84);
    read(fd, text->str, size.st_size);
    text->str[size.st_size] = '\0';
    text->str_display[0] = '\0';
    if (text->speed == 1)
        my_strcpy(text->str_display, text->str);
    close(fd);
    return (0);
}

static void init_param_text(head_t *head, text_data_scrolling_t data,
text_scrolling_t *new_text)
{
    new_text->title = data.title;
    new_text->position = data.position;
    sfText_setColor(new_text->text, data.color);
    sfText_setCharacterSize(new_text->text, data.size);
    sfText_setFont(new_text->text, head->res->fonts->basic);
    sfText_setString(new_text->text, new_text->str_display);
    sfText_setPosition(new_text->text, new_text->position);
    new_text->sound = sfSound_create();
    new_text->soundbuffer =
    sfSoundBuffer_createFromFile("./assets/typing.ogg");
    sfSound_setBuffer(new_text->sound, new_text->soundbuffer);
    sfSound_setLoop(new_text->sound, sfTrue);
    new_text->display = 0;
    new_text->last_move = 0;
    new_text->time = 0;
    new_text->time_base = 0;
    new_text->start = 0;
    new_text->i = 0;
}

static void set_raw_text(text_data_scrolling_t data,
text_scrolling_t *new_text)
{
    new_text->str = malloc(sizeof(char) * my_strlen(data.origin_str) + 1);
    new_text->str_display =
    malloc(sizeof(char) * my_strlen(data.origin_str) + 1);
    my_strcpy(new_text->str, data.origin_str);
    if (new_text->speed == 1) {
        my_strcpy(new_text->str_display, data.origin_str);
        new_text->text_event = &handler_text_scrolling_off;
    }
    else {
        new_text->str_display[0] = '\0';
        new_text->text_event = &handler_text_scrolling;
    }
}

void create_text_scrolling(head_t *head, text_data_scrolling_t data,
text_scrolling_t **list_text)
{
    text_scrolling_t *new_text = malloc(sizeof(text_scrolling_t));

    new_text->filepath = data.filepath;
    new_text->speed = data.speed;
    if (data.filepath != NULL) {
        read_text(new_text);
        new_text->text_event = &handler_text_scrolling;
    }
    else {
        set_raw_text(data, new_text);
    }
    new_text->text = sfText_create();
    init_param_text(head, data, new_text);
    new_text->clock = sfClock_create();
    new_text->next = NULL;
    sfText_setPosition(new_text->text, new_text->position);
    if (*list_text != NULL)
        get_last_text_scro(*list_text)->next = new_text;
    else
        *list_text = new_text;
}