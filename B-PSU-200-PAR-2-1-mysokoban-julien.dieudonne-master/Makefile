##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## sokoban
##

SRC	=	src/main.c\
		src/errors.c\
		src/load_file_in_mem.c\
		src/sokoban.c\
		src/get_nbr_of_box.c\
		src/create_struct.c\
		src/move_player.c\
		src/move_box.c\
		src/win_condition.c\
		src/move_left.c\
		src/move_up.c\
		src/move_right.c\
		src/move_down.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lncurses

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)
		rm -f include/*~
		rm -f src/*~
		rm -f *~
		clear

re:		fclean all

debug: CFLAGS += -ggdb
debug: re

.PHONY:		all clean fclean re
