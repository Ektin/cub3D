/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:27:19 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2024/04/19 00:00:50 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	fill_sin_cos_arr(t_data *data)
{
	int		i;
	int		j;
	double	x;

	if (!data)
		return (print_error(-1, "fill_sin_cos problem"));
	i = -1;
	while (++i <= 6)
	{
		x = PI * i / 180.0;
		data->sinarr[i] = x - mypow(x, 3) / 6.0 + mypow(x, 5) / 120.0 \
				- mypow(x, 7) / 5040.0 + mypow(x, 9) / 362880.0 ;
		data->cosarr[i] = 1.0 - mypow(x, 2) / 2.0 + mypow(x, 4) / 24.0 \
				- mypow(x, 6) / 720.0 + mypow(x, 8) / 40320.0 ;
	}
	--i;
	while (++i <= 45)
	{
		j = i / 2;
		data->sinarr[i] = data->sinarr[j] * data->cosarr[i - j] \
				+ data->cosarr[j] * data->sinarr[i - j];
		data->cosarr[i] = data->cosarr[j] * data->cosarr[i - j] \
				- data->sinarr[j] * data->sinarr[i - j];
	}
	return (0);
}

int	init_player(t_data *data)
{
	if (NULL == data)
		return (print_error(-1, "init_player NULL data"));
	if (NULL != data->player)
		return (print_error(-2, "init_player with non NULL player"));
	data->player = (t_player *)malloc(sizeof(t_player));
	if (!data->player)
		return (print_error(-3, "failed malloc in init_player"));
	data->player->viewzoom = 1;
	data->player->halfanglespan = 30;
	data->player->deltaphi = 3;
	data->player->step_angle_to_draw = 2.0 * \
		data->player->halfanglespan / (data->win_width - 1.0);
	data->player->deltal = 0.1;
	data->player->x = data->map.player_x + 0.5;
	data->player->y = data->map.player_y + 0.5;
	data->player->angledeg = 45;
	if ('N' == data->map.player_direction)
		data->player->angledeg = 90;
	else if ('E' == data->map.player_direction)
		data->player->angledeg = 0;
	else if ('S' == data->map.player_direction)
		data->player->angledeg = -90;
	else if ('W' == data->map.player_direction)
		data->player->angledeg = 180;
	return (0);
}

int	init_ray(t_data *data)
{
	if (NULL == data)
		return (print_error(-1, "init_ray NULL data"));
	if (NULL == data->player)
		return (print_error(-2, "init_ray with NULL player"));
	data->ray = (t_ray *)malloc(sizeof(t_ray));
	if (!data->ray)
		return (print_error(-3, "failed malloc in init_ray"));
	interwine_ray_to_data(data->ray, data);
	set_init_point_in_ray(data->ray, mkpnt(data->player->x, data->player->y));
	set_main_angle_in_ray(data->ray, data->player->angledeg);
	return (0);
}
