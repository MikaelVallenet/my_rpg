/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-david.gozlan
** File description:
** error_handler
*/

#ifndef ERROR_HANDLER_H_
#define ERROR_HANDLER_H_

// // Error Macro // //

int show_error(char *message);

// Basic errors
#define OPEN_ERROR show_error("Error: Can't open file")
#define ALLOC_ERROR show_error("Error: Allocation problem")
#define READ_ERROR show_error("Error: Can't read file")
#define CREATE_ERROR show_error("Error: Can't create file")

// Args errors
#define UNKNOWN_OPTION_ERROR show_error("Unknown option. Retry with -h.")
#define NB_ARGS_ERROR show_error("Error: Bad number of arguments")

// Sf errors
#define WINDOW_ERROR show_error("Error: Can't create SfRenderWindow object")

#endif /* !ERROR_HANDLER_H_ */
