NAME=minirt

CC= cc

CFLAGS = -Wall -Wextra -Werror -I include -I src/libft

SRC = src/main.c

OBJS = $(SRC:.c=.o)

HEADER= include/minirt.h

MATH = -lm

LIBFT = src/libft/libft.a

all: $(NAME)

$(OBJS): $(HEADER)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(MATH) -o $(NAME)

$(LIBFT): 
	@$(MAKE) -C src/libft
clean:
	@rm -f $(OBJS)
	@$(MAKE) -C src/libft/ clean
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C src/libft/ fclean

re: fclean all

.PHONY: all clean fclean re
