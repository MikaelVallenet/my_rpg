/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** skill_tree
*/

#ifndef SKILL_TREE_H_
#define SKILL_TREE_H_


#include "rpg.h"

// STRUCTURE //
typedef struct skill_tree_scene_s {
    object_t *object;
    button_t *button;
    text_t *text;
    text_scrolling_t *text_scrolling;
    gen_ptcl_t *gen_ptcl;
    text_t *nb_star;
    button_t *armor_1;
    object_t *cost_armor_1;
    button_t *armor_2;
    object_t *cost_armor_2;
    button_t *armor_3;
    object_t *cost_armor_3;
    button_t *damage_1;
    object_t *cost_damage_1;
    button_t *damage_2;
    object_t *cost_damage_2;
    button_t *damage_3;
    object_t *cost_damage_3;
    button_t *speed_1;
    object_t *cost_speed_1;
    button_t *speed_2;
    object_t *cost_speed_2;
    button_t *speed_3;
    object_t *cost_speed_3;
    object_t *table_description;
} skill_tree_scenes_t;

// FUNCTION PROTOTYPE //
void init_skill_tree(head_t *head);
void init_skill_tree_aux(head_t *head, skill_tree_scenes_t *menu);
void init_text_skill_tree(head_t *head, skill_tree_scenes_t *menu);
void set_pos_text_skill_tree(head_t *head, skill_tree_scenes_t *menu);
void destroy_skill_tree(scenes_t *scene);
void skill_tree_handler(head_t *head);
void skill_tree_display(head_t *head);
void skill_tree_event(head_t *head, sfEvent event);

// UPDATE STATE BUTTON //
void set_state_speed_button(head_t *head, skill_tree_scenes_t *menu);
void set_state_damage_button(head_t *head, skill_tree_scenes_t *menu);
void set_state_armor_button(head_t *head, skill_tree_scenes_t *menu);

// BUTTON FUNCTION //
void is_hover_button_skill(head_t *head, button_t *button, sfVector2f clic);
void is_clic_button_skill(head_t *head, button_t *button, sfVector2f clic);
sfBool is_button_activate(head_t *head, button_t *button);
void quit_skill_tree(head_t *head, button_t * button);
sfBool is_button_skill(head_t *head, button_t *button);
void manage_clic_speed(head_t *head, button_t *button);
void manage_clic_armor(head_t *head, button_t *button);
void manage_clic_damage(head_t *head, button_t *button);
void clic_skill_button(head_t *head, button_t *button);

// DISPLAY //
void init_state_button(head_t *head, skill_tree_scenes_t *menu);
void display_cost_star(head_t *head);

// BUTTON PRESET //
static const button_data_t QUIT_SKILL_TREE =
{{(1920 / 2) - (966 * 1.35 / 2) + 1210,
(1080 / 2) - (627 * 1.35 / 2) - 10},
{0.85, 0.85}, CIRCLE,
"assets/buttons/close.png",
"", 20, (sfColor){255, 255, 255, 255},
"", 20, (sfColor){255, 255, 255, 255},
&quit_skill_tree};

// OBJECT PRESET //
static const object_data_t TABLE_SKILL_TREE =
{"assets/images/table/table_medium.png",
{(1920 / 2) - (966 * 1.35 / 2),
(1080 / 2) - (627 * 1.35 / 2)},
{1.35, 1.35}
};

static const object_data_t TABLE_2_SKILL_TREE =
{"assets/images/table/s_table.png",
{(1920 / 2) - (557 * 0.5 / 2), 950},
{0.5, 0.5}
};

static const object_data_t BACK_ARMOR =
{"assets/images/window/window_3.png",
{(1920 / 2) - (178 * 1.1 / 2) - 300,
(1080 / 2) - (736 * 0.9 / 2)},
{1.1, 0.9}
};

static const button_data_t ARMOR_3 =
{{(1920 / 2) - (178 * 1.1 / 2) - 285,
(1080 / 2) - (736 * 0.9 / 2) + 10},
{1, 1}, SQUARE,
"assets/skill_tree/armor_3.png",
"", 20, (sfColor){255, 255, 255, 255},
"Increase your\narmor by 10", 20, (sfColor){255, 255, 255, 255},
&clic_skill_button};

