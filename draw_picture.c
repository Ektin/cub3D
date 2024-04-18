/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_picture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:58:58 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2024/04/19 00:00:13 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	reset_image(t_data *data)
{
	if (!data)
		return ;
	ft_memset(data->img.addr, 0, data->img.pixel_bits / 8 * \
		data->win_width * data->win_height);
}

int	draw_picture(t_data *data)
{
	int		j;
	double	angle;

	set_init_point_in_ray(data->ray, mkpnt(data->player->x, data->player->y));
	set_main_angle_in_ray(data->ray, data->player->angledeg);
	reset_image(data);
	j = -1;
	while (++j < data->win_width)
	{
		angle = data->player->angledeg + data->player->halfanglespan \
			- data->player->step_angle_to_draw * j;
		getdistance(angle, data->ray);
		draw_vertline_raycast(j, data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

//i_min .. i_max - 1, i.e. i_min including, i_max excluding
int	draw_vertline_raycast(int j, t_data *data)
{
	double		k;
	t_intpoint	i_min_max;
	int			i;
	int			color;
	int			tmpx;

	k = data->player->viewzoom / data->ray->fish_dist_to_wall;
	i_min_max.x = (int)(data->win_height * (1.0 - k) / 2.0);
	i_min_max.y = (int)(data->win_height * (1.0 + k) / 2.0);
	tmpx = get_tmpx(data);
	color = 0x00FFFF00;
	i = ft_intmax(0, i_min_max.x) - 1;
	while (++i < ft_intmin(data->win_height, i_min_max.y))
	{
		color = get_color_of_pixel(i, i_min_max, tmpx, data);
		paint_point(i, j, color, data);
	}
	i = -1;
	while (++i < ft_intmax(0, i_min_max.x))
		paint_point(i, j, data->texinfo.hex_ceiling, data);
	i = ft_intmin(data->win_height, i_min_max.y) - 1;
	while (++i < data->win_height)
		paint_point(i, j, data->texinfo.hex_floor, data);
	return (0);
}
