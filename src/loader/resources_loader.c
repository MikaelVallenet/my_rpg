/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** resources_loader
*/

#include "rpg.h"


static sfx_t *sfx_initialize(head_t *head)
{
    sfx_t *sfx = malloc(sizeof(sfx_t));

    sfx->click_soundbuffer =
    sfSoundBuffer_createFromFile("./assets/click.ogg");
    sfx->click_sound = sfSound_create();
    sfSound_setBuffer(sfx->click_sound, sfx->click_soundbuffer);
    sfSound_setVolume(sfx->click_sound, head->option->sound_volume);
    sfx->attack_soundbuffer =
    sfSoundBuffer_createFromFile("./assets/attack.ogg");
    sfx->attack_sound = sfSound_create();
    sfSound_setBuffer(sfx->attack_sound, sfx->attack_soundbuffer);
    sfSound_setVolume(sfx->attack_sound, head->option->sound_volume);
    sfx->defend_soundbuffer =
    sfSoundBuffer_createFromFile("./assets/defend.ogg");
    sfx->defend_sound = sfSound_create();
    sfSound_setBuffer(sfx->defend_sound, sfx->defend_soundbuffer);
    sfSound_setVolume(sfx->defend_sound, head->option->sound_volume);
    return (sfx);
}

static font_t *font_initialize(void)
{
    font_t *font = malloc(sizeof(font_t));

    font->basic = sfFont_createFromFile("assets/fonts/Dimbo.ttf");
    return (font);
}

static music_t *music_initialize(head_t *head)
{
    music_t *music = malloc(sizeof(music_t));

    music->music = create_music(head, "./assets/main_menu_music.ogg");
    return (music);
}

static texture_t *texture_initialize(option_t *option)
{
    texture_t *tex = malloc(sizeof(texture_t));
    int size = option->mode.width * option->mode.height
    * option->mode.bitsPerPixel;
    sfUint8 *pixels = malloc(size + 1);

    for (int i = 0; i < size; i++)
        pixels[i] = ((i + 1) % 4 == 0) ? 255 : 0;
    tex->fader = sfTexture_create(option->mode.width, option->mode.height);
    sfTexture_updateFromPixels(tex->fader, pixels,
    option->mode.width, option->mode.height, 0, 0);
    return (tex);
}

resources_t *res_initialize(head_t *head)
{
    resources_t *res = malloc(sizeof(resources_t));

    res->fonts = font_initialize();
    res->music = music_initialize(head);
    res->sfx = sfx_initialize(head);
    res->text = texture_initialize(head->option);
    return (res);
}