static const object_data_t COST_ARMOR_3 =
{"assets/skill_tree/cost_3_star.png",
{(1920 / 2) - (178 * 1.1 / 2) - 285 + 105,
(1080 / 2) - (736 * 0.9 / 2) + 10 + 123},
{1, 1}
};

static const button_data_t ARMOR_2 =
{{(1920 / 2) - (178 * 1.1 / 2) - 285,
(1080 / 2) - (736 * 0.9 / 2) + 10 + 190},
{1, 1}, SQUARE,
"assets/skill_tree/armor_2.png",
"", 20, (sfColor){255, 255, 255, 255},
"Increase your\narmor by 6", 20, (sfColor){255, 255, 255, 255},
&clic_skill_button};

static const object_data_t COST_ARMOR_2 =
{"assets/skill_tree/cost_2_star.png",
{(1920 / 2) - (178 * 1.1 / 2) - 285 + 105,
(1080 / 2) - (736 * 0.9 / 2) + 10 + 190 + 123},
{1, 1}
};

static const button_data_t ARMOR_1 =
{{(1920 / 2) - (178 * 1.1 / 2) - 285,
(1080 / 2) - (736 * 0.9 / 2) + 10 + 380},
{1, 1}, SQUARE,
"assets/skill_tree/armor_1.png",
"", 20, (sfColor){255, 255, 255, 255},
"Increase your\narmor by 3", 20, (sfColor){255, 255, 255, 255},
&clic_skill_button};

static const object_data_t COST_ARMOR_1 =
{"assets/skill_tree/cost_1_star.png",
{(1920 / 2) - (178 * 1.1 / 2) - 285 + 105,
(1080 / 2) - (736 * 0.9 / 2) + 10 + 380 + 123},
{1, 1}
};

static const object_data_t BACK_DAMAGE =
{"assets/images/window/window_3.png",
{(1920 / 2) - (178 * 1.1 / 2),
(1080 / 2) - (736 * 0.9 / 2)},
{1.1, 0.9}
};

static const button_data_t DAMAGE_3 =
{{(1920 / 2) - (178 * 1.1 / 2) + 15,
(1080 / 2) - (736 * 0.9 / 2) + 10},
{1, 1}, SQUARE,
"assets/skill_tree/damage_3.png",
"", 20, (sfColor){255, 255, 255, 255},
"Increase your\ndamage by 10", 20, (sfColor){255, 255, 255, 255},
&clic_skill_button};

static const object_data_t COST_DAMAGE_3 =
{"assets/skill_tree/cost_3_star.png",
{(1920 / 2) - (178 * 1.1 / 2) + 15 + 105,
(1080 / 2) - (736 * 0.9 / 2) + 10 + 123},
{1, 1}
};

static const button_data_t DAMAGE_2 =
{{(1920 / 2) - (178 * 1.1 / 2) + 15,
(1080 / 2) - (736 * 0.9 / 2) + 10 + 190},
{1, 1}, SQUARE,
"assets/skill_tree/damage_2.png",
"", 20, (sfColor){255, 255, 255, 255},
"Increase your\ndamage by 6", 20, (sfColor){255, 255, 255, 255},
&clic_skill_button};

static const object_data_t COST_DAMAGE_2 =
{"assets/skill_tree/cost_2_star.png",
{(1920 / 2) - (178 * 1.1 / 2) + 15 + 105,
(1080 / 2) - (736 * 0.9 / 2) + 10 + 190 + 123},
{1, 1}
};

static const button_data_t DAMAGE_1 =
{{(1920 / 2) - (178 * 1.1 / 2) + 15,
(1080 / 2) - (736 * 0.9 / 2) + 10 + 380},
{1, 1}, SQUARE,
"assets/skill_tree/damage_1.png",
"", 20, (sfColor){255, 255, 255, 255},
"Increase your\ndamage by 3", 20, (sfColor){255, 255, 255, 255},
&clic_skill_button};

static const object_data_t COST_DAMAGE_1 =
{"assets/skill_tree/cost_1_star.png",
{(1920 / 2) - (178 * 1.1 / 2) + 15 + 105,
(1080 / 2) - (736 * 0.9 / 2) + 10 + 380 + 123},
{1, 1}
};

