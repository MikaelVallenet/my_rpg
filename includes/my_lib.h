/*
** EPITECH PROJECT, 2021
** My World
** File description:
** My Lib Header
*/

#ifndef MY_H
#define MY_H

#define RADS(angle) ((angle) * M_PI / 180.0)
#define ABS(value) ((value > 0) ? (value) : (-value))
#define COMPARE(x, y) (((x) > (y)) - ((x) < (y)))
#define SIGN(x) COMPARE(x, 0)

int my_strlen(char *str);
int my_strcmp(char *str1, char *str2);
void my_free(int nb_elements, ...);
void my_putstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_nbr_to_str(int nb);
char *my_strcpy(char *dest, char const *src);
int my_getnbr(char const *str);
char *my_nbr_to_str(int nb);
void my_putnbr(long long arg);
char *my_addchar(char *str, char c, int position);
void my_putchar(char c);
int show_error(char *message);
char *my_strcat_original(char *dest, char *src);
char *my_strncat(char *src1, char *to_add, int index);
char *my_strdup(char const *src);

#endif /* !MY_H */