/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Header
*/

#ifndef BUTTONS_H
#define BUTTONS_H

#include "rpg.h"

// // STRUCTURE // //
// OBJECT //

typedef struct object_data_s {
    char *path;
    sfVector2f pos;
    sfVector2f scale;
} object_data_t;

typedef struct object_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    struct object_s *next;
} object_t;

// BUTTON //
#define SQUARE 0
#define CIRCLE 1

typedef struct button_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfText *text;
    sfText *hover_text;
    sfVector2f pos_original;
    sfVector2f scale_original;
    int type;
    sfClock *clock;
    void (*call_func)(head_t*, button_t*);
    struct button_s *next;
} button_t;

//GENERATOR PARTICLE

#define G_INFINITE -1
#define G_SLOW 0.5
#define G_MEDIUM 0.2
#define G_FAST 0.1

typedef struct gen_direction_s {
    int north;
    int south;
    int west;
    int est;
} gen_direction_t;

typedef struct ptcl_s {
    sfSprite *particle;
    sfVector2f position;
    int age;
    int step_x;
    int step_y;
    int spawn;
    int opacity;
    int passage;
} ptcl_t;

typedef struct gen_ptcl_s gen_ptcl_t;

typedef struct gen_ptcl_s {
    char *title;
    ptcl_t *particles;
    char *path_texture;
    char *path_sound;
    int nb_ptcl;
    float max_time;
    float gen_speed;
    int speed_max;
    int slow;
    sfVector2f position;
    sfVector2f scale;
    int age_max;
    sfTexture *texture;
    sfSound *sound;
    sfSoundBuffer *soundbuffer;
    sfClock *clock;
    float time;
    float time_base;
    void (*gen_ptcl_event)(gen_ptcl_t*);
    int start;
    int audio;
    float opacity;
    float last_move;
    gen_direction_t direction;
    struct gen_ptcl_s *next;
} gen_ptcl_t;


//TEXT

#define T_FULL 1
#define T_LOW 0.15
#define T_MEDIUM 0.08
#define T_FAST 0.05

typedef struct text_scrolling_s text_scrolling_t;

typedef struct text_scrolling_s {
    char *title;
    char *filepath;
    char *origin_str;
    char *str;
    char *str_display;
    sfText *text;
    sfSound *sound;
    sfSoundBuffer *soundbuffer;
    sfVector2f position;
    float speed;
    sfClock *clock;
    float time;
    float time_base;
    float last_move;
    void (*text_event)(text_scrolling_t*);
    int start;
    int i;
    int display;
    struct text_scrolling_s *next;
} text_scrolling_t;

// // PROTOTYPE // //

typedef struct gen_ptcl_data_s {
    char *title;
    char *path_texture;
    char *path_sound;
    int nb_ptcl;
    int speed_max;
    sfVector2f scale;
    float gen_speed;
    float max_time;
    int age_max;
    int slow;
    float opacity;
    sfVector2f position;
    gen_direction_t direction;

} gen_ptcl_data_t;

typedef struct button_data_s {
    sfVector2f pos;
    sfVector2f scale;
    int type;
    char *path;
    char *text_str;
    int size_text;
    sfColor color_text;
    char *hover_text_str;
    int size_hover_text;
    sfColor color_hover_text;
    void (*call_func)(head_t*, button_t*);
} button_data_t;

typedef struct text_data_scrolling_s {
    char *title;
    char *filepath;
    char *origin_str;
    sfVector2f position;
    sfColor color;
    int size;
    float speed;
} text_data_scrolling_t;

typedef struct text_data_s {
    char *path;
    char *text_str;
    int size_text;
    sfVector2f pos;
    sfColor color_text;
} text_data_t;

typedef struct text_s {
    sfText *text;
    sfFont *font;
    sfVector2f pos_original;
    int size;
    struct text_s *next;
} text_t;

