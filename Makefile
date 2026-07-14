NAME=miniRT

CC= cc

CFLAGS = -Wall -Wextra -Werror -I includes -I src/libft -I ./includes/minilibx-linux -g

SRC = src/main.c src/clean.c src/windows/create_win.c src/parser/parse_minirt.c\
      src/parser/parse_minirt_utils.c src/parser/print_error.c\
	  src/get_next_line/get_next_line_utils.c src/get_next_line/get_next_line.c\
	  src/parser/parse_ambient.c src/init.c src/parser/parse_camera.c src/str_array.c\
	  src/parser/parse_light.c src/parser/parse_sphere.c src/parser/parse_vector.c

OBJS = $(SRC:.c=.o)

HEADER= includes/minirt.h

LIBXFLAGS = -lX11 -lXext -lm

LIBFT = src/libft/libft.a

MLX = ./includes/minilibx-linux/libmlx_Linux.a

all: $(NAME)

$(OBJS): $(HEADER)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(MLX) $(LIBXFLAGS) -o $(NAME)

$(LIBFT): 
	@$(MAKE) -C src/libft

$(MLX):
	@$(MAKE) -C ./includes/minilibx-linux
clean:
	@rm -f $(OBJS)
	@$(MAKE) -C src/libft/ clean
	@$(MAKE) -C ./includes/minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C src/libft/ fclean

re: fclean all

.PHONY: all clean fclean re
