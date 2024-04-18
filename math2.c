/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:14:33 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2024/04/10 17:21:11 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	mysin(int angle, t_data *data)
{
	angle = modangle(angle);
	if (0 <= angle && angle <= 45)
		return (data->sinarr[angle]);
	if (46 <= angle && angle <= 90)
		return (data->cosarr[90 - angle]);
	if (angle > 90)
		return (mysin(180 - angle, data));
	if (angle < 0)
		return (-mysin(-angle, data));
	return ((double)print_error(-1, "error in mysin: could not happen"));
}

double	mycos(int angle, t_data *data)
{
	angle = modangle(angle);
	if (0 <= angle && angle <= 45)
		return (data->cosarr[angle]);
	if (46 <= angle && angle <= 90)
		return (data->sinarr[90 - angle]);
	if (angle > 90)
		return (-mycos(180 - angle, data));
	if (angle < 0)
		return (mycos(-angle, data));
	return ((double)print_error(-1, "error in mycos: could not happen"));
}

double	ft_sin(double angle, t_data *data)
{
	int		intang;
	double	fractang;
	double	cosang;
	double	sinang;
	double	x;

	intang = (int) angle;
	fractang = angle - intang;
	intang = modangle(intang);
	x = fractang * PI / 180.0;
	sinang = x - mypow(x, 3) / 6.0 + mypow(x, 5) / 120.0 - \
		mypow(x, 7) / 5040.0 + mypow(x, 9) / 362880.0 ;
	cosang = 1 - mypow(x, 2) / 2.0 + mypow(x, 4) / 24.0 - \
		mypow(x, 6) / 720.0 + mypow(x, 8) / 40320.0;
	return (sinang * mycos(intang, data) + \
		cosang * mysin(intang, data));
}

double	ft_cos(double angle, t_data *data)
{
	int		intang;
	double	fractang;
	double	cosang;
	double	sinang;
	double	x;

	intang = (int) angle;
	fractang = angle - intang;
	intang = modangle(intang);
	x = fractang * PI / 180.0;
	sinang = x - mypow(x, 3) / 6.0 + mypow(x, 5) / 120.0 - \
		mypow(x, 7) / 5040.0;
	cosang = 1 - mypow(x, 2) / 2.0 + mypow(x, 4) / 24.0 - \
		mypow(x, 6) / 720.0;
	return (cosang * mycos(intang, data) - \
		sinang * mysin(intang, data));
}
