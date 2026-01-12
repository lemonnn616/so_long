/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:33:35 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/25 11:49:13 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	count_collectibles_and_player(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.grid[i][j] == 'C')
				game->map.collectibles++;
			if (game->map.grid[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			j++;
		}
		i++;
	}
}

void	init_map_data(t_game *game, t_map_data map_data)
{
	game->map.grid = map_data.map;
	game->map.width = map_data.width;
	game->map.height = map_data.height;
	game->map.collectibles = 0;
}

void	init_map(t_game *game, char *map_file)
{
	t_map_data	map_data;

	map_data = read_map(map_file);
	validate_map(&map_data);
	init_map_data(game, map_data);
	count_collectibles_and_player(game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	size_t	i;

	if (argc != 2)
		print_error("Usage: ./so_long <map_file>");
	game = (t_game){0};
	init_map(&game, argv[1]);
	game.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "so_long", true);
	if (!game.mlx)
		print_error("Error: Failed to initialize MLX42");
	load_textures(&game);
	game.steps = 0;
	render_map(&game);
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_close_hook(game.mlx, close_window, &game);
	mlx_loop(game.mlx);
	free_textures(&game);
	i = 0;
	while (i < game.map.height)
	{
		free(game.map.grid[i]);
		i++;
	}
	free(game.map.grid);
	return (mlx_terminate(game.mlx), 0);
}