static const object_data_t BACK_SPEED =
{"assets/images/window/window_3.png",
{(1920 / 2) - (178 * 1.1 / 2) + 295,
(1080 / 2) - (736 * 0.9 / 2)},
{1.1, 0.9}
};

static const button_data_t SPEED_3 =
{{(1920 / 2) - (178 * 1.1 / 2) + 310,
(1080 / 2) - (736 * 0.9 / 2) + 10},
{1, 1}, SQUARE,
"assets/skill_tree/speed_3.png",
"", 20, (sfColor){255, 255, 255, 255},
"Increase your\nspeed by 0.6", 20, (sfColor){255, 255, 255, 255},
&clic_skill_button};

static const object_data_t COST_SPEED_3 =
{"assets/skill_tree/cost_3_star.png",
{(1920 / 2) - (178 * 1.1 / 2) + 310 + 105,
(1080 / 2) - (736 * 0.9 / 2) + 10 + 123},
{1, 1}
};

static const button_data_t SPEED_2 =
{{(1920 / 2) - (178 * 1.1 / 2) + 310,
(1080 / 2) - (736 * 0.9 / 2) + 10 + 190},
{1, 1}, SQUARE,
"assets/skill_tree/speed_2.png",
"", 20, (sfColor){255, 255, 255, 255},
"Increase your\nspeed by 0.3", 20, (sfColor){255, 255, 255, 255},
&clic_skill_button};

static const object_data_t COST_SPEED_2 =
{"assets/skill_tree/cost_2_star.png",
{(1920 / 2) - (178 * 1.1 / 2) + 310 + 105,
(1080 / 2) - (736 * 0.9 / 2) + 10 + 190 + 123},
{1, 1}
};

static const button_data_t SPEED_1 =
{{(1920 / 2) - (178 * 1.1 / 2) + 310,
(1080 / 2) - (736 * 0.9 / 2) + 10 + 380},
{1, 1}, SQUARE,
"assets/skill_tree/speed_1.png",
"", 20, (sfColor){255, 255, 255, 255},
"Increase your\nspeed by 0.2", 20, (sfColor){255, 255, 255, 255},
&clic_skill_button};

static const object_data_t COST_SPEED_1 =
{"assets/skill_tree/cost_1_star.png",
{(1920 / 2) - (178 * 1.1 / 2) + 310 + 105,
(1080 / 2) - (736 * 0.9 / 2) + 10 + 380 + 123},
{1, 1}
};

static const object_data_t NB_STAR =
{"assets/skill_tree/nb_star.png",
{(1920 / 2) - (966 * 1.35 / 2) + 45,
(1080 / 2) - (627 * 1.35 / 2) + 720},
{1.5, 1.5}
};

// TEXT PRESET //
static const text_data_t TEXT_ARMOR =
{"assets/fonts/Dimbo.ttf",
"Armor", 70,
{(1920 / 2) - (178 * 1.1 / 2) - 285 + 10,
(1080 / 2) - (736 * 0.9 / 2) + 10 + 380 + 170},
(sfColor){255, 255, 255, 255}};

static const text_data_t TEXT_DAMAGE =
{"assets/fonts/Dimbo.ttf",
"Damage", 70,
{(1920 / 2) - (178 * 1.1 / 2) + 15,
(1080 / 2) - (736 * 0.9 / 2) + 10 + 380 + 170},
(sfColor){255, 255, 255, 255}};

static const text_data_t TEXT_SPEED =
{"assets/fonts/Dimbo.ttf",
"Speed", 70,
{(1920 / 2) - (178 * 1.1 / 2) + 310 + 10,
(1080 / 2) - (736 * 0.9 / 2) + 10 + 380 + 170},
(sfColor){255, 255, 255, 255}};

static const text_data_t TEXT_NB_STAR =
{"assets/fonts/Dimbo.ttf",
"0", 45,
{(1920 / 2) - (966 * 1.35 / 2) + 60,
(1080 / 2) - (627 * 1.35 / 2) + 725},
(sfColor){255, 255, 255, 255}};

static const text_data_t TEXT_SKILL_TREE =
{"assets/fonts/Dimbo.ttf",
"Skill Tree", 175,
{(1920 / 2) - (966 * 1.35 / 2) + 1260,
(1080 / 2) - (627 * 1.35 / 2) + 155},
(sfColor){255, 255, 255, 255}};

#endif /* !SKILL_TREE_H_ */