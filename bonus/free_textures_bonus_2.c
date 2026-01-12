/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures_bonus_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:18:38 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/22 11:21:15 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_player_textures(t_game *game)
{
	if (game->player_up)
		mlx_delete_texture(game->player_up);
	if (game->player_down)
		mlx_delete_texture(game->player_down);
	if (game->player_left)
		mlx_delete_texture(game->player_left);
	if (game->player_right)
		mlx_delete_texture(game->player_right);
}

void	free_textures(t_game *game)
{
	free_wall_texture(game);
	free_floor_texture(game);
	free_collectible_texture(game);
	free_player_textures(game);
	free_exit_texture(game);
	free_enemy_texture(game);
}
