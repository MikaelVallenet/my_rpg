/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** unloader
*/

#include "rpg.h"

void main_destroy(head_t *head)
{
    sfMusic_destroy(head->res->music->music);
    sfSound_destroy(head->res->sfx->click_sound);
    sfSoundBuffer_destroy(head->res->sfx->click_soundbuffer);
    sfSound_destroy(head->res->sfx->attack_sound);
    sfSoundBuffer_destroy(head->res->sfx->attack_soundbuffer);
    sfSound_destroy(head->res->sfx->defend_sound);
    sfSoundBuffer_destroy(head->res->sfx->defend_soundbuffer);
    free(head->engine);
    free(head->option);
    free(head->res);
    free(head->technical);
    scenes_unloader(head, head->scenes);
    sfRenderWindow_destroy(head->window);
    free(head);
}