/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 22:43:02 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2024/04/18 22:08:23 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	do_if_right_pressed(t_data *data)
{
	if (!data)
		return ;
	data->player->angledeg -= data->player->deltaphi;
	draw_picture(data);
}

void	do_if_left_pressed(t_data *data)
{
	if (!data)
		return ;
	data->player->angledeg += data->player->deltaphi;
	draw_picture(data);
}
