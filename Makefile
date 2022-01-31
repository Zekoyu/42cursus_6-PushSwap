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

CHECKER_SRCS =	checker_srcs/push_stacks.c \
				checker_srcs/reverse_rotate_stacks.c \
				checker_srcs/rotate_stacks.c \
				checker_srcs/swap_stacks.c \
				checker_srcs/checker.c \
				checker_srcs/ft_utils.c \
				ft_utils.c \
				stack_utils_2.c \
				stack_utils.c \
				parsing.c \
				ft_split.c \
				array_utils.c

OBJS = $(SRCS:.c=.o)

CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

NAME = push_swap

CHECKER_NAME = checker

CC = gcc

GNL = ft_gnl/libft_gnl.a

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

$(GNL) :
	@$(MAKE) -C ft_gnl

$(CHECKER_NAME):	$(CHECKER_OBJS) $(GNL)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(GNL) -o $(CHECKER_NAME)

all:		$(NAME)

clean:
	rm -f $(OBJS) $(CHECKER_OBJS)
	@$(MAKE) -C ft_gnl clean

fclean:		clean
	rm -f $(NAME) $(CHECKER_NAME)
	@$(MAKE) -C ft_gnl fclean

re:			fclean all

.PHONY:	all clean fclean re bonus