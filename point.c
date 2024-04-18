/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:37:00 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2024/04/12 17:37:01 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_point	mkpnt(double x, double y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

t_intpoint	mkintpnt(int x, int y)
{
	t_intpoint	point;

	point.x = x;
	point.y = y;
	return (point);
}
