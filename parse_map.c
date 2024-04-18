/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:46:31 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2024/04/12 16:47:24 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*create_boundary_line(int line_length)
{
	char	*line;

	line = (char *)malloc((line_length + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_memset(line, 'x', line_length);
	line[line_length] = '\0';
	return (line);
}

static char	*create_map_line(t_data *data, int index, int line_length)
{
	int		remaining_len;
	int		j;
	char	*line;

	line = (char *)malloc((line_length + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[0] = 'x';
	ft_strlcpy(line + 1, data->map.map_start[index], line_length - 1);
	remaining_len = line_length - ft_strlen(line);
	ft_memset(line + ft_strlen(line), 'x', remaining_len);
	line[line_length - 1] = 'x';
	line[line_length] = '\0';
	j = -1;
	while (line[++j])
	{
		if (line[j] == ' ')
			line[j] = 'x';
	}
	return (line);
}
// todo

static void	free_map_and_exit(t_data *data, char **map, int i)
{
	while (--i >= 0)
		free(map[i]);
	free(map);
	print_error_exit(data, "Error\nMalloc fail\n");
}

void	create_map(t_data *data)
{
	int		i;
	int		map_width;
	int		map_height;
	char	**map;

	i = -1;
	map_width = data->map.width + 2;
	map_height = data->map.height + 2;
	map = (char **)malloc((map_height + 1) * sizeof(char *));
	if (!map)
		print_error_exit(data, "Error\nMalloc fail\n");
	map[0] = create_boundary_line(map_width);
	while (++i < map_height - 2)
	{
		map[i + 1] = create_map_line(data, i, map_width);
		if (!map[i + 1])
			free_map_and_exit(data, map, i);
	}
	map[map_height - 1] = create_boundary_line(map_width);
	map[map_height] = NULL;
	data->map.map_arr = map;
}
