/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:18:16 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2024/04/18 23:53:31 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_tmpx(t_data *data)
{
	int	tmpx;

	if ('S' == data->ray->side)
	{
		tmpx = (data->ray->wall_point.x - \
		(int)data->ray->wall_point.x) * data->texinfo.size;
	}
	if ('N' == data->ray->side)
	{
		tmpx = (-data->ray->wall_point.x - \
		ft_floor(-data->ray->wall_point.x)) * data->texinfo.size;
	}
	if ('W' == data->ray->side)
	{
		tmpx = (data->ray->wall_point.y - \
		(int)data->ray->wall_point.y) * data->texinfo.size;
	}
	if ('E' == data->ray->side)
	{
		tmpx = (-data->ray->wall_point.y - \
		ft_floor(-data->ray->wall_point.y)) * data->texinfo.size;
	}
	return (tmpx);
}

int	get_color_of_pixel(int i, t_intpoint i_min_max, int tmpx, t_data *data)
{
	int	tmpy;
	int	color;

	if (!data)
		return (print_error(-1, "NULL in assign_color_to_pixel"));
	color = 0x0000FF00;
	if (i_min_max.y > i_min_max.x)
		tmpy = (i - i_min_max.x) * data->texinfo.size / \
			(i_min_max.y - i_min_max.x);
	else if (i_min_max.y == i_min_max.x)
	{
		printf("i_min = i_max in assign_color_to_pixel!\n\n");
		tmpy = (i - i_min_max.x) * data->texinfo.size;
	}
	else
		return (print_error(-1, "i_min > i_max in get_color_of_pixel"));
	if ('S' == data->ray->side)
		color = data->textures[NORTH][tmpy * data->texinfo.size + tmpx];
	else if ('N' == data->ray->side)
		color = data->textures[SOUTH][tmpy * data->texinfo.size + tmpx];
	else if ('E' == data->ray->side)
		color = data->textures[WEST][tmpy * data->texinfo.size + tmpx];
	else if ('W' == data->ray->side)
		color = data->textures[EAST][tmpy * data->texinfo.size + tmpx];
	return (color);
}

void	paint_point(int i, int j, int color, t_data *data)
{
	if (!data)
		return ;
	*(int *)(data->img.addr + data->img.size_line * i + \
			data->img.pixel_bits / 8 * j) = color;
}
