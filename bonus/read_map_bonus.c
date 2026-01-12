/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:10:58 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/22 14:19:49 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_read_error(int fd, char **file_content)
{
	close(fd);
	if (!(*file_content) || ft_strlen(*file_content) == 0)
		print_error("Error: Empty or invalid map file");
}

char	*append_buffer(char *file_content, char *buffer,
				size_t total_size, ssize_t bytes_read)
{
	char	*new_content;

	new_content = malloc(total_size + bytes_read + 1);
	if (!new_content)
		print_error("Error: Memory allocation failed");
	if (file_content)
	{
		ft_strcpy(new_content, file_content);
		free(file_content);
	}
	else
		new_content[0] = '\0';
	ft_strcat(new_content, buffer);
	return (new_content);
}

char	*read_file(const char *filename)
{
	int		fd;
	ssize_t	bytes_read;
	char	buffer[1024];
	char	*f;
	size_t	total_size;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("Error: Could not open the map file");
	f = NULL;
	total_size = 0;
	while (1)
	{
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		f = append_buffer(f, buffer, total_size, bytes_read);
		total_size += bytes_read;
	}
	handle_read_error(fd, &f);
	return (f);
}

void	parse_line(char *line, size_t line_num, t_map_data *data)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
		{
			data->player_x = i;
			data->player_y = line_num;
		}
		i++;
	}
}

void	append_line_to_map(char ***map, size_t *lines_count, char *line)
{
	char	**new_map;

	new_map = realloc(*map, sizeof(char *) * (*lines_count + 2));
	if (!new_map)
		print_error("Error: Memory allocation failed");
	*map = new_map;
	(*map)[*lines_count] = ft_strdup(line);
	if (!(*map)[*lines_count])
		print_error("Error: Memory allocation failed");
	(*lines_count)++;
}
