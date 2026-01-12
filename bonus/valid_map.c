/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:01:56 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/24 16:06:43 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	validate_map(t_map_data *map)
{
	check_walls(map);
	check_player_and_exit(map);
	check_collectibles(map);
	check_rectangular(map);
}

void	check_walls(t_map_data *map)
{
	size_t	i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			print_error("Error: Map borders must be surrounded by walls");
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			print_error("Error: Map borders must be surrounded by walls");
		i++;
	}
}

void	check_player_and_exit(t_map_data *map)
{
	size_t	i;
	size_t	j;
	size_t	player_count;
	size_t	exit_count;

	i = 0;
	player_count = 0;
	exit_count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
				player_count++;
			else if (map->map[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		print_error("Error: Map must have exactly one player ('P')");
	if (exit_count != 1)
		print_error("Error: Map must have exactly one exit ('E')");
}

void	check_collectibles(t_map_data *map)
{
	size_t	i;
	size_t	j;
	size_t	collectible_count;

	i = 0;
	collectible_count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'C')
				collectible_count++;
			j++;
		}
		i++;
	}
	if (collectible_count == 0)
		print_error("Error: Map must have at least one collectible ('C')");
}

void	check_rectangular(t_map_data *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->map[i]) != map->width)
			print_error("Error: Map is not rectangular");
		i++;
	}
}
