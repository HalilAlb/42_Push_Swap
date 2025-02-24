CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT = libft/libft.a
LIBFTDIR = libft
PRINTF = libft/ft_printf/libftprintf.a
PRINTFDIR = libft/ft_printf

NAME = push_swap

SRCS = main.c 
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(PRINTF) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFTDIR) -I $(PRINTFDIR) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR) > /dev/null 2>&1
	@$(MAKE) -C $(LIBFTDIR) bonus > /dev/null 2>&1

$(PRINTF):
	make -C $(PRINTFDIR) > /dev/null 2>&1

clean:
	make clean -C $(PRINTFDIR)
	make clean -C $(LIBFTDIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(PRINTFDIR)
	make fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re