/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:30:15 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/25 11:46:27 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

# define TILE_SIZE 128
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef struct s_map
{
	char	**grid;
	size_t	width;
	size_t	height;
	size_t	collectibles;
}	t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		**images;
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*collectible;
	mlx_texture_t	*player_up;
	mlx_texture_t	*player_down;
	mlx_texture_t	*player_left;
	mlx_texture_t	*player_right;
	mlx_texture_t	*exit;
	mlx_texture_t	*enemy;
	t_map			map;
	size_t			player_x;
	size_t			player_y;
	size_t			steps;
	char			last_move;
	mlx_image_t		*steps_image;
	bool			key_pressed[512];
}	t_game;

typedef struct s_map_data
{
	char	**map;
	size_t	width;
	size_t	height;
	size_t	player_x;
	size_t	player_y;
}	t_map_data;

//utils
void		print_error(const char *message);
void		update_steps_display(t_game *game);
bool		check_collision(t_game *game, size_t x, size_t y);

// load_textures
void		load_wall_texture(t_game *game);
void		load_floor_texture(t_game *game);
void		load_collectible_texture(t_game *game);
void		load_exit_texture(t_game *game);
void		load_enemy_texture(t_game *game);

//load textures 2
void		load_player_textures(t_game *game);
void		load_textures(t_game *game);

// free textures
void		free_wall_texture(t_game *game);
void		free_floor_texture(t_game *game);
void		free_collectible_texture(t_game *game);
void		free_exit_texture(t_game *game);
void		free_enemy_texture(t_game *game);

// free textures 2
void		free_player_textures(t_game *game);
void		free_textures(t_game *game);

// read map
char		*read_file(const char *filename);
void		parse_line(char *line, size_t line_num, t_map_data *data);
void		append_line_to_map(char ***map, size_t *lines_count, char *line);
void		handle_read_error(int fd, char **file_content);
char		*append_buffer(char *file_content, char *buffer,
				size_t total_size, ssize_t bytes_read);

// read map 2
char		**parse_map(char *file_content, t_map_data *data);
// t map
t_map_data	read_map(const char *filename);

// render map
void		draw_tile(t_game *game, size_t x, size_t y);
void		render_steps(t_game *game);
void		render_player(t_game *game);
void		render_map(t_game *game);

// move player
void		update_last_move(t_game *game, int dx, int dy);
void		move_player_to_new_position(t_game *game,
				size_t new_x, size_t new_y);
void		check_win_condition(t_game *game);
void		move_player(t_game *game, int dx, int dy);

// key pressed
void		handle_key_press(mlx_key_data_t keydata, t_game *game);
void		handle_game_over(t_game *game);
void		handle_player_move(t_game *game);
void		key_hook(mlx_key_data_t keydata, void *param);
void		close_window(void *param);

//main
void		init_map(t_game *game, char *map_file);
void		init_map_data(t_game *game, t_map_data map_data);
void		count_collectibles_and_player(t_game *game);

//ft_utils
char		*ft_strcpy(char *s1, char *s2);
char		*ft_strcat(char *dest, char *src);
char		*ft_strndup(const char *s, size_t n);
//valid map
void		validate_map(t_map_data *map);
void		check_walls(t_map_data *map);
void		check_player_and_exit(t_map_data *map);
void		check_collectibles(t_map_data *map);
void		check_rectangular(t_map_data *map);

#endif