// // PROTOTYPE // //
// OBJECT //
void create_object(object_data_t data, object_t **object);
void destroy_object(object_t *object);
void display_object(head_t *head, object_t *first);
object_t *get_last_object(object_t *object);
void destroy_one_object(object_t *object);

// BUTTON //
void create_button(head_t *head, button_data_t data, button_t **list_button);
void is_hover_button(button_t *button, sfVector2f clic);
void is_clic_button(head_t *head, button_t *button, sfVector2f clic);
void destroy_button(button_t *button);
void display_button(head_t *head, button_t *first);
void animation_button_clic(button_t *but);
void animation_button_none(button_t *but);
button_t *get_last_button(button_t *first_button);

// TEXT //
void create_text(text_data_t data, text_t **object);
void destroy_text(text_t *object);
void display_text(head_t *head, text_t *first);
void set_pos_hover_text(button_t *button);
text_t *get_last_text(text_t *object);

// WINDOW //
void switch_full_screen_window(head_t *head, option_t *option);
void resize_window(head_t *head, option_t *option);
void update_button_fullscreen(head_t *head, button_t *object);

// MUSIC //
sfMusic *create_music(head_t *head, char *path);
void update_bar_music(head_t *head, object_t *object);
void update_button_on_off_music(head_t *head, button_t *object);

// SOUND //
void update_bar_sound(head_t *head, object_t *object);
void update_button_on_off_sound(head_t *head, button_t *object);

// TEXT //
void create_text_scrolling(head_t *head, text_data_scrolling_t data,
text_scrolling_t **list_text);
void handler_text_scrolling(text_scrolling_t *text);
void destroy_text_scrolling(text_scrolling_t *list_text);
void display_text_scrolling(head_t *head, text_scrolling_t *list_text);
float get_time_text_scrolling(text_scrolling_t* text);
void animation_text_scrolling(text_scrolling_t *list_text);
void start_text_scrolling(char *title, text_scrolling_t *text);
void stop_text_scrolling(char *title, text_scrolling_t *text);
void start_text_scrolling_all(text_scrolling_t *text);
void stop_text_scrolling_all(text_scrolling_t *text);
void reset_text_scrolling_all(text_scrolling_t *text);
void handler_text_scrolling_off(text_scrolling_t *text);
void update_text_scrolling(text_scrolling_t *text, char *new_str);
text_scrolling_t *find_text(char *title, text_scrolling_t *text);
void display_on_text_scrolling(char *title, text_scrolling_t *text);
void display_off_text_scrolling(char *title, text_scrolling_t *text);
text_scrolling_t *find_text(char *title, text_scrolling_t *text);
void update_text_scrolling(text_scrolling_t *text, char *new_str);
void reset_text_scrolling(char *title, text_scrolling_t *text, char *new_str);
text_scrolling_t *get_last_text_scro(text_scrolling_t *first_text);
void skip_animation_text_scrolling(char *name, text_scrolling_t *list);

// PARTICLES //
void create_gen_ptcl(gen_ptcl_data_t data, gen_ptcl_t **list_gen_ptcl);
void handler_gen_ptcl(gen_ptcl_t *gen_ptcl_t);
void destroy_gen_ptcl(gen_ptcl_t *list_gen_ptcl);
float get_time_gen(gen_ptcl_t *gen_ptcl);
gen_ptcl_t *find_gen_ptcl(char *title, gen_ptcl_t *gen_ptcl);
void start_gen_ptcl(char *title, gen_ptcl_t *gen_ptcl);
void stop_gen_ptcl(char *title, gen_ptcl_t *gen_ptcl);
void display_gen_ptcl(head_t *head, gen_ptcl_t *gen_ptcl);
void animation_gen_ptcl(gen_ptcl_t *list_gen_ptcl);
void direction_gen_ptcl(gen_ptcl_t *gen_ptcl, int i);
void reset_gen_ptcl(char *title, gen_ptcl_t *gen_ptcl);
void update_bar(object_t *object, int value);


#endif /* !BUTTONS_H */