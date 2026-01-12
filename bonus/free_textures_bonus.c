/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:06:01 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/22 11:21:13 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_wall_texture(t_game *game)
{
	if (game->wall)
		mlx_delete_texture(game->wall);
}

void	free_floor_texture(t_game *game)
{
	if (game->floor)
		mlx_delete_texture(game->floor);
}

void	free_collectible_texture(t_game *game)
{
	if (game->collectible)
		mlx_delete_texture(game->collectible);
}

void	free_exit_texture(t_game *game)
{
	if (game->exit)
		mlx_delete_texture(game->exit);
}

void	free_enemy_texture(t_game *game)
{
	if (game->enemy)
		mlx_delete_texture(game->enemy);
}
