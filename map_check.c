/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:09:35 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2024/04/12 17:28:27 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* first check, if the map part contains any other than the allowed character.
 */

void	check_invalid_char(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
			data->map.p_count++;
		else if (line[i] != ' ' && line[i] != '0' && line[i] != '1')
			error_exit(data, ERR_INVALID_MAP);
		i++;
	}
	data->map.height++;
	if (i > data->map.width)
		data->map.width = i;
	if (data->map.p_count > 1)
		print_error_exit(data, "Error\nToo many players");
}

static bool	check_neighbors(char **map, t_intpoint pxy, t_intpoint width_height)
{
	int	dx;
	int	dy;
	int	nx;
	int	ny;

	dx = -2;
	while (++dx < 2)
	{
		dy = -2;
		while (++dy < 2)
		{
			if (0 == dx && 0 == dy)
				continue ;
			nx = pxy.x + dx;
			ny = pxy.y + dy;
			if (nx >= 0 && nx < width_height.y && ny >= 0 \
						&& ny < width_height.x)
			{
				if (map[nx][ny] == '0' || map[nx][ny] == 'N' \
	|| map[nx][ny] == 'S' || map[nx][ny] == 'W' || map[nx][ny] == 'E')
					return (false);
			}
		}
	}
	return (true);
}

static void	set_player_pos(t_data *data, int i, int j, char c)
{
	data->map.player_direction = c;
	data->map.player_x = j;
	data->map.player_y = i;
}

static void	check_player(t_data *data)
{
	if (data->map.p_count != 1)
		print_error_exit(data, "Error\nWrong Player Count\n");
}

void	validate_map(t_data *data)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < data->map.height + 2)
	{
		j = 0;
		while (j < data->map.width + 2)
		{
			c = data->map.map_arr[i][j];
			if (c == 'x')
			{
				if (!check_neighbors(data->map.map_arr, mkintpnt(i, j), \
				mkintpnt(data->map.width + 2, data->map.height + 2)))
					print_error_exit(data, \
						"Error\nMap not surrounded by walls\n");
			}
			else if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
				set_player_pos(data, i, j, c);
			j++;
		}
		i++;
	}
	check_player(data);
}
