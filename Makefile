##
## Makefile for Makefile in /home/tchikl_h/rendu/B2/Infography/gfx_game_of_life
## 
## Made by Hervé TCHIKLADZE
## Login   <tchikl_h@epitech.net>
## 
## Started on  Thu Apr 28 17:07:49 2016 Hervé TCHIKLADZE
## Last update Fri Jul  1 14:03:46 2016 Hervé TCHIKLADZE
##

NAME		=	boxpop

CC		=	gcc -g -O3

RM		=	rm -rf

LIB		=	-L/home/${USER}/.froot/lib/		\
			-llapin     				\
	                -L/usr/local/lib                        \
		        -lsfml-audio                            \
	                -lsfml-graphics                         \
		        -lsfml-window                           \
			-lsfml-system                           \
	                -lstdc++				\
			-ldl					\
		        -lm                                     \


CFLAGS		=	-W				\
			-Wall				\
			-Werror				\
			-Wextra			 	\
			-I				\
			./include/			\

MAIN		=	./src/main/

MYLIB		=	./src/mylib/

DISPLAY		=	./src/display/

GAME		=	./src/game/

SRC		=	$(MAIN)main.c			\
			$(DISPLAY)display.c		\
			$(GAME)game.c			\
			$(GAME)init.c			\
			$(GAME)end.c			\
			$(GAME)fct.c			\
			$(MYLIB)tekpixel.c		\
			$(MYLIB)teksquare.c		\
			$(MYLIB)my_free.c		\

OBJS		=	$(SRC:.c=.o)


all		:	$(OBJS)
			$(CC) -g $(OBJS) -o $(NAME) $(LIB)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all
