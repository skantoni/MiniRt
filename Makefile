NAME=miniRT

CC= cc

CFLAGS = -Wall -Wextra -Werror -I include -I src/libft -I minilibx-linux

SRC = src/main.c src/windows/create_win.c src/parser/parse_miniRT.c

OBJS = $(SRC:.c=.o)

HEADER= include/minirt.h

LIBXFLAGS = -lX11 -lXext -lm

LIBFT = src/libft/libft.a

MLX = ./minilibx-linux/libmlx_Linux.a

all: $(NAME)

$(OBJS): $(HEADER)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(MLX) $(LIBXFLAGS) -o $(NAME)

$(LIBFT): 
	@$(MAKE) -C src/libft

$(MLX):
	@$(MAKE) -C minilibx-linux
clean:
	@rm -f $(OBJS)
	@$(MAKE) -C src/libft/ clean
	@$(MAKE) -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C src/libft/ fclean

re: fclean all

.PHONY: all clean fclean re
