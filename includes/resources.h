/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** resources
*/

#ifndef RESOURCES_H_
#define RESOURCES_H_

// Paths
#define RESOURCES_PATH "./assets/"
#define SAVE_PATH "./saves/"

// Fonts
typedef struct font_s {
    sfFont *basic;
} font_t;

// Textures
typedef struct texture_s {
    sfTexture *fader;
} texture_t;

// Sfx
typedef struct sfx_s {
    sfSound *click_sound;
    sfSoundBuffer *click_soundbuffer;
    sfSound *attack_sound;
    sfSoundBuffer *attack_soundbuffer;
    sfSound *defend_sound;
    sfSoundBuffer *defend_soundbuffer;
} sfx_t;

typedef struct music_s {
    sfMusic *music;
} music_t;

// Resources
typedef struct resources_s {
    font_t *fonts;
    texture_t *text;
    sfx_t *sfx;
    music_t *music;
} resources_t;


#endif /* !RESOURCES_H_ */
