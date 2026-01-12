/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:18:41 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/22 11:22:54 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_player_textures(t_game *game)
{
	game->player_up = mlx_load_png("textures/player_up.png");
	if (!game->player_up)
		print_error("Error: Failed to load player_up texture");
	game->player_down = mlx_load_png("textures/player_down.png");
	if (!game->player_down)
		print_error("Error: Failed to load player_down texture");
	game->player_left = mlx_load_png("textures/player_left.png");
	if (!game->player_left)
		print_error("Error: Failed to load player_left texture");
	game->player_right = mlx_load_png("textures/player_right.png");
	if (!game->player_right)
		print_error("Error: Failed to load player_right texture");
}

void	load_textures(t_game *game)
{
	load_wall_texture(game);
	load_floor_texture(game);
	load_collectible_texture(game);
	load_player_textures(game);
	load_exit_texture(game);
	load_enemy_texture(game);
}
