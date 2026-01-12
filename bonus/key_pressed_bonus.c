/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:20:43 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/25 12:09:42 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_key_press(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.action == MLX_PRESS)
		game->key_pressed[keydata.key] = true;
	else if (keydata.action == MLX_RELEASE)
		game->key_pressed[keydata.key] = false;
}

void	handle_game_over(t_game *game)
{
	if (game->key_pressed[MLX_KEY_ESCAPE])
	{
		ft_printf("Game Over! You quit the game.\n");
		mlx_terminate(game->mlx);
		exit(EXIT_SUCCESS);
	}
}

void	handle_player_move(t_game *game)
{
	if (game->key_pressed[MLX_KEY_W])
		move_player(game, 0, -1);
	if (game->key_pressed[MLX_KEY_S])
		move_player(game, 0, 1);
	if (game->key_pressed[MLX_KEY_A])
		move_player(game, -1, 0);
	if (game->key_pressed[MLX_KEY_D])
		move_player(game, 1, 0);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	handle_key_press(keydata, game);
	handle_game_over(game);
	handle_player_move(game);
}

void	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_printf("Game Over! You quit the game.\n");
	mlx_terminate(game->mlx);
	exit(0);
}
