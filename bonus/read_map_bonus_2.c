/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:18:43 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/24 10:01:25 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	**resize_map(char **map, size_t new_size)
{
	return (realloc(map, sizeof(char *) * (new_size + 1)));
}

static void	handle_line(char *file_content,
		size_t *i, size_t *j, t_map_data *data)
{
	size_t	len;
	char	*line_start;

	line_start = &file_content[*j];
	if (file_content[*i] == '\n')
		len = *i - *j;
	else
		len = *i - *j + 1;
	data->map = resize_map(data->map, data->height);
	data->map[data->height++] = ft_strndup(line_start, len);
	*j = *i + 1;
}

char	**parse_map(char *file_content, t_map_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	data->map = NULL;
	while (file_content[i] != '\0')
	{
		if (file_content[i] == '\n' || file_content[i + 1] == '\0')
			handle_line(file_content, &i, &j, data);
		i++;
	}
	data->map[data->height] = NULL;
	data->width = ft_strlen(data->map[0]);
	return (data->map);
}

t_map_data	read_map(const char *filename)
{
	t_map_data	data;
	char		*file_content;

	data.map = NULL;
	data.width = 0;
	data.height = 0;
	data.player_x = 0;
	data.player_y = 0;
	file_content = read_file(filename);
	data.map = parse_map(file_content, &data);
	free(file_content);
	return (data);
}
