CC = gcc
INC = .
INCLUDES = push_swap.h
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
SRCS = push_swap.c \
	ps_sort_utils.c \
	ps_sort.c \
	ps_sort_large_utils.c \
	ps_sort_positioner.c \
	ps_utils.c \
	ps_initialize.c \
	ps_validate.c \
	ps_atoi_overflow.c \
	ps_actions_utils.c \
	ps_actions_first.c \
	ps_actions_second.c \
	ps_actions_third.c

OBJS = $(SRCS:%.c=%.o)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -Ilibft

$(NAME): $(OBJS)
	@make -C libft
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) -I$(INC) libft/libft.a

all: $(NAME)

clean:
	@make -C libft clean
	$(RM) $(OBJS)

fclean: clean
	@make -C libft fclean
	$(RM) $(NAME)

re: clean all

norme:
	norminette libft/*.c libft/*.h
	norminette $(SRCS) $(INCLUDES)
