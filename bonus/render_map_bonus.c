/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:10:42 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/22 11:06:56 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_tile(t_game *game, size_t x, size_t y)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	if (game->map.grid[y][x] == '1')
		texture = game->wall;
	else if (game->map.grid[y][x] == '0')
		texture = game->floor;
	else if (game->map.grid[y][x] == 'C')
		texture = game->collectible;
	else if (game->map.grid[y][x] == 'E')
		texture = game->exit;
	else if (game->map.grid[y][x] == 'X')
		texture = game->enemy;
	else
		return ;
	image = mlx_texture_to_image(game->mlx, texture);
	if (!image)
		print_error("Error: Failed to create image from texture");
	mlx_image_to_window(game->mlx, image, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_steps(t_game *game)
{
	if (game->steps_image)
		mlx_image_to_window(game->mlx, game->steps_image, 10, 10);
}

void	render_player(t_game *game)
{
	mlx_texture_t	*player_texture;
	mlx_image_t		*player_image;

	player_texture = game->player_down;
	if (game->last_move == 'U')
		player_texture = game->player_up;
	else if (game->last_move == 'D')
		player_texture = game->player_down;
	else if (game->last_move == 'L')
		player_texture = game->player_left;
	else if (game->last_move == 'R')
		player_texture = game->player_right;
	player_image = mlx_texture_to_image(game->mlx, player_texture);
	if (!player_image)
		print_error("Error: Failed to create image from player texture");
	mlx_image_to_window(game->mlx, player_image, game->player_x * TILE_SIZE,
		game->player_y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
	render_steps(game);
	render_player(game);
}
