/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:54:57 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/24 10:18:31 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_error(const char *message)
{
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	update_steps_display(t_game *game)
{
	char	steps_text[50];
	char	*steps_str;

	steps_str = ft_itoa(game->steps);
	if (!steps_str)
		print_error("Error: Failed to convert steps to string");
	ft_strlcpy(steps_text, "Steps: ", sizeof(steps_text));
	ft_strlcat(steps_text, steps_str, sizeof(steps_text));
	free(steps_str);
	if (game->steps_image)
		mlx_delete_image(game->mlx, game->steps_image);
	game->steps_image = mlx_new_image(game->mlx, 200, 50);
	if (!game->steps_image)
		print_error("Error: Failed to create image for steps display");
	mlx_put_string(game->mlx, steps_text, 10, 10);
}

bool	check_collision(t_game *game, size_t x, size_t y)
{
	char	cell;

	cell = game->map.grid[y][x];
	if (cell == '1')
		return (true);
	if (cell == 'C')
	{
		game->map.grid[y][x] = '0';
		game->map.collectibles--;
	}
	if (cell == 'X')
	{
		ft_printf("Game Over! You were caught by an enemy.\n");
		mlx_terminate(game->mlx);
		exit(EXIT_FAILURE);
	}
	return (false);
}
