##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c		\
		src/print.c		\
		src/button.c		\
		src/event.c		\
		src/input.c		\
		src/load.c		\
		src/map_creation.c	\
		src/move.c		\
		src/render.c		\
		src/square.c		\
		src/vertex.c		\
		src/display.c		\
		src/free.c		\
		src/key.c		\
		src/map_next.c		\
		src/point.c		\
		src/rotate.c		\
		src/tool.c		\
		src/draw.c		\
		src/init.c		\
		src/link.c		\
		src/map.c		\
		src/mouse.c		\
		src/scroll.c		\
		src/vector.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -I ./include -lm

NAME	=	my_world

all:		$(NAME)

$(NAME):	$(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-audio -l csfml-system -l csfml-window

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
