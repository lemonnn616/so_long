/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:15:04 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/22 11:51:49 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_last_move(t_game *game, int dx, int dy)
{
	if (dy == -1)
		game->last_move = 'U';
	else if (dy == 1)
		game->last_move = 'D';
	else if (dx == -1)
		game->last_move = 'L';
	else if (dx == 1)
		game->last_move = 'R';
}

void	move_player_to_new_position(t_game *game, size_t new_x, size_t new_y)
{
	if (game->map.collectibles != 0
		&& game->map.grid[game->player_y][game->player_x] == 'E')
	{
		game->player_x = new_x;
		game->player_y = new_y;
		game->steps++;
	}
	else
	{
		game->map.grid[game->player_y][game->player_x] = '0';
		game->player_x = new_x;
		game->player_y = new_y;
		game->steps++;
	}
}

void	check_win_condition(t_game *game)
{
	if (game->map.collectibles == 0
		&& game->map.grid[game->player_y][game->player_x] == 'E')
	{
		ft_printf("Game Over! You won in %zu steps.\n", game->steps);
		mlx_terminate(game->mlx);
		exit(EXIT_SUCCESS);
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	size_t	new_x;
	size_t	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_x < game->map.width && new_y < game->map.height
		&& !check_collision(game, new_x, new_y))
	{
		update_last_move(game, dx, dy);
		move_player_to_new_position(game, new_x, new_y);
		render_map(game);
		update_steps_display(game);
		check_win_condition(game);
	}
}
