##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	my_putstr.c \
		my_strcmp.c \
		my_strlen.c \
		my_free.c \
		my_strcat.c \
		my_nbr_to_str.c \
		my_strcpy.c \
		my_getnbr.c	\
		my_putnbr.c	\
		my_addchar.c	\
		my_putchar.c	\
		show_error.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	@cp "my_lib.h" ../../../includes
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f libmy.a

re:	fclean all