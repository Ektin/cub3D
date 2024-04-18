/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:40:55 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2024/04/12 17:42:27 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	fabs(double num)
{
	if (num >= 0)
		return (num);
	return (-num);
}

double	distl1(t_point pnt1, t_point pnt2)
{
	return (fabs(pnt1.x - pnt2.x) + fabs(pnt1.y - pnt2.y));
}

// brings the angle to -179 .. 180 range
int	modangle(int angle)
{
	if (-179 <= angle && angle <= 180)
		return (angle);
	if (angle > 180)
		return (modangle(angle - 360));
	if (angle < -179)
		return (modangle(angle + 360));
	return (angle);
}

// brings the angle to -180.0 .. 180.0 range
double	ft_modangle(double angle)
{
	if (-180.0 + EPS < angle && angle < 180.0 + EPS)
		return (angle);
	if (angle >= 180.0 + EPS)
		return (ft_modangle(angle - 360.0));
	if (angle <= -180.0 + EPS)
		return (ft_modangle(angle + 360.0));
	return (angle);
}

double	mypow(double x, int i)
{
	double	res;

	if (i == 0)
		return (1.0);
	if (i > 0)
	{
		res = x;
		while (--i)
			res *= x;
		return (res);
	}
	if (i < 0 && - i > 0 && fabs(x) > EPS)
		return (1.0 / mypow(x, -i));
	return ((double)print_error(-1, "strange input in pow"));
}
