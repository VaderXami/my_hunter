##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile
##

SRC	=	my_hunter.c		\
		my_hunter2.c		\
		my_hunter3.c		\
		my_hunter4.c		\
		my_hunter5.c		\
		my_hunter6.c		\
		functions.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS	=	-W -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -lc_graph_prog -o  $(NAME)	$(OBJ)

clean:
		rm -f	$(OBJ)

fclean:		clean
		rm *~ -f $(NAME)

re:		fclean all
