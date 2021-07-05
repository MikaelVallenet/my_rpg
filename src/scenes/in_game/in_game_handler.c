/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** in_game_handler
*/

#include "rpg.h"

void in_game_event(head_t *head, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
        open_pause_menu(head, NULL);
        return;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS) {
        open_skill_tree(head);
        return;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyQ) {
        open_quest_menu(head, NULL);
        return;
    }
    player_event(head, event, head->scenes->in_game->player);
    event_inventory(head, event);
    manage_event_button_in_game(head, event);
}

void in_game_handler(head_t *head)
{
    game_event_manager(head);
    update_inventory_str(head->scenes->in_game->inventory,
    head->scenes->in_game->text_scrolling, head->scenes->in_game->player);
    update_item_text(head->scenes->in_game->inventory,
    head->scenes->in_game->text_scrolling);
    handle_items_over_effect(head, head->scenes->in_game->inventory);
    handler_drag_and_drop(head, head->scenes->in_game->inventory);
    head->scenes->in_game->time = head->scenes->in_game->time_base;
    head->scenes->in_game->time += get_time(head);
    update_timer(head, head->scenes->in_game->inventory);
    follow_player(head);
    lvl_up(head->scenes->in_game->player);
    destroy_stacked_item(head, head->scenes->in_game->inventory);
    check_interaction_npc(head, head->scenes->in_game->npc);
    animation_text_scrolling(head->scenes->in_game->text_scrolling);
    main_quest(head, head->scenes->in_game, head->scenes->in_game->quests);
    animation_text_scrolling(head->scenes->in_game->current_conversation);
    handler_npc(head);
}

void in_game_display(head_t *head)
{
    sfRenderWindow_setView(head->window, head->scenes->in_game->view);
    sfRenderWindow_clear(head->window, sfBlack);
    display_map(head, head->scenes->in_game);
    display_npc(head, head->scenes->in_game->npc);
    display_player(head, head->scenes->in_game->player);
    display_map_top(head, head->scenes->in_game);
    if (head->scenes->in_game->event_text_display)
        display_cloud(head, head->scenes->in_game->player);
    sfRenderWindow_setView(head->window, head->technical->view);
    display_inventory(head);
    display_items_inventory(head, head->scenes->in_game->inventory);
    display_item_window(head, head->scenes->in_game->inventory);
    display_object(head, head->scenes->in_game->object);
    display_button(head, head->scenes->in_game->button);
    display_text(head, head->scenes->in_game->text);
    display_gen_ptcl(head, head->scenes->in_game->gen_ptcl);
    display_conversation(head, head->scenes->in_game->player);
    display_text_scrolling(head, head->scenes->in_game->text_scrolling);
    display_text_scrolling(head, head->scenes->in_game->current_conversation);
}