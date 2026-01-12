/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:55:13 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/22 11:22:50 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_wall_texture(t_game *game)
{
	game->wall = mlx_load_png("textures/wall.png");
	if (!game->wall)
		print_error("Error: Failed to load wall texture");
}

void	load_floor_texture(t_game *game)
{
	game->floor = mlx_load_png("textures/floor.png");
	if (!game->floor)
		print_error("Error: Failed to load floor texture");
}

void	load_collectible_texture(t_game *game)
{
	game->collectible = mlx_load_png("textures/collectible.png");
	if (!game->collectible)
		print_error("Error: Failed to load collectible texture");
}

void	load_exit_texture(t_game *game)
{
	game->exit = mlx_load_png("textures/exit.png");
	if (!game->exit)
		print_error("Error: Failed to load exit texture");
}

void	load_enemy_texture(t_game *game)
{
	game->enemy = mlx_load_png("textures/enemy.png");
	if (!game->enemy)
		print_error("Error: Failed to load enemy texture");
}
