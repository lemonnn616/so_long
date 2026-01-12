NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -g3

SRCDIR = bonus
INCDIR = include
OBJDIR = build
LIBFT_DIR = libft
MLX42_DIR = MLX42

SRCS = main_bonus.c utils_bonus.c load_textures_bonus.c \
		free_textures_bonus.c read_map_bonus.c render_map_bonus.c \
		move_player_bonus.c key_pressed_bonus.c \
		read_map_bonus_2.c free_textures_bonus_2.c \
		load_textures_bonus_2.c ft_utils.c valid_map.c

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

LIBFT = $(LIBFT_DIR)/libft.a
MLX42 = -L$(MLX42_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm
IFLAGS = -I$(INCDIR) -I$(MLX42_DIR)/include

all: mlx42_build $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(MLX42) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

mlx42_build:
	@echo "Building MLX42 library..."
	cd $(MLX42_DIR) && cmake -B build && cmake --build build -j4 && cd ..

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re mlx42_build

