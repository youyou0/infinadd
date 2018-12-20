CC	=	gcc

AR	= 	ar rcs

NAME	= 	infinadd

SRCS	=	$(wildcard *.c)

OBJS	= 	$(SRCS:.c=.o)

CFLAGS	+= 	-Wextra -Wall -Werror -I./include/ -g3

LDFLAGS += 	-L./lib/ -lmy

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		del $(OBJS)

fclean: 	clean
		del $(NAME)

re: 		clean fclean all

.PHONY: 	all
