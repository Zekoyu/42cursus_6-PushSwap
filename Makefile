SRCS = 	array_utils.c \
		count_operations.c \
		count_operations_2.c \
		ft_split.c \
		ft_utils.c \
		parsing.c \
		push_one_elt.c \
		push_stacks.c \
		reverse_rotate_stacks.c \
		rotate_stacks.c \
		swap_stacks.c \
		sort_3.c \
		sort_15.c \
		stack_utils.c \
		stack_utils_2.c \
		push_swap.c


OBJS = $(SRCS:.c=.o)

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

all:		$(NAME)

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re bonus