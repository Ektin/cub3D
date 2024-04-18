/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 22:51:39 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2024/04/19 00:18:49 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	do_if_w_pressed(t_data *data)
{
	double	dist;

	if (!data)
		return ;
	dist = getdistance(data->player->angledeg + 0.0, data->ray);
	if (dist > data->player->deltal + 1000 * EPS)
	{
		data->player->x += data->player->deltal * data->ray->cosangle;
		data->player->y -= data->player->deltal * data->ray->sinangle;
		draw_picture(data);
	}
	else if (VERBATIM)
		printf("Dist is too small, %f, dist: %f\n", 1000 * EPS, dist);
}

void	do_if_d_pressed(t_data *data)
{
	double	dist;

	if (!data)
		return ;
	dist = getdistance(data->player->angledeg - 90.0, data->ray);
	if (dist > data->player->deltal + 1000 * EPS)
	{
		data->player->x += data->player->deltal * data->ray->cosangle;
		data->player->y -= data->player->deltal * data->ray->sinangle;
		draw_picture(data);
	}
	else if (VERBATIM)
		printf("Dist is too small, %f, dist: %f\n", 1000 * EPS, dist);
}

void	do_if_a_pressed(t_data *data)
{
	double	dist;

	if (!data)
		return ;
	dist = getdistance(data->player->angledeg + 90.0, data->ray);
	if (dist > data->player->deltal + 1000 * EPS)
	{
		data->player->x += data->player->deltal * data->ray->cosangle;
		data->player->y -= data->player->deltal * data->ray->sinangle;
		draw_picture(data);
	}
	else if (VERBATIM)
		printf("Dist is too small, %f, dist: %f\n", 1000 * EPS, dist);
}

void	do_if_s_pressed(t_data *data)
{
	double	dist;

	if (!data)
		return ;
	dist = getdistance(data->player->angledeg + 180.0, data->ray);
	if (dist > data->player->deltal + 1000 * EPS)
	{
		data->player->x += data->player->deltal * data->ray->cosangle;
		data->player->y -= data->player->deltal * data->ray->sinangle;
		draw_picture(data);
	}
	else if (VERBATIM)
		printf("Dist is too small, %f, dist: %f\n", 1000 * EPS, dist);
}

/*void	do_if_p_pressed(t_data *data)
{
	t_img	img;
	int	pixel_bits, size_line, endian;
	char	*ptr;

	img.img = mlx_new_image(data->mlx, 64, 64);
	ptr = mlx_get_data_addr(img.img, &pixel_bits, &size_line, &endian);

	printf("pixel_bits: %d, size_line: %d, endian: %d\n", \
		pixel_bits, size_line, endian);
	for (int i = 0; i < 64; ++i)
	{
		for (int j=0; j < 64; ++j)
		{
			*((int *)ptr + i * size_line/4 + j) = \
				data->textures[0][i * 64 + j];
		}
	}
	for (int i = 0; i < 2* 64 * 256; ++i)
		printf(" %d", data->textures[0][i]);
	mlx_put_image_to_window(data->mlx, data->win, img.img, 0, 0);
}*/
