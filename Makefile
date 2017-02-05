##
## Makefile for navy bootstrap in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy_bootstrap
## 
## Made by Antonin Rapini
## Login   <antonin.rapini@epitech.net>
## 
## Started on  Wed Feb  1 18:39:58 2017 Antonin Rapini
## Last update Sat Feb  4 15:44:55 2017 Antonin Rapini
##

CFLAGS	+= -Wall -Werror -Wextra
CFLAGS	+= -I include

SRC	= 	utils/my_show_wordtab.c	\
		utils/get_next_line.c	\
		utils/my_putstr.c	\
		utils/my_getnbr.c	\
		utils/my_putchar.c	\
		utils/my_put_nbr.c	\
		utils/my_abs.c		\
		utils/my_strlen.c	\
		sources/my_create_emptymap.c	\
		sources/my_printpid.c	\
		sources/my_hostgame.c	\
		sources/my_creategame.c	\
		sources/my_fillmap.c	\
		sources/my_joingame.c	\
		sources/my_gameloop.c	\
		sources/my_waitforinput.c	\
		sources/my_play.c	\
		sources/my_showgame.c	\
		sources/my_checkgamestatus.c	\
		navy.c	\

OBJ	= 	$(SRC:.c=.o)

NAME	=	navy

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
