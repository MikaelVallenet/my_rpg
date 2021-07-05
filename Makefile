##
## EPITECH PROJECT, 2020
## rpg
## File description:
## Makefile
##

SRC_FILES	=	main.c	\
				main_window.c \
				loader/main_loader.c \
				loader/resources_loader.c \
				loader/window_loader.c \
				scenes/global/global_handler.c \
				tools/file_tools.c \
				tools/randomizer.c \
				tools/texts_tools.c \
				tools/button_tools.c	\
				tools/clock_tools.c	\
				unloader/unloader.c \
				game_engine/buttons/clic_hover_button.c	\
				game_engine/buttons/create_button.c	\
				game_engine/buttons/destroy_button.c	\
				game_engine/buttons/display_button.c	\
				game_engine/object/create_object.c	\
				game_engine/object/display_object.c	\
				game_engine/object/destroy_object.c	\
				game_engine/window/window.c	\
				game_engine/music/music.c	\
				game_engine/sound/sound.c	\
				scenes/main_menu/function_button_main_menu.c	\
				scenes/main_menu/function_button_main_menu_2.c	\
				scenes/main_menu/handler_main_menu.c	\
				game_engine/text_scrolling/create_text_scrolling.c \
				game_engine/text_scrolling/destroy_text_scrolling.c \
				game_engine/text_scrolling/handler_text.c \
				game_engine/text_scrolling/update_text.c \
				game_engine/text_scrolling/display_text_scrolling.c \
				game_engine/text_scrolling/methods_text.c \
				game_engine/text_scrolling/methods_text_all.c \
				game_engine/text_scrolling/skip_animation.c \
				game_engine/text/create_text.c	\
				game_engine/text/display_text.c	\
				game_engine/text/destroy_text.c	\
				game_engine/gen_ptcl/create_gen_ptcl.c \
				game_engine/gen_ptcl/handler_gen_ptcl.c \
				game_engine/gen_ptcl/destroy_gen_ptcl.c \
				game_engine/gen_ptcl/methods_gen_ptcl.c \
				game_engine/gen_ptcl/display_gen_ptcl.c \
				game_engine/gen_ptcl/direction_gen_ptcl.c \
				inventory/init_inventory.c \
				inventory/fill_empty_inventory.c \
				inventory/event_inventory.c \
				inventory/display_inventory.c \
				inventory/destroy_inventory.c \
				inventory/update_inventory.c \
				inventory/load_inventory.c \
				items/load_items.c \
				items/display_items_inventory.c \
				items/handle_items_over_effect.c \
				items/drag_and_drop.c \
				items/destroy_item.c \
				items/add_items.c \
				items/init_item_window.c \
				items/event_items.c \
				items/update_item_text.c \
				items/func_equip.c \
				items/func_potions.c \
				items/drag_and_drop_tools.c \
				items/double_click.c \
				scenes/main_menu/init_main_menu.c \
				scenes/setting_menu/function_button_setting.c	\
				scenes/setting_menu/function_button_setting_2.c	\
				scenes/setting_menu/function_button_setting_framerate.c	\
				scenes/setting_menu/handler_setting_menu.c	\
				scenes/setting_menu/init_setting_menu.c	\
				scenes/setting_menu/destroy_setting.c	\
				scenes/pause_menu/function_button_pause.c	\
				scenes/pause_menu/function_button_pause_2.c	\
				scenes/pause_menu/handler_pause_menu.c	\
				scenes/pause_menu/init_pause_menu.c	\
				scenes/load_save_menu/function_button_load_save_menu.c	\
				scenes/load_save_menu/handler_load_save_menu.c	\
				scenes/load_save_menu/init_load_save_menu.c	\
				scenes/load_save_menu/init_text_load_save_menu.c	\
				scenes/load_save_menu/init_text_load_save_menu_aux.c	\
				scenes/load_save_menu/load_save.c	\
				scenes/load_save_menu/update_load_save_menu.c	\
				scenes/in_game/function_button_in_game.c	\
				scenes/in_game/in_game_handler.c	\
				scenes/in_game/init_in_game.c	\
				scenes/in_game/in_game_event.c	\
				scenes/in_game/open_pause.c	\
				scenes/in_game/open_skill_tree.c	\
				scenes/in_game/open_duel.c \
				scenes/in_game/map.c	\
				scenes/select_player/function_button_select_player.c	\
				scenes/select_player/select_player_handler.c	\
				scenes/select_player/init_select_player.c	\
				scenes/select_player/init_select_player_2.c	\
				scenes/global/global_transition.c \
				scenes/global/init_global.c \
				scenes/skill_tree/init_skill_tree.c	\
				scenes/skill_tree/handler_skill_tree.c	\
				scenes/skill_tree/function_button_skill_tree.c	\
				scenes/skill_tree/init_text_skill_tree.c	\
				scenes/skill_tree/init_state_button_skill_tree.c	\
				scenes/skill_tree/display_skill_tree.c	\
				scenes/skill_tree/init_skill_tree_aux.c	\
				scenes/skill_tree/handler_button/manage_button.c	\
				scenes/skill_tree/handler_button/check_button_enable.c	\
				scenes/skill_tree/manage_stat/manage_speed.c	\
				scenes/skill_tree/manage_stat/manage_armor.c	\
				scenes/skill_tree/manage_stat/manage_damage.c	\
				scenes/duel/init_duel.c \
				scenes/duel/handler_duel.c \
				scenes/duel/display_infos.c \
				scenes/quest_menu/init_quest_menu.c	\
				scenes/quest_menu/handler_quest_menu.c	\
				scenes/quest_menu/function_button_quest_menu.c	\
				scenes/quest_menu/init_text_quest_menu.c	\
				scenes/quest_menu/text_quest.c	\
				player/lvl_up.c \
				player/player.c	\
				player/move_player.c	\
				player/init_player.c	\
				player/animated_player.c	\
				player/turn_player.c	\
				player/player_event.c	\
				player/manage_move_animation.c	\
				player/get_preset_player.c	\
				player/init_skill_tree_player.c	\
				player/init_player_aux.c	\
				player/hitbox.c	\
				npc/init_npc.c	\
				npc/animated_npc.c	\
				npc/handler_npc.c	\
				npc/interaction_npc.c	\
				npc/conversation/conversation_event.c	\
				npc/conversation/load_conversation.c	\
				npc/conversation/load_face_conversation.c	\
				npc/conversation/display_conversation.c	\
				npc/conversation/function_npc.c	\
				npc/event_zone.c	\
				npc/destroy_npc.c	\
				npc/turn_npc.c	\
				npc/init_movement.c	\
				npc/manage_patern.c	\
				npc/conversation/function_or_conversation.c	\
				npc/function_npc.c	\
				fights/init_fight.c \
				fights/init_cards.c \
				fights/destroy_fight.c \
				fights/display_fights.c \
				fights/display_cards.c \
				fights/load_monster.c \
				fights/init_attack.c \
				fights/handle_attack.c \
				fights/init_defense.c \
				fights/handle_defense.c \
				fights/move_player_ptcl.c \
				fights/collision.c \
				fights/handle_turn.c \
				fights/init_gen_mobs.c \
				fights/launch_rdm_fight.c \
				unloader/scenes_unloader.c \
				tools/player_data_json/player_data_json.c	\
				tools/player_data_json/init_empty_save_inventory.c	\
				tools/player_data_json/init_empty_skill_tree.c	\
				tools/save_tools.c	\
				tools/parser/checker/parser_tools.c \
				tools/parser/checker/main_parser.c	\
				tools/parser/checker/parser_element.c \
				tools/parser/checker/parser_destroy.c \
				tools/parser/writer/main_writer.c \
				tools/parser/writer/writer_element.c \
				tools/set_volume.c \
				saves/save_stat_player.c	\
				view/set_view.c	\
				tools/parser/writer/writer_tools.c \
				loader/event_loader.c \
				worlds/map/parser_map_tools.c \
				worlds/map/map_event.c \
				worlds/map/pars_map_init_2.c \
				worlds/map/switch_map.c \
				worlds/map/map_event_manager.c \
				worlds/map/pars_map_init.c \
				worlds/map/map_load.c \
				worlds/map/map_unload.c \
				worlds/map/parser_tiles.c	\
				worlds/quests/init_quest.c \
				worlds/quests/init_quest_2.c \
				worlds/quests/main_quest.c \
				worlds/quests/quest_npc.c \
				worlds/quests/save_quest.c \
				worlds/quests/destroy_quest.c \
				worlds/quests/event_quest.c \
				worlds/quests/callback/awards.c \
				fights/handle_turn_2.c \
				worlds/quests/callback/quest_event.c


SRC_DIR	= src/

SRC		=	$(foreach file, $(SRC_FILES), $(addprefix $(SRC_DIR), $(file)))

OBJ		=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS	=	-I./includes/ -L./src/lib/my/ -lmy -g3 -Wall -l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio -lm

all:	$(NAME)
	@echo "Build succesfull!"

$(NAME):  $(OBJ)
	@make -C ./src/lib/my
	@gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	@make -C ./src/lib/my clean
	@rm -f $(OBJ)

fclean:	clean
	@make -C ./src/lib/my fclean
	@rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re