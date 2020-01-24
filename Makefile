##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Thomas Meurice <thomas.meurice@epitech.eu>
##


SRC	=	src/infinadd.c     		\
		src/error_management.c	\
		src/neg.c				\
		src/modif_zero.c		\
		src/diy.c

NAME	=	infin_add

OBJ	=	$(SRC:.c=.o)

COMPIL	=	-Llib/my -lmy

CFLAGS	=	-W -Wall -Werror -Wextra -I include/ -g

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		make clean -C lib/my
		gcc -o $(NAME) $(OBJ) $(COMPIL) $(CFLAGS)
		make clean
clean:
		rm -f $(OBJ)
		rm -rf *~ src/*~ vg*

fclean: clean
		make fclean -C lib/my
		rm -f $(NAME)

debug:		CFLAGS += -ggdb3

debug:		re

re:		fclean all

.PHONY:		all debug clean fclean
