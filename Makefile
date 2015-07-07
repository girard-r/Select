##
## Makefile for Makefile in /home/girard_r/Documents/CPE-2013-BSQ
## 
## Made by girard_r
## Login   <girard_r@epitech.net>
## 
## Started on  Tue Dec  3 17:46:05 2013 girard_r
## Last update Sun Jan 19 19:56:30 2014 girard_r
##

CC	=	cc

RM	=	rm -f

NAME	=	my_select

SRCS	=	my_select.c \
		list_functions.c \
		process_keys.c \
		process_keys_2.c \
		display.c \
		process_entry.c \
		main.c \
		left_right.c \
		error.c \
		my_strncmp.c \
		my_putstr.c \
		my_strlen.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	        $(CC) -o $(NAME) $(OBJS) -lncurses

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
