/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:35:47 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2024/04/12 17:40:33 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// think of 2.99999999999999 and 2.000000000000001 and different angles
// for |angle| < 90, we should get 4.0 and 3.0, respectively,
// for |angle| > 90, we should get 2.0 and 1.0, respectively.
// Also think of 3.0, 2.0.

double	getnextx(double x, t_ray *ray)
{
	if (x < 1)
		print_error(-1, "too small x in getnextx");
	if (fabs(90 - ray->angle) < EPS || fabs(90 + ray->angle) < EPS)
		return (x);
	else if (ray->angle < 90 && ray->angle > -90)
	{
		if (fabs((int)x + 1.0 - x) >= EPS)
			return ((int) x + 1.0);
		else
			return ((int) x + 2.0);
	}
	else if (ray->angle > 90 || ray->angle < -90)
	{
		if (fabs(x - (int)x) >= EPS)
			return ((int)x + 0.0);
		else
			return ((int)x - 1.0);
	}
	return ((double)print_error(-1, "nothing else is possible in getnextx"));
}

double	getnexty(double y, t_ray *ray)
{
	if (y < 1)
		print_error(-1, "too small y in getnexty");
	if (fabs(ray->angle) < EPS || fabs(180 - ray->angle) < EPS || \
					fabs(180 + ray->angle) < EPS)
		return (y);
	else if (ray->angle < 0)
	{
		if (fabs((int)y + 1.0 - y) >= EPS)
			return ((int) y + 1.0);
		else
			return ((int) y + 2.0);
	}
	else if (ray->angle > 0)
	{
		if (fabs(y - (int)y) >= EPS)
			return ((int)y + 0.0);
		else
			return ((int)y - 1.0);
	}
	return ((double)print_error(-1, "nothing else is possible in getnexty"));
}